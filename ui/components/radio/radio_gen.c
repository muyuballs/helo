/**
 * @file radio_gen.c
 * @brief Template source file for LVGL objects
 */

/*********************
 *      INCLUDES
 *********************/

#include "radio_gen.h"
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

lv_obj_t * radio_create(lv_obj_t * parent, const char * label)
{
    LV_TRACE_OBJ_CREATE("begin");

    static lv_style_t radio_base;
    static lv_style_t radio_focused;
    static lv_style_t radio_checked;
    static lv_style_t radio_label;

    static bool style_inited = false;

    if (!style_inited) {
        lv_style_init(&radio_base);
        lv_style_set_text_color(&radio_base, lv_color_hex(0xE0E0E0));
        lv_style_set_border_opa(&radio_base, 255);
        lv_style_set_bg_opa(&radio_base, 70);
        lv_style_set_border_width(&radio_base, 2);
        lv_style_set_bg_color(&radio_base, lv_color_hex(0x6688ee));
        lv_style_set_radius(&radio_base, 255);

        lv_style_init(&radio_focused);
        lv_style_set_text_color(&radio_focused, lv_color_hex(0xFFFFFF));
        lv_style_set_shadow_width(&radio_focused, 10);
        lv_style_set_border_opa(&radio_focused, 255);
        lv_style_set_border_color(&radio_focused, lv_color_hex(0x00D1FF));

        lv_style_init(&radio_checked);
        lv_style_set_text_color(&radio_checked, lv_color_hex(0x1A1C22));
        lv_style_set_bg_opa(&radio_checked, 255);
        lv_style_set_bg_grad_color(&radio_checked, lv_color_hex(0xE0E0E0));

        lv_style_init(&radio_label);
        lv_style_set_align(&radio_label, LV_ALIGN_CENTER);
        lv_style_set_text_font(&radio_label, misan_16);

        style_inited = true;
    }

    lv_obj_t * lv_obj_0 = lv_obj_create(parent);
    lv_obj_set_name_static(lv_obj_0, "radio_#");
    lv_obj_set_state(lv_obj_0, LV_STATE_FOCUSED, false);
    lv_obj_set_state(lv_obj_0, LV_STATE_CHECKED, false);
    lv_obj_set_flag(lv_obj_0, LV_OBJ_FLAG_CLICKABLE, true);
    lv_obj_set_flag(lv_obj_0, LV_OBJ_FLAG_CLICK_FOCUSABLE, true);
    lv_obj_set_flag(lv_obj_0, LV_OBJ_FLAG_CHECKABLE, true);

    lv_obj_remove_style(lv_obj_0, NULL, 0);
    lv_obj_add_style(lv_obj_0, &radio_base, 0);
    lv_obj_add_style(lv_obj_0, &radio_checked, LV_STATE_CHECKED);
    lv_obj_add_style(lv_obj_0, &radio_focused, LV_STATE_FOCUSED);
    lv_obj_t * lv_label_0 = lv_label_create(lv_obj_0);
    lv_label_set_text(lv_label_0, label);
    lv_obj_add_style(lv_label_0, &radio_label, 0);

    LV_TRACE_OBJ_CREATE("finished");

    return lv_obj_0;
}

/**********************
 *   STATIC FUNCTIONS
 **********************/

