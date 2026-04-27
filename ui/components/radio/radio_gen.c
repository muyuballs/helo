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

    static lv_style_t style_base;
    static lv_style_t focused;
    static lv_style_t checked;
    static lv_style_t disabled;

    static bool style_inited = false;

    if (!style_inited) {
        lv_style_init(&style_base);
        lv_style_set_bg_opa(&style_base, 255);
        lv_style_set_border_width(&style_base, 0);
        lv_style_set_radius(&style_base, 255);
        lv_style_set_bg_color(&style_base, GREY);

        lv_style_init(&focused);
        lv_style_set_border_width(&focused, 1);
        lv_style_set_border_color(&focused, RED);

        lv_style_init(&checked);
        lv_style_set_text_color(&checked, WHITE);
        lv_style_set_bg_color(&checked, ACTIVE);

        lv_style_init(&disabled);
        lv_style_set_opa(&disabled, 100);

        style_inited = true;
    }

    lv_obj_t * lv_obj_0 = lv_obj_create(parent);
    lv_obj_set_name_static(lv_obj_0, "radio_#");
    lv_obj_set_flag(lv_obj_0, LV_OBJ_FLAG_CHECKABLE, true);
    lv_obj_set_flag(lv_obj_0, LV_OBJ_FLAG_CLICK_FOCUSABLE, true);

    lv_obj_remove_style(lv_obj_0, NULL, 0);
    lv_obj_add_style(lv_obj_0, &style_base, 0);
    lv_obj_add_style(lv_obj_0, &checked, LV_STATE_CHECKED);
    lv_obj_add_style(lv_obj_0, &focused, LV_STATE_FOCUSED);
    lv_obj_add_style(lv_obj_0, &disabled, LV_STATE_DISABLED);
    lv_obj_t * lv_label_0 = lv_label_create(lv_obj_0);
    lv_label_set_text(lv_label_0, label);
    lv_obj_set_align(lv_label_0, LV_ALIGN_CENTER);

    LV_TRACE_OBJ_CREATE("finished");

    return lv_obj_0;
}

/**********************
 *   STATIC FUNCTIONS
 **********************/

