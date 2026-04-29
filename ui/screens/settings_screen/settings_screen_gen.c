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

    static lv_style_t main_style;
    static lv_style_t title_bar;
    static lv_style_t items;
    static lv_style_t item;

    static bool style_inited = false;

    if (!style_inited) {
        lv_style_init(&main_style);
        lv_style_set_width(&main_style, lv_pct(100));
        lv_style_set_height(&main_style, lv_pct(100));
        lv_style_set_bg_image_src(&main_style, main_bg);

        lv_style_init(&title_bar);
        lv_style_set_flex_main_place(&title_bar, LV_FLEX_ALIGN_CENTER);
        lv_style_set_pad_column(&title_bar, 4);
        lv_style_set_flex_cross_place(&title_bar, LV_FLEX_ALIGN_CENTER);
        lv_style_set_flex_track_place(&title_bar, LV_FLEX_ALIGN_CENTER);
        lv_style_set_text_color(&title_bar, WHITE);
        lv_style_set_text_font(&title_bar, misan_16);
        lv_style_set_bg_opa(&title_bar, 255);
        lv_style_set_bg_color(&title_bar, lv_color_hex(0x11161b));
        lv_style_set_height(&title_bar, 36);
        lv_style_set_width(&title_bar, lv_pct(100));

        lv_style_init(&items);
        lv_style_set_pad_hor(&items, 8);
        lv_style_set_pad_row(&items, 8);
        lv_style_set_flex_grow(&items, 1);
        lv_style_set_width(&items, lv_pct(100));

        lv_style_init(&item);
        lv_style_set_height(&item, 69);
        lv_style_set_width(&item, lv_pct(100));

        style_inited = true;
    }

    lv_obj_t * column_0 = column_create(NULL);
    lv_obj_set_name_static(column_0, "settings_screen_#");
    lv_obj_set_flag(column_0, LV_OBJ_FLAG_SCROLLABLE, false);

    lv_obj_add_style(column_0, &main_style, 0);
    lv_obj_add_event_cb(column_0, on_screen_loaded, LV_EVENT_SCREEN_LOADED, NULL);
    lv_obj_add_event_cb(column_0, on_menu_screen_keyevent, LV_EVENT_KEY, NULL);
    lv_obj_t * row_0 = row_create(column_0);
    lv_obj_add_style(row_0, &title_bar, 0);
    lv_obj_t * lv_label_0 = lv_label_create(row_0);
    lv_label_set_text(lv_label_0, "设置");
    
    lv_obj_t * menu = column_create(column_0);
    lv_obj_set_name(menu, "menu");
    lv_obj_set_flag(menu, LV_OBJ_FLAG_EVENT_BUBBLE, true);
    lv_obj_set_flag(menu, LV_OBJ_FLAG_SCROLLABLE, true);
    lv_obj_set_scrollbar_mode(menu, LV_SCROLLBAR_MODE_OFF);
    lv_obj_add_style(menu, &items, 0);
    lv_obj_t * menu_item_0 = menu_item_create(menu, "步进驱动配置", ic_stepper_30);
    lv_obj_add_style(menu_item_0, &item, 0);
    lv_obj_add_event_cb(menu_item_0, on_menu_item_clicked, LV_EVENT_CLICKED, "0");
    
    lv_obj_t * menu_item_1 = menu_item_create(menu, "舵机控制配置", ic_motor_30);
    lv_obj_add_style(menu_item_1, &item, 0);
    lv_obj_add_event_cb(menu_item_1, on_menu_item_clicked, LV_EVENT_CLICKED, "1");
    
    lv_obj_t * menu_item_2 = menu_item_create(menu, "关于", ic_info_30);
    lv_obj_add_style(menu_item_2, &item, 0);
    lv_obj_add_event_cb(menu_item_2, on_menu_item_clicked, LV_EVENT_CLICKED, "2");

    LV_TRACE_OBJ_CREATE("finished");

    return column_0;
}

/**********************
 *   STATIC FUNCTIONS
 **********************/

