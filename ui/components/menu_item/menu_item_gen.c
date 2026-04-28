/**
 * @file menu_item_gen.c
 * @brief Template source file for LVGL objects
 */

/*********************
 *      INCLUDES
 *********************/

#include "menu_item_gen.h"
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

lv_obj_t * menu_item_create(lv_obj_t * parent, const char * text)
{
    LV_TRACE_OBJ_CREATE("begin");

    static lv_style_t style_base;

    static bool style_inited = false;

    if (!style_inited) {
        lv_style_init(&style_base);
        lv_style_set_bg_color(&style_base, lv_color_hex(0x6688ee));

        style_inited = true;
    }

    lv_obj_t * row_0 = row_create(parent);
    lv_obj_set_name_static(row_0, "menu_item_#");

    lv_obj_t * lv_label_0 = lv_label_create(row_0);
    lv_label_set_text(lv_label_0, text);

    LV_TRACE_OBJ_CREATE("finished");

    return row_0;
}

/**********************
 *   STATIC FUNCTIONS
 **********************/

