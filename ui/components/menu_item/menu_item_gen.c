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

lv_obj_t * menu_item_create(lv_obj_t * parent, const char * text, bool has_sub)
{
    LV_TRACE_OBJ_CREATE("begin");

    static lv_style_t style_base;
    static lv_style_t selected;
    static lv_style_t style_title;

    static bool style_inited = false;

    if (!style_inited) {
        lv_style_init(&style_base);
        lv_style_set_shadow_color(&style_base, GREY);
        lv_style_set_shadow_width(&style_base, 2);
        lv_style_set_border_width(&style_base, 1);
        lv_style_set_radius(&style_base, 3);
        lv_style_set_pad_all(&style_base, 3);
        lv_style_set_width(&style_base, lv_pct(100));
        lv_style_set_border_color(&style_base, DARKGREY);
        lv_style_set_flex_main_place(&style_base, LV_FLEX_ALIGN_SPACE_BETWEEN);

        lv_style_init(&selected);
        lv_style_set_border_color(&selected, ACTIVE);

        lv_style_init(&style_title);
        lv_style_set_text_color(&style_title, BLACK);

        style_inited = true;
    }

    lv_obj_t * row_0 = row_create(parent);
    lv_obj_set_name_static(row_0, "menu_item_#");
    lv_obj_set_flag(row_0, LV_OBJ_FLAG_CLICK_FOCUSABLE, true);

    lv_obj_add_style(row_0, &style_base, 0);
    lv_obj_add_style(row_0, &selected, LV_STATE_FOCUSED);
    lv_obj_t * lv_label_0 = lv_label_create(row_0);
    lv_label_set_text(lv_label_0, text);
    lv_obj_add_style(lv_label_0, &style_title, 0);

    LV_TRACE_OBJ_CREATE("finished");

    return row_0;
}

/**********************
 *   STATIC FUNCTIONS
 **********************/

