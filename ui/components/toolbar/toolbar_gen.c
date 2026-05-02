/**
 * @file toolbar_gen.c
 * @brief Template source file for LVGL objects
 */

/*********************
 *      INCLUDES
 *********************/

#include "toolbar_gen.h"
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

lv_obj_t * toolbar_create(lv_obj_t * parent, const char * title, int32_t height)
{
    LV_TRACE_OBJ_CREATE("begin");

    static lv_style_t toolbar_style;

    static bool style_inited = false;

    if (!style_inited) {
        lv_style_init(&toolbar_style);
        lv_style_set_flex_main_place(&toolbar_style, LV_FLEX_ALIGN_CENTER);
        lv_style_set_pad_column(&toolbar_style, 4);
        lv_style_set_flex_cross_place(&toolbar_style, LV_FLEX_ALIGN_CENTER);
        lv_style_set_flex_track_place(&toolbar_style, LV_FLEX_ALIGN_CENTER);
        lv_style_set_text_color(&toolbar_style, WHITE);
        lv_style_set_text_font(&toolbar_style, misan_16);
        lv_style_set_bg_opa(&toolbar_style, 255);
        lv_style_set_bg_color(&toolbar_style, lv_color_hex(0x11161b));
        lv_style_set_height(&toolbar_style, height);
        lv_style_set_width(&toolbar_style, lv_pct(100));

        style_inited = true;
    }

    lv_obj_t * row_0 = row_create(parent);
    lv_obj_set_name_static(row_0, "toolbar_#");

    lv_obj_add_style(row_0, &toolbar_style, 0);
    lv_obj_t * lv_label_0 = lv_label_create(row_0);
    lv_label_set_text(lv_label_0, title);

    LV_TRACE_OBJ_CREATE("finished");

    return row_0;
}

/**********************
 *   STATIC FUNCTIONS
 **********************/

