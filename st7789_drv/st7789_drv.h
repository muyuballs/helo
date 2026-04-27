#ifndef __ST7789_H__
#define __ST7789_H__

#include "pico/stdio.h"
#include "pico/stdlib.h"
#include "hardware/pio.h"

typedef void(*job_done_cb)();
typedef struct _st7789_drv st7789_drv_t;
void st7789_drv_setup(st7789_drv_t **drv, PIO pio, uint sm,
                      uint8_t dc, uint8_t cs, uint8_t clk, uint8_t mosi,
                      uint8_t bl, uint8_t rst,job_done_cb callback);
bool st7789_drv_is_busy(st7789_drv_t *drv);
bool st7789_put_pixels(st7789_drv_t *drv, uint8_t *data, size_t count);
bool st7789_put_pixels_for_window(st7789_drv_t *drv, uint8_t x, uint8_t x1, uint8_t y, uint8_t y1, uint8_t *data);

#endif