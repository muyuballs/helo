/**
 * @file rotate_dir_gen.c
 * @brief Template source file for LVGL objects
 */

/*********************
 *      INCLUDES
 *********************/

#include "rotate_dir_gen.h"
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

lv_obj_t * rotate_dir_create(lv_obj_t * parent, int32_t c_height)
{
    LV_TRACE_OBJ_CREATE("begin");

    static lv_style_t style_base;
    static lv_style_t radio_item;

    static bool style_inited = false;

    if (!style_inited) {
        lv_style_init(&style_base);
        lv_style_set_width(&style_base, lv_pct(100));
        lv_style_set_height(&style_base, LV_SIZE_CONTENT);
        lv_style_set_pad_row(&style_base, 4);
        lv_style_set_flex_cross_place(&style_base, LV_FLEX_ALIGN_START);
        lv_style_set_bg_color(&style_base, lv_color_hex(0x6688ee));

        lv_style_init(&radio_item);
        lv_style_set_height(&radio_item, lv_pct(100));

        style_inited = true;
    }

    lv_obj_t * column_0 = column_create(parent);
    lv_obj_set_name_static(column_0, "rotate_dir_#");

    lv_obj_add_style(column_0, &style_base, 0);
    lv_obj_t * lv_label_0 = lv_label_create(column_0);
    lv_label_set_text(lv_label_0, "DIR");
    lv_obj_add_style(lv_label_0, &section_title, 0);
    
    lv_obj_t * row_0 = row_create(column_0);
    lv_obj_set_width(row_0, lv_pct(100));
    lv_obj_set_height(row_0, c_height);
    lv_obj_set_style_pad_column(row_0, 4, 0);
    lv_obj_t * radio_0 = radio_create(row_0, "CW");
    lv_obj_set_flex_grow(radio_0, 1);
    lv_obj_add_style(radio_0, &radio_item, 0);
    lv_obj_bind_state_if_eq(radio_0, &rotate_dir, LV_STATE_CHECKED, 0);
    
    lv_obj_t * radio_1 = radio_create(row_0, "CCW");
    lv_obj_set_flex_grow(radio_1, 1);
    lv_obj_add_style(radio_1, &radio_item, 0);
    lv_obj_bind_state_if_eq(radio_1, &rotate_dir, LV_STATE_CHECKED, 1);

    LV_TRACE_OBJ_CREATE("finished");

    return column_0;
}

/**********************
 *   STATIC FUNCTIONS
 **********************/

