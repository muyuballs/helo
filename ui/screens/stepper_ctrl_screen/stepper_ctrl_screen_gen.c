/**
 * @file stepper_ctrl_screen_gen.c
 * @brief Template source file for LVGL objects
 */

/*********************
 *      INCLUDES
 *********************/

#include "stepper_ctrl_screen_gen.h"
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

lv_obj_t * stepper_ctrl_screen_create(void)
{
    LV_TRACE_OBJ_CREATE("begin");

    static lv_style_t style_base;
    static lv_style_t comment_text;
    static lv_style_t ctrl_base;
    static lv_style_t rpm_base;

    static bool style_inited = false;

    if (!style_inited) {
        lv_style_init(&style_base);
        lv_style_set_pad_all(&style_base, 4);
        lv_style_set_layout(&style_base, LV_LAYOUT_NONE);
        lv_style_set_height(&style_base, lv_pct(100));
        lv_style_set_width(&style_base, lv_pct(100));

        lv_style_init(&comment_text);
        lv_style_set_text_color(&comment_text, DARKGREY);

        lv_style_init(&ctrl_base);
        lv_style_set_align(&ctrl_base, LV_ALIGN_CENTER);
        lv_style_set_width(&ctrl_base, 160);
        lv_style_set_height(&ctrl_base, 160);
        lv_style_set_radius(&ctrl_base, 255);
        lv_style_set_bg_opa(&ctrl_base, 255);
        lv_style_set_bg_color(&ctrl_base, GREY);

        lv_style_init(&rpm_base);
        lv_style_set_text_font(&rpm_base, font_medium_48);

        style_inited = true;
    }

    lv_obj_t * lv_obj_0 = lv_obj_create(NULL);
    lv_obj_set_name_static(lv_obj_0, "stepper_ctrl_screen_#");
    lv_obj_set_width(lv_obj_0, lv_pct(100));
    lv_obj_set_height(lv_obj_0, lv_pct(100));
    lv_obj_set_flag(lv_obj_0, LV_OBJ_FLAG_SCROLLABLE, false);
    lv_obj_set_scrollbar_mode(lv_obj_0, LV_SCROLLBAR_MODE_OFF);

    lv_obj_remove_style(lv_obj_0, NULL, 0);
    lv_obj_add_style(lv_obj_0, &style_base, 0);
    lv_obj_t * lv_label_0 = lv_label_create(lv_obj_0);
    lv_label_set_text(lv_label_0, "TMC220X");
    lv_obj_add_style(lv_label_0, &comment_text, 0);
    
    lv_obj_t * lv_label_1 = lv_label_create(lv_obj_0);
    lv_label_set_text(lv_label_1, "1/256");
    lv_obj_set_align(lv_label_1, LV_ALIGN_TOP_RIGHT);
    lv_obj_add_style(lv_label_1, &comment_text, 0);
    
    lv_obj_t * lv_label_2 = lv_label_create(lv_obj_0);
    lv_label_set_text(lv_label_2, "CCW");
    lv_obj_set_align(lv_label_2, LV_ALIGN_BOTTOM_LEFT);
    lv_obj_add_style(lv_label_2, &comment_text, 0);
    
    lv_obj_t * lv_label_3 = lv_label_create(lv_obj_0);
    lv_label_bind_text(lv_label_3, &vol, "%.1f v");
    lv_obj_set_align(lv_label_3, LV_ALIGN_BOTTOM_MID);
    lv_obj_add_style(lv_label_3, &comment_text, 0);
    
    lv_obj_t * lv_label_4 = lv_label_create(lv_obj_0);
    lv_label_bind_text(lv_label_4, &load_str, NULL);
    lv_obj_set_align(lv_label_4, LV_ALIGN_BOTTOM_RIGHT);
    lv_obj_add_style(lv_label_4, &comment_text, 0);
    
    lv_obj_t * lv_obj_1 = lv_obj_create(lv_obj_0);
    lv_obj_remove_style(lv_obj_1, NULL, 0);
    lv_obj_add_style(lv_obj_1, &ctrl_base, 0);
    lv_obj_t * column_0 = column_create(lv_obj_1);
    lv_obj_set_width(column_0, LV_SIZE_CONTENT);
    lv_obj_set_height(column_0, LV_SIZE_CONTENT);
    lv_obj_set_align(column_0, LV_ALIGN_CENTER);
    lv_obj_set_style_flex_cross_place(column_0, LV_FLEX_ALIGN_CENTER, 0);
    lv_obj_t * lv_label_5 = lv_label_create(column_0);
    lv_label_bind_text(lv_label_5, &rpm, "%.1f");
    lv_obj_add_style(lv_label_5, &rpm_base, 0);
    
    lv_obj_t * lv_label_6 = lv_label_create(column_0);
    lv_label_set_text(lv_label_6, "rpm");

    LV_TRACE_OBJ_CREATE("finished");

    return lv_obj_0;
}

/**********************
 *   STATIC FUNCTIONS
 **********************/

