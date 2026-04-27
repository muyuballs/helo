
#include "st7789_drv.h"
#include "st7789_drv.pio.h"
#include <stdlib.h>
#include <string.h>

#define SERIAL_CLK_DIV 1.f

#ifndef M_PI
#define M_PI 3.14159265358979323846
#endif

#define SCREEN_WIDTH 240
#define SCREEN_HEIGHT 240

struct _st7789_drv
{
    uint8_t dc;
    uint8_t cs;
    uint8_t mosi;
    uint8_t clk;
    uint8_t bl;
    uint8_t rst;
    PIO pio;
    uint sm;
    uint8_t *buf;
    size_t remain;
    bool busy;
    job_done_cb callback;
    /* data */
};
// Format: cmd length (including cmd byte), post delay in units of 5 ms, then cmd payload
// Note the delays have been shortened a little
static const uint8_t st7789_init_seq[] = {
    1, 20, 0x01,                                                      // Software reset
    1, 10, 0x11,                                                      // Exit sleep mode
    2, 2, 0x3a, 0B01100101,                                           // 16bit 262k//0x55,                                    // Set colour mode to 16 bit
    2, 0, 0x36, 0x00,                                                 // Set MADCTL: row then column, refresh is bottom to top ????
    5, 0, 0x2a, 0x00, 0x00, SCREEN_WIDTH >> 8, SCREEN_WIDTH & 0xff,   // CASET: column addresses
    5, 0, 0x2b, 0x00, 0x00, SCREEN_HEIGHT >> 8, SCREEN_HEIGHT & 0xff, // RASET: row addresses
    1, 2, 0x21,                                                       // Inversion on, then 10 ms delay (supposedly a hack?)
    1, 2, 0x13,                                                       // Normal display on, then 10 ms delay
    1, 2, 0x29,                                                       // Main screen turn on, then wait 500 ms
    0                                                                 // Terminate list
};

static inline void lcd_set_dc_cs(st7789_drv_t *drv, bool dc, bool cs)
{
    sleep_us(1);
    gpio_put_masked((1u << drv->dc) | (1u << drv->cs), !!dc << drv->dc | !!cs << drv->cs);
    sleep_us(1);
}

static inline void lcd_write_cmd(st7789_drv_t *drv, const uint8_t *cmd, size_t count)
{
    st7789_drv_wait_idle(drv->pio, drv->sm);
    lcd_set_dc_cs(drv, 0, 0);
    st7789_drv_put(drv->pio, drv->sm, *cmd++);
    if (count >= 2)
    {
        st7789_drv_wait_idle(drv->pio, drv->sm);
        lcd_set_dc_cs(drv, 1, 0);
        for (size_t i = 0; i < count - 1; ++i)
            st7789_drv_put(drv->pio, drv->sm, *cmd++);
    }
    st7789_drv_wait_idle(drv->pio, drv->sm);
    lcd_set_dc_cs(drv, 1, 1);
}

static inline void lcd_init(st7789_drv_t *drv, const uint8_t *init_seq)
{
    const uint8_t *cmd = init_seq;
    while (*cmd)
    {
        lcd_write_cmd(drv, cmd + 2, *cmd);
        sleep_ms(*(cmd + 1) * 5);
        cmd += *cmd + 2;
    }
}

static inline void _write_pixels(st7789_drv_t *drv, uint8_t *data, size_t count)
{
    uint8_t cmd = 0x2c; // RAMWR
    lcd_write_cmd(drv, &cmd, 1);
    lcd_set_dc_cs(drv, 1, 0);
    for (size_t i = 0; i < count; i++)
    {
        st7789_drv_put(drv->pio, drv->sm, data[i]);
    }
}

void pio_irq_handler(void) {
    // 清除中断
    pio_interrupt_clear(pio0, 0);
}

bool st7789_put_pixels(st7789_drv_t *drv, uint8_t *data, size_t count)
{
    // if (drv->busy)
    // {
    //     return false;
    // }
    // drv->busy = true;
    _write_pixels(drv, data, count);
}

bool st7789_put_pixels_for_window(st7789_drv_t *drv, uint8_t x, uint8_t x1, uint8_t y, uint8_t y1, uint8_t *data)
{
    // if (drv->busy)
    // {
    //     return false;
    // }
    // drv->busy = true;
    // 0x2A CASET — 列地址（X）设置
    // 0x2B RASET — 行地址（Y）设置
    uint8_t caset[5] = {0x2A, x >> 8, x & 0xFF, x1 >> 8, x1 & 0xFF};
    uint8_t raset[5] = {0x2B, y >> 8, y & 0xFF, y1 >> 8, y1 & 0xFF};
    lcd_write_cmd(drv, caset, 5);
    lcd_write_cmd(drv, raset, 5);
    _write_pixels(drv, data, (x1 - x + 1) * (y1 - y + 1) * 2);
}

bool st7789_drv_is_busy(st7789_drv_t *drv)
{
    return drv->busy;
}

void st7789_drv_setup(st7789_drv_t **drv, PIO pio, uint sm,
                      uint8_t dc, uint8_t cs, uint8_t clk, uint8_t mosi,
                      uint8_t bl, uint8_t rst, job_done_cb callback)
{

    *drv = malloc(sizeof(struct _st7789_drv));
    (*drv)->callback = callback;
    (*drv)->bl = bl;
    (*drv)->rst = rst;
    (*drv)->dc = dc;
    (*drv)->cs = cs;
    (*drv)->clk = clk;
    (*drv)->mosi = mosi;
    (*drv)->pio = pio;
    (*drv)->sm = sm;

    uint offset = pio_add_program(pio, &st7789_drv_program);
    st7789_drv_program_init(pio, sm, offset, (*drv)->mosi, (*drv)->clk, SERIAL_CLK_DIV);

    gpio_init((*drv)->cs);
    gpio_init((*drv)->dc);
    gpio_init((*drv)->rst);
    gpio_init((*drv)->bl);
    gpio_set_dir((*drv)->cs, GPIO_OUT);
    gpio_set_dir((*drv)->dc, GPIO_OUT);
    gpio_set_dir((*drv)->rst, GPIO_OUT);
    gpio_set_dir((*drv)->bl, GPIO_OUT);

    gpio_put((*drv)->cs, 1);
    gpio_put((*drv)->rst, 1);
    lcd_init((*drv), st7789_init_seq);
    // uint8_t *buf = malloc(240*2*5);
    // for (int i = 0; i < 240*5; i+=2)
    // {
    //     buf[i] = 0b00000111;
    //     buf[i+1]=0b11100000;
    // }
    //  uint8_t cmds[5] = { 0x2A, 0, 40, 0, 50};
    // lcd_write_cmd(*drv, cmds, 5);
    // uint8_t cmds2[5] = { 0x2b, 0, 40, 0, 50};
    // lcd_write_cmd(*drv, cmds2, 5);
    // // st7789_put_pixels_for_window(*drv,10,20,10,20,(uint8_t *)buf);
    // st7789_put_pixels(*drv, buf, 240*2*5);
    // free(buf);
    (*drv)->busy = false;
    gpio_put((*drv)->bl, 1);
}
