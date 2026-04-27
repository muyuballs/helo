/**
 * @file screen_hello_world_gen.c
 * @brief Template source file for LVGL objects
 */

/*********************
 *      INCLUDES
 *********************/

#include "screen_hello_world_gen.h"
#include "../ui_helo.h"

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

lv_obj_t * screen_hello_world_create(void)
{
    LV_TRACE_OBJ_CREATE("begin");

    static lv_style_t style_main;
    static lv_style_t content;
    static lv_style_t rpm_container;
    static lv_style_t rpm_container_active;
    static lv_style_t rpm_info;

    static bool style_inited = false;

    if (!style_inited) {
        lv_style_init(&style_main);
        lv_style_set_width(&style_main, lv_pct(100));
        lv_style_set_height(&style_main, lv_pct(100));
        lv_style_set_bg_color(&style_main, BLACK);
        lv_style_set_bg_opa(&style_main, 255);

        lv_style_init(&content);
        lv_style_set_pad_all(&content, 4);
        lv_style_set_pad_row(&content, 6);
        lv_style_set_width(&content, lv_pct(100));
        lv_style_set_flex_grow(&content, 1);

        lv_style_init(&rpm_container);
        lv_style_set_flex_grow(&rpm_container, 1);
        lv_style_set_border_width(&rpm_container, 2);
        lv_style_set_border_color(&rpm_container, DARKGREY);
        lv_style_set_bg_color(&rpm_container, GREY);
        lv_style_set_bg_opa(&rpm_container, 255);
        lv_style_set_radius(&rpm_container, 8);
        lv_style_set_width(&rpm_container, lv_pct(100));

        lv_style_init(&rpm_container_active);
        lv_style_set_bg_color(&rpm_container_active, ACTIVE);
        lv_style_set_text_color(&rpm_container_active, WHITE);
        lv_style_set_border_side(&rpm_container_active, LV_BORDER_SIDE_NONE);

        lv_style_init(&rpm_info);
        lv_style_set_pad_column(&rpm_info, 2);
        lv_style_set_text_color(&rpm_info, DARKGREY);
        lv_style_set_width(&rpm_info, LV_SIZE_CONTENT);
        lv_style_set_height(&rpm_info, lv_pct(100));
        lv_style_set_align(&rpm_info, LV_ALIGN_CENTER);

        style_inited = true;
    }

    lv_obj_t * column_0 = column_create(NULL);
    lv_obj_set_name_static(column_0, "screen_hello_world_#");
    lv_obj_set_flag(column_0, LV_OBJ_FLAG_SCROLLABLE, false);
    lv_obj_set_scrollbar_mode(column_0, LV_SCROLLBAR_MODE_OFF);

    lv_obj_add_style(column_0, &style_main, 0);
    stepper_titlebar_create(column_0);
    
    lv_obj_t * column_1 = column_create(column_0);
    lv_obj_add_style(column_1, &content, 0);
    driver_switch_create(column_1, 22);
    
    micro_steps_create(column_1, 22);
    
    rotate_dir_create(column_1, 22);
    
    lv_obj_t * lv_obj_0 = lv_obj_create(column_1);
    lv_obj_remove_style(lv_obj_0, NULL, 0);
    lv_obj_add_style(lv_obj_0, &rpm_container, 0);
    lv_obj_add_style(lv_obj_0, &rpm_container_active, LV_STATE_USER_1);
    lv_obj_bind_state_if_eq(lv_obj_0, &stepper_status, LV_STATE_USER_1, 1);
    lv_obj_t * row_0 = row_create(lv_obj_0);
    lv_obj_set_scrollbar_mode(row_0, LV_SCROLLBAR_MODE_OFF);
    lv_obj_set_flag(row_0, LV_OBJ_FLAG_SCROLLABLE, false);
    lv_obj_add_style(row_0, &rpm_info, 0);
    lv_obj_t * lv_label_0 = lv_label_create(row_0);
    lv_label_set_text(lv_label_0, "0");
    
    lv_obj_t * lv_label_1 = lv_label_create(row_0);
    lv_label_set_text(lv_label_1, "rpm");

    LV_TRACE_OBJ_CREATE("finished");

    return column_0;
}

/**********************
 *   STATIC FUNCTIONS
 **********************/

