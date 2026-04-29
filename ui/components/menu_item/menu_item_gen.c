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
    static lv_style_t dot;
    static lv_style_t selected;
    static lv_style_t style_title;

    static bool style_inited = false;

    if (!style_inited) {
        lv_style_init(&style_base);
        lv_style_set_border_side(&style_base, LV_BORDER_SIDE_NONE);
        lv_style_set_radius(&style_base, 3);
        lv_style_set_pad_all(&style_base, 3);
        lv_style_set_width(&style_base, lv_pct(100));
        lv_style_set_border_color(&style_base, DARKGREY);
        lv_style_set_text_color(&style_base, BLACK);
        lv_style_set_flex_cross_place(&style_base, LV_FLEX_ALIGN_CENTER);
        lv_style_set_flex_track_place(&style_base, LV_FLEX_ALIGN_CENTER);

        lv_style_init(&dot);
        lv_style_set_opa(&dot, 0);
        lv_style_set_margin_right(&dot, 8);
        lv_style_set_bg_opa(&dot, 255);
        lv_style_set_bg_color(&dot, ACTIVE);
        lv_style_set_radius(&dot, 12);
        lv_style_set_width(&dot, 12);
        lv_style_set_height(&dot, 12);

        lv_style_init(&selected);
        lv_style_set_text_color(&selected, ACTIVE);

        lv_style_init(&style_title);
        lv_style_set_text_font(&style_title, misan_16);

        style_inited = true;
    }

    lv_obj_t * row_0 = row_create(parent);
    lv_obj_set_name_static(row_0, "menu_item_#");
    lv_obj_set_flag(row_0, LV_OBJ_FLAG_CLICKABLE, true);

    lv_obj_add_style(row_0, &style_base, 0);
    lv_obj_add_style(row_0, &selected, LV_STATE_FOCUSED);
    lv_obj_add_event_cb(row_0, on_menu_item_focus_changed, LV_EVENT_FOCUSED, NULL);
    lv_obj_t * prefix = lv_obj_create(row_0);
    lv_obj_set_name(prefix, "prefix");
    lv_obj_remove_style(prefix, NULL, 0);
    lv_obj_add_style(prefix, &dot, 0);
    
    lv_obj_t * lv_label_0 = lv_label_create(row_0);
    lv_label_set_text(lv_label_0, text);
    lv_obj_add_style(lv_label_0, &style_title, 0);

    LV_TRACE_OBJ_CREATE("finished");

    return row_0;
}

/**********************
 *   STATIC FUNCTIONS
 **********************/

