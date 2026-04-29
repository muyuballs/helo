/**
 * Copyright (c) 2020 Raspberry Pi (Trading) Ltd.
 *
 * SPDX-License-Identifier: BSD-3-Clause
 */
#include <stdio.h>
#include "pico/stdio.h"
#include "pico/stdlib.h"
#include "lvgl.h"
#include "pico/time.h"
#include "hardware/spi.h"
#include "hardware/adc.h"
#include "hw_define.h"
#include "st7789_drv/st7789_drv.h"
#include "ui_helo.h"

#ifndef LED_DELAY_MS
#define LED_DELAY_MS 250
#endif

#define TFT_SELECT   // gpio_put(TFT_CS, 0)
#define TFT_UNSELECT // gpio_put(TFT_CS, 1)
#define TFT_CMD gpio_put(TFT_DC, 0)
#define TFT_DATA gpio_put(TFT_DC, 1)

uint8_t lv_buffer[LV_BUF_SIZE] __attribute__((aligned(4)));

static st7789_drv_t *disp_drv;

static struct repeating_timer lvgl_tick_timer;

static volatile bool has_keypad_event = false;
static lv_indev_t *keypad;

static inline uint64_t millis_since_boot()
{
    return to_ms_since_boot(get_absolute_time());
}

static bool lvgl_tick_callback(struct repeating_timer *t)
{
    lv_tick_inc(1); // 通知过去了1ms
    return true;    // 继续重复
}

float get_vsys_voltage(void)
{
    adc_select_input(3); // ADC3 = VSYS
    uint16_t raw = adc_read();

    // 官方公式：3 = 1/3分压  x 3.3V参考
    return (raw * 3.3f * 2) / 4096.0f; // 正确公式！无三倍！
}

// Perform initialisation
int pico_led_init(void)
{
#if defined(PICO_DEFAULT_LED_PIN)
    // A device like Pico that uses a GPIO for the LED will define PICO_DEFAULT_LED_PIN
    // so we can use normal GPIO functionality to turn the led on and off
    gpio_init(PICO_DEFAULT_LED_PIN);
    gpio_set_dir(PICO_DEFAULT_LED_PIN, GPIO_OUT);
    return PICO_OK;
#endif
}

// Turn the led on or off
void pico_set_led(bool led_on)
{
#if defined(PICO_DEFAULT_LED_PIN)
    // Just set the GPIO on or off
    gpio_put(PICO_DEFAULT_LED_PIN, led_on);
#endif
}

void setup_st7789_disp()
{
    printf("init setup_st7789_disp\n");
    st7789_drv_setup(&disp_drv, pio0, 0,
                     TFT_DC, TFT_CS, TFT_SCK, TFT_MOSI,
                     TFT_BL, TFT_RST, NULL);
}

void st7789_flush_impl(lv_display_t *disp, const lv_area_t *area, uint8_t *px_map)
{
    st7789_put_pixels_for_window(disp_drv, (uint8_t)area->x1, (uint8_t)area->x2, (uint8_t)area->y1, (uint8_t)area->y2, px_map);
    lv_display_flush_ready(disp);
}

void keypan_irq_handler()
{
    has_keypad_event = true;
}

void setup_keypad()
{
    uint keys[5] = {KEY_U, KEY_D, KEY_L, KEY_R, KEY_M};
    for (int i = 0; i < 5; i++)
    {
        gpio_init(keys[i]);
        gpio_set_dir(keys[i], false);
        gpio_set_pulls(keys[i], true, false);
        gpio_set_irq_enabled_with_callback(keys[i], GPIO_IRQ_EDGE_FALL, true, keypan_irq_handler);
    }
}

void keypad_read_impl(lv_indev_t *indev, lv_indev_data_t *data)
{
    data->state = LV_INDEV_STATE_PRESSED;
    if (gpio_get(KEY_M) == 0)
    {
        data->key = LV_KEY_ENTER;
    }
    else if (gpio_get(KEY_U) == 0)
    {
        data->key = LV_KEY_ESC;
    }
    else if (gpio_get(KEY_D) == 0)
    {
        data->key = LV_KEY_HOME;
    }
    else
    {
        data->state = LV_INDEV_STATE_RELEASED;
        if (gpio_get(KEY_L) == 0)
        {
            data->enc_diff = -1;
        }
        else if (gpio_get(KEY_R) == 0)
        {
            data->enc_diff = 1;
        }
        else
        {
            data->enc_diff = 0;
        }
    }
}

void setup_lvgl()
{
    printf("lv init\n");
    lv_init();
    if (!add_repeating_timer_ms(1, lvgl_tick_callback, NULL, &lvgl_tick_timer))
    {
        printf("start lv tick timer faild\n");
    }
    printf("lv_disp_create\n");
    lv_display_t *disp = lv_display_create(SCR_W, SCR_H);
    lv_display_set_flush_cb(disp, st7789_flush_impl);
    printf("lv_display_set_buffers\n");
    lv_display_set_buffers(disp, lv_buffer, NULL, LV_BUF_SIZE, LV_DISPLAY_RENDER_MODE_PARTIAL);

    keypad = lv_indev_create();
    lv_indev_set_mode(keypad, LV_INDEV_MODE_EVENT);
    lv_indev_set_type(keypad, LV_INDEV_TYPE_ENCODER);
    lv_indev_set_read_cb(keypad, keypad_read_impl);
    lv_indev_set_display(keypad, disp);

    lv_group_t *group = lv_group_create();
    lv_group_set_default(group);
    lv_indev_set_group(keypad, group);

    printf("ui_hello_world_init\n");
    ui_helo_init("");
    printf("lv_screen_load\n");
    lv_obj_t *scr = stepper_ctrl_screen_create();
    lv_screen_load(scr);
    printf("setup lvgl done\n");
}

uint32_t tick = 0;
uint64_t millis = 0;

int main()
{
    stdio_init_all();
    for (int i = 0; i < 5; i++)
    {
        printf("wait serial connect: %d\n", i);
        sleep_ms(1000);
    }
    adc_init();
    adc_gpio_init(29);

    printf("led init\n");
    int rc = pico_led_init();
    hard_assert(rc == PICO_OK);
    setup_st7789_disp();
    setup_keypad();
    printf("setup lvgl\n");
    setup_lvgl();
    printf("start blink\n");
    bool led_status = false;
    millis = millis_since_boot();
    while (true)
    {
        tick++;
        uint64_t lmillis = millis_since_boot();
        if (lmillis - millis >= 1000)
        {
            lv_subject_set_float(&rpm, tick * 1000.0 / (lmillis - millis));
            millis = lmillis;
            tick = 0;
        }
        lv_subject_set_float(&vol, get_vsys_voltage());

        led_status = !led_status;
        pico_set_led(led_status);
        uint32_t delay = lv_timer_handler();
        if (has_keypad_event)
        {
            has_keypad_event = false;
            lv_indev_read(keypad);
            continue;
        }
        // printf("delay = %ld ms\n", delay);
        if (delay == LV_NO_TIMER_READY)
        {
            sleep_ms(LV_DEF_REFR_PERIOD);
        }
        else
        {
            sleep_ms(delay);
        }
    }
}

void on_screen_loaded(lv_event_t *e)
{
    lv_obj_t *target = lv_event_get_current_target_obj(e);
    printf("on_screen_loaded :%s\n", lv_obj_get_name(target));
    lv_group_t *group = lv_group_get_default();
    lv_group_remove_all_objs(group);
    // lv_obj_t* screen = lv_obj_get_child_by_name(lv_screen_active(),"stepper_ctrl_screen_#");
    if (lv_strcmp("settings_screen_#", lv_obj_get_name(target)) == 0)
    {
        lv_obj_t *menu = lv_obj_find_by_name(target, "menu");
        lv_group_add_obj(group, menu);
        lv_gridnav_add(menu, LV_GRIDNAV_CTRL_ROLLOVER);
    }
    else
    {
        lv_group_add_obj(group, lv_screen_active());
        lv_gridnav_add(lv_screen_active(), LV_GRIDNAV_CTRL_ROLLOVER);
    }
}

void on_stepper_ctrl_keyevent(lv_event_t *e)
{
    lv_event_code_t code = lv_event_get_code(e);
    printf("event code:%d ", code);
    if (code == LV_EVENT_KEY)
    {
        uint32_t key = lv_event_get_key(e);
        printf("key: %d", key);
        lv_obj_t *settings_screen = settings_screen_create();
        lv_screen_load_anim(settings_screen, LV_SCREEN_LOAD_ANIM_MOVE_LEFT, 500, 0, true);
    }
    printf("\n");
}

void on_menu_item_focus_changed(lv_event_t *e)
{
    lv_obj_t *target = lv_event_get_target_obj(e);
    lv_obj_t *prefix = lv_obj_find_by_name(target, "prefix");
    if (prefix)
    {
        lv_obj_set_style_opa(prefix, 255, LV_PART_MAIN);
    }
    lv_obj_t *fobj = lv_group_get_focused(lv_group_get_default());
    printf("on_menu_item_focus_changed :%s %p --- %d\n", lv_obj_get_name(target), fobj, target == fobj);
}

void on_menu_screen_keyevent(lv_event_t *e)
{
    lv_event_code_t code = lv_event_get_code(e);
    printf("event code:%d ", code);
    if (code == LV_EVENT_KEY)
    {
        uint32_t key = lv_event_get_key(e);
        printf("key: %d", key);
        if (key == LV_KEY_ESC)
        {
            lv_obj_t *stepper_ctrl_screen = stepper_ctrl_screen_create();
            lv_screen_load_anim(stepper_ctrl_screen, LV_SCREEN_LOAD_ANIM_MOVE_RIGHT, 500, 0, true);
        }
    }
    printf("\n");
}

void on_menu_item_clicked(lv_event_t *e)
{
    void *which = lv_event_get_user_data(e);
    printf("on_menu_item_clicked:%s\n", which);
}