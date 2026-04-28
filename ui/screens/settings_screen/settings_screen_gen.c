/**
 * @file settings_screen_gen.c
 * @brief Template source file for LVGL objects
 */

/*********************
 *      INCLUDES
 *********************/

#include "settings_screen_gen.h"
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

lv_obj_t * settings_screen_create(void)
{
    LV_TRACE_OBJ_CREATE("begin");

    static lv_style_t menu;
    static lv_style_t item;

    static bool style_inited = false;

    if (!style_inited) {
        lv_style_init(&menu);
        lv_style_set_pad_all(&menu, 8);
        lv_style_set_width(&menu, lv_pct(100));
        lv_style_set_height(&menu, lv_pct(100));
        lv_style_set_pad_row(&menu, 4);
        lv_style_set_flex_cross_place(&menu, LV_FLEX_ALIGN_START);
        lv_style_set_flex_track_place(&menu, LV_FLEX_ALIGN_START);

        lv_style_init(&item);
        lv_style_set_height(&item, 32);
        lv_style_set_width(&item, lv_pct(100));

        style_inited = true;
    }

    lv_obj_t * column_0 = column_create(NULL);
    lv_obj_set_name_static(column_0, "settings_screen_#");
    lv_obj_set_flag(column_0, LV_OBJ_FLAG_SCROLLABLE, true);
    lv_obj_set_scrollbar_mode(column_0, LV_SCROLLBAR_MODE_AUTO);

    lv_obj_add_style(column_0, &menu, 0);
    lv_obj_t * menu_item_0 = menu_item_create(column_0, "STEEPER", true);
    lv_obj_add_style(menu_item_0, &item, 0);
    
    lv_obj_t * menu_item_1 = menu_item_create(column_0, "Routate", true);
    lv_obj_add_style(menu_item_1, &item, 0);
    
    lv_obj_t * menu_item_2 = menu_item_create(column_0, "ABOUT", true);
    lv_obj_add_style(menu_item_2, &item, 0);

    LV_TRACE_OBJ_CREATE("finished");

    return column_0;
}

/**********************
 *   STATIC FUNCTIONS
 **********************/

