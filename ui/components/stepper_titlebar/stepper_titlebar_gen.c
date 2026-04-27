/**
 * @file stepper_titlebar_gen.c
 * @brief Template source file for LVGL objects
 */

/*********************
 *      INCLUDES
 *********************/

#include "stepper_titlebar_gen.h"
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

lv_obj_t * stepper_titlebar_create(lv_obj_t * parent)
{
    LV_TRACE_OBJ_CREATE("begin");

    static lv_style_t style_base;
    static lv_style_t center_title;
    static lv_style_t dot;
    static lv_style_t st_active;

    static bool style_inited = false;

    if (!style_inited) {
        lv_style_init(&style_base);
        lv_style_set_text_color(&style_base, WHITE);
        lv_style_set_width(&style_base, lv_pct(100));
        lv_style_set_height(&style_base, 23);
        lv_style_set_border_side(&style_base, LV_BORDER_SIDE_BOTTOM);
        lv_style_set_border_width(&style_base, 1);
        lv_style_set_border_color(&style_base, GREY);
        lv_style_set_pad_hor(&style_base, 4);

        lv_style_init(&center_title);
        lv_style_set_text_color(&center_title, WHITE);
        lv_style_set_border_side(&center_title, LV_BORDER_SIDE_NONE);
        lv_style_set_bg_opa(&center_title, 1);
        lv_style_set_height(&center_title, LV_SIZE_CONTENT);

        lv_style_init(&dot);
        lv_style_set_bg_color(&dot, GREY);
        lv_style_set_margin_right(&dot, 4);
        lv_style_set_width(&dot, 12);
        lv_style_set_height(&dot, 12);
        lv_style_set_radius(&dot, 12);
        lv_style_set_bg_opa(&dot, 255);

        lv_style_init(&st_active);
        lv_style_set_bg_color(&st_active, RUNNING);
        lv_style_set_text_color(&st_active, RUNNING);

        style_inited = true;
    }

    lv_obj_t * row_0 = row_create(parent);
    lv_obj_set_name_static(row_0, "stepper_titlebar_#");

    lv_obj_add_style(row_0, &style_base, 0);
    lv_obj_t * lv_label_0 = lv_label_create(row_0);
    lv_label_set_text(lv_label_0, "STEPPER");
    
    lv_obj_t * lv_obj_0 = lv_obj_create(row_0);
    lv_obj_set_flex_grow(lv_obj_0, 1);
    lv_obj_add_style(lv_obj_0, &center_title, 0);
    lv_obj_t * lv_label_1 = lv_label_create(lv_obj_0);
    lv_label_bind_text(lv_label_1, &load_str, NULL);
    lv_obj_set_align(lv_label_1, LV_ALIGN_CENTER);
    
    lv_obj_t * row_1 = row_create(row_0);
    lv_obj_set_width(row_1, LV_SIZE_CONTENT);
    lv_obj_set_height(row_1, lv_pct(100));
    lv_obj_t * lv_obj_1 = lv_obj_create(row_1);
    lv_obj_remove_style(lv_obj_1, NULL, 0);
    lv_obj_add_style(lv_obj_1, &dot, 0);
    lv_obj_add_style(lv_obj_1, &st_active, LV_STATE_USER_1);
    lv_obj_bind_state_if_eq(lv_obj_1, &stepper_status, LV_STATE_USER_1, 1);
    
    lv_obj_t * lv_label_2 = lv_label_create(row_1);
    lv_label_set_text(lv_label_2, "RUN");
    lv_obj_add_style(lv_label_2, &st_active, 0);
    lv_obj_bind_flag_if_not_eq(lv_label_2, &stepper_status, LV_OBJ_FLAG_HIDDEN, 1);
    
    lv_obj_t * lv_label_3 = lv_label_create(row_1);
    lv_label_set_text(lv_label_3, "IDLE");
    lv_obj_bind_flag_if_eq(lv_label_3, &stepper_status, LV_OBJ_FLAG_HIDDEN, 1);

    LV_TRACE_OBJ_CREATE("finished");

    return row_0;
}

/**********************
 *   STATIC FUNCTIONS
 **********************/

