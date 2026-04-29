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

lv_obj_t * menu_item_create(lv_obj_t * parent, const char * text, const void * icon)
{
    LV_TRACE_OBJ_CREATE("begin");

    static lv_style_t style_base;
    static lv_style_t selected;
    static lv_style_t title_style;
    static lv_style_t icon_style;

    static bool style_inited = false;

    if (!style_inited) {
        lv_style_init(&style_base);
        lv_style_set_border_width(&style_base, 2);
        lv_style_set_border_color(&style_base, ACTIVE);
        lv_style_set_border_side(&style_base, LV_BORDER_SIDE_NONE);
        lv_style_set_radius(&style_base, 3);
        lv_style_set_pad_left(&style_base, 12);
        lv_style_set_pad_right(&style_base, 4);
        lv_style_set_width(&style_base, lv_pct(100));
        lv_style_set_height(&style_base, 69);
        lv_style_set_bg_image_src(&style_base, mitem_bg);
        lv_style_set_flex_cross_place(&style_base, LV_FLEX_ALIGN_CENTER);
        lv_style_set_flex_track_place(&style_base, LV_FLEX_ALIGN_CENTER);

        lv_style_init(&selected);
        lv_style_set_border_side(&selected, LV_BORDER_SIDE_FULL);

        lv_style_init(&title_style);
        lv_style_set_text_color(&title_style, WHITE);
        lv_style_set_flex_grow(&title_style, 1);
        lv_style_set_text_font(&title_style, misan_22);
        lv_style_set_pad_hor(&title_style, 12);
        lv_style_set_text_align(&title_style, LV_TEXT_ALIGN_LEFT);

        lv_style_init(&icon_style);
        lv_style_set_width(&icon_style, 30);
        lv_style_set_height(&icon_style, 30);

        style_inited = true;
    }

    lv_obj_t * row_0 = row_create(parent);
    lv_obj_set_name_static(row_0, "menu_item_#");
    lv_obj_set_flag(row_0, LV_OBJ_FLAG_CLICKABLE, true);
    lv_obj_set_flag(row_0, LV_OBJ_FLAG_SCROLLABLE, false);

    lv_obj_add_style(row_0, &style_base, 0);
    lv_obj_add_style(row_0, &selected, LV_STATE_FOCUSED);
    lv_obj_add_event_cb(row_0, on_menu_item_focus_changed, LV_EVENT_FOCUSED, NULL);
    lv_obj_t * lv_image_0 = lv_image_create(row_0);
    lv_image_set_src(lv_image_0, icon);
    lv_obj_add_style(lv_image_0, &icon_style, 0);
    
    lv_obj_t * lv_label_0 = lv_label_create(row_0);
    lv_label_set_text(lv_label_0, text);
    lv_obj_add_style(lv_label_0, &title_style, 0);
    
    lv_obj_t * lv_image_1 = lv_image_create(row_0);
    lv_image_set_src(lv_image_1, ic_more_24);

    LV_TRACE_OBJ_CREATE("finished");

    return row_0;
}

/**********************
 *   STATIC FUNCTIONS
 **********************/

