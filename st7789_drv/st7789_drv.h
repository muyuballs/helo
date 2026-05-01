#ifndef __ST7789_H__
#define __ST7789_H__

#include "stdint.h"
#include "pico/stdio.h"
#include "pico/stdlib.h"
#include "hardware/pio.h"

typedef void (*job_done_cb)();

void st7789_drv_setup(PIO pio, uint sm,
                      uint8_t dc, uint8_t cs, uint8_t clk, uint8_t mosi,
                      uint8_t bl, uint8_t rst, float clk_div, job_done_cb callback);
void st7789_put_pixels_for_window(uint16_t x, uint16_t y, uint16_t x1, uint16_t y1, uint8_t *data);

#endif