/**
 * @file stepper_driver_config_screen_gen.c
 * @brief Template source file for LVGL objects
 */

/*********************
 *      INCLUDES
 *********************/

#include "stepper_driver_config_screen_gen.h"
#include "../../ui_helo.h"

/*********************
 *      DEFINES
 *********************/

/**********************
 *      TYPEDEFS
 **********************/

/***********************
 *  STATIC VARIABLES
 **********************/

/***********************
 *  STATIC PROTOTYPES
 **********************/

/**********************
 *   GLOBAL FUNCTIONS
 **********************/

lv_obj_t * stepper_driver_config_screen_create(void)
{
    LV_TRACE_OBJ_CREATE("begin");

    static lv_style_t content;
    static lv_style_t sub_title;

    static bool style_inited = false;

    if (!style_inited) {
        lv_style_init(&content);
        lv_style_set_pad_all(&content, 8);
        lv_style_set_pad_row(&content, 8);
        lv_style_set_flex_track_place(&content, LV_FLEX_ALIGN_START);
        lv_style_set_width(&content, lv_pct(100));
        lv_style_set_flex_grow(&content, 1);

        lv_style_init(&sub_title);
        lv_style_set_text_font(&sub_title, misan_16);
        lv_style_set_text_color(&sub_title, DARKGREY);

        style_inited = true;
    }

    lv_obj_t * column_0 = column_create(NULL);
    lv_obj_set_name_static(column_0, "stepper_driver_config_screen_#");
    lv_obj_set_flag(column_0, LV_OBJ_FLAG_SCROLLABLE, false);

    lv_obj_add_style(column_0, &screen_base, 0);
    lv_obj_add_event_cb(column_0, on_screen_loaded, LV_EVENT_SCREEN_LOADED, NULL);
    lv_obj_add_event_cb(column_0, on_stepper_driver_config_keyevent, LV_EVENT_KEY, NULL);
    toolbar_create(column_0, "步进驱动配置", 32);
    
    lv_obj_t * column_1 = column_create(column_0);
    lv_obj_set_flag(column_1, LV_OBJ_FLAG_EVENT_BUBBLE, true);
    lv_obj_set_flag(column_1, LV_OBJ_FLAG_SCROLLABLE, true);
    lv_obj_set_scrollbar_mode(column_1, LV_SCROLLBAR_MODE_OFF);
    lv_obj_add_style(column_1, &content, 0);
    lv_obj_t * lv_label_0 = lv_label_create(column_1);
    lv_label_set_text(lv_label_0, "驱动类型");
    lv_obj_add_style(lv_label_0, &sub_title, 0);
    
    lv_obj_t * lv_label_1 = lv_label_create(column_1);
    lv_label_set_text(lv_label_1, "细分设置");
    lv_obj_add_style(lv_label_1, &sub_title, 0);
    
    lv_obj_t * lv_label_2 = lv_label_create(column_1);
    lv_label_set_text(lv_label_2, "旋转方向");
    lv_obj_add_style(lv_label_2, &sub_title, 0);

    LV_TRACE_OBJ_CREATE("finished");

    return column_0;
}

/**********************
 *   STATIC FUNCTIONS
 **********************/

