/**
 * @file stepper_driver_config_screen_gen.c
 * @brief Template source file for LVGL objects
 */

/*********************
 *      INCLUDES
 *********************/

#include "stepper_driver_config_screen_gen.h"
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

lv_obj_t * stepper_driver_config_screen_create(void)
{
    LV_TRACE_OBJ_CREATE("begin");

    static lv_style_t content;
    static lv_style_t sub_title;
    static lv_style_t radios_container;
    static lv_style_t radio_item;
    static lv_style_t micro_steps_container;

    static bool style_inited = false;

    if (!style_inited) {
        lv_style_init(&content);
        lv_style_set_pad_all(&content, 8);
        lv_style_set_pad_row(&content, 8);
        lv_style_set_flex_cross_place(&content, LV_FLEX_ALIGN_START);
        lv_style_set_flex_track_place(&content, LV_FLEX_ALIGN_START);
        lv_style_set_width(&content, lv_pct(100));
        lv_style_set_flex_grow(&content, 1);

        lv_style_init(&sub_title);
        lv_style_set_text_font(&sub_title, misan_16);
        lv_style_set_text_color(&sub_title, DARKGREY);

        lv_style_init(&radios_container);
        lv_style_set_pad_column(&radios_container, 6);
        lv_style_set_width(&radios_container, lv_pct(100));
        lv_style_set_height(&radios_container, LV_SIZE_CONTENT);

        lv_style_init(&radio_item);
        lv_style_set_grid_column_align(&radio_item, LV_GRID_ALIGN_STRETCH);
        lv_style_set_grid_row_align(&radio_item, LV_GRID_ALIGN_STRETCH);
        lv_style_set_radius(&radio_item, 14);
        lv_style_set_height(&radio_item, 32);
        lv_style_set_flex_grow(&radio_item, 1);

        lv_style_init(&micro_steps_container);
        lv_style_set_layout(&micro_steps_container, LV_LAYOUT_GRID);
        static const int32_t micro_steps_container_grid_column_dsc_array_0[] = {536870812,536870812,536870812, LV_GRID_TEMPLATE_LAST};
        lv_style_set_grid_column_dsc_array(&micro_steps_container, micro_steps_container_grid_column_dsc_array_0);
        static const int32_t micro_steps_container_grid_row_dsc_array_1[] = {32,32,32, LV_GRID_TEMPLATE_LAST};
        lv_style_set_grid_row_dsc_array(&micro_steps_container, micro_steps_container_grid_row_dsc_array_1);
        lv_style_set_width(&micro_steps_container, lv_pct(100));
        lv_style_set_height(&micro_steps_container, LV_SIZE_CONTENT);
        lv_style_set_pad_column(&micro_steps_container, 6);
        lv_style_set_pad_row(&micro_steps_container, 4);

        style_inited = true;
    }

    lv_obj_t * column_0 = column_create(NULL);
    lv_obj_set_name_static(column_0, "stepper_driver_config_screen_#");
    lv_obj_set_flag(column_0, LV_OBJ_FLAG_SCROLLABLE, false);

    lv_obj_add_style(column_0, &screen_base, 0);
    lv_obj_add_event_cb(column_0, on_screen_loaded, LV_EVENT_SCREEN_LOADED, NULL);
    lv_obj_add_event_cb(column_0, on_stepper_driver_config_keyevent, LV_EVENT_KEY, NULL);
    toolbar_create(column_0, "步进驱动配置", 32);
    
    lv_obj_t * menu = column_create(column_0);
    lv_obj_set_name(menu, "menu");
    lv_obj_set_flag(menu, LV_OBJ_FLAG_EVENT_BUBBLE, true);
    lv_obj_set_flag(menu, LV_OBJ_FLAG_SCROLLABLE, true);
    lv_obj_set_scrollbar_mode(menu, LV_SCROLLBAR_MODE_OFF);
    lv_obj_add_style(menu, &content, 0);
    lv_obj_t * lv_label_0 = lv_label_create(menu);
    lv_label_set_text(lv_label_0, "驱动类型");
    lv_obj_add_style(lv_label_0, &sub_title, 0);
    
    lv_obj_t * row_0 = row_create(menu);
    lv_obj_set_flag(row_0, LV_OBJ_FLAG_EVENT_BUBBLE, true);
    lv_obj_set_flag(row_0, LV_OBJ_FLAG_CLICK_FOCUSABLE, true);
    lv_obj_add_style(row_0, &radios_container, 0);
    lv_obj_t * radio_0 = radio_create(row_0, "TMC2209");
    lv_obj_add_style(radio_0, &radio_item, 0);
    lv_obj_bind_state_if_eq(radio_0, &driver_type, LV_STATE_CHECKED, 0);
    
    lv_obj_t * radio_1 = radio_create(row_0, "A4988");
    lv_obj_add_style(radio_1, &radio_item, 0);
    lv_obj_bind_state_if_eq(radio_1, &driver_type, LV_STATE_CHECKED, 1);
    
    lv_obj_t * lv_label_1 = lv_label_create(menu);
    lv_label_set_text(lv_label_1, "细分设置");
    lv_obj_add_style(lv_label_1, &sub_title, 0);
    
    lv_obj_t * lv_obj_0 = lv_obj_create(menu);
    lv_obj_set_flag(lv_obj_0, LV_OBJ_FLAG_EVENT_BUBBLE, true);
    lv_obj_set_flag(lv_obj_0, LV_OBJ_FLAG_CLICK_FOCUSABLE, true);
    lv_obj_remove_style(lv_obj_0, NULL, 0);
    lv_obj_add_style(lv_obj_0, &micro_steps_container, 0);
    lv_obj_t * radio_2 = radio_create(lv_obj_0, "1/1");
    lv_obj_set_style_grid_cell_row_pos(radio_2, 0, 0);
    lv_obj_set_style_grid_cell_column_pos(radio_2, 0, 0);
    lv_obj_add_style(radio_2, &radio_item, 0);
    lv_obj_bind_state_if_eq(radio_2, &micro_steps, LV_STATE_CHECKED, 0);
    
    lv_obj_t * radio_3 = radio_create(lv_obj_0, "1/2");
    lv_obj_set_style_grid_cell_row_pos(radio_3, 0, 0);
    lv_obj_set_style_grid_cell_column_pos(radio_3, 1, 0);
    lv_obj_add_style(radio_3, &radio_item, 0);
    lv_obj_bind_state_if_eq(radio_3, &micro_steps, LV_STATE_CHECKED, 1);
    
    lv_obj_t * radio_4 = radio_create(lv_obj_0, "1/4");
    lv_obj_set_style_grid_cell_row_pos(radio_4, 0, 0);
    lv_obj_set_style_grid_cell_column_pos(radio_4, 2, 0);
    lv_obj_add_style(radio_4, &radio_item, 0);
    lv_obj_bind_state_if_eq(radio_4, &micro_steps, LV_STATE_CHECKED, 1);
    
    lv_obj_t * radio_5 = radio_create(lv_obj_0, "1/8");
    lv_obj_set_style_grid_cell_row_pos(radio_5, 1, 0);
    lv_obj_set_style_grid_cell_column_pos(radio_5, 0, 0);
    lv_obj_add_style(radio_5, &radio_item, 0);
    lv_obj_bind_state_if_eq(radio_5, &micro_steps, LV_STATE_CHECKED, 1);
    
    lv_obj_t * radio_6 = radio_create(lv_obj_0, "1/16");
    lv_obj_set_style_grid_cell_row_pos(radio_6, 1, 0);
    lv_obj_set_style_grid_cell_column_pos(radio_6, 1, 0);
    lv_obj_add_style(radio_6, &radio_item, 0);
    lv_obj_bind_state_if_eq(radio_6, &micro_steps, LV_STATE_CHECKED, 1);
    
    lv_obj_t * radio_7 = radio_create(lv_obj_0, "1/32");
    lv_obj_set_style_grid_cell_row_pos(radio_7, 1, 0);
    lv_obj_set_style_grid_cell_column_pos(radio_7, 2, 0);
    lv_obj_add_style(radio_7, &radio_item, 0);
    lv_obj_bind_state_if_eq(radio_7, &micro_steps, LV_STATE_CHECKED, 1);
    
    lv_obj_t * radio_8 = radio_create(lv_obj_0, "1/64");
    lv_obj_set_style_grid_cell_row_pos(radio_8, 2, 0);
    lv_obj_set_style_grid_cell_column_pos(radio_8, 0, 0);
    lv_obj_add_style(radio_8, &radio_item, 0);
    lv_obj_bind_state_if_eq(radio_8, &micro_steps, LV_STATE_CHECKED, 1);
    
    lv_obj_t * radio_9 = radio_create(lv_obj_0, "1/128");
    lv_obj_set_style_grid_cell_row_pos(radio_9, 2, 0);
    lv_obj_set_style_grid_cell_column_pos(radio_9, 1, 0);
    lv_obj_add_style(radio_9, &radio_item, 0);
    lv_obj_bind_state_if_eq(radio_9, &micro_steps, LV_STATE_CHECKED, 1);
    
    lv_obj_t * radio_10 = radio_create(lv_obj_0, "1/256");
    lv_obj_set_style_grid_cell_row_pos(radio_10, 2, 0);
    lv_obj_set_style_grid_cell_column_pos(radio_10, 2, 0);
    lv_obj_add_style(radio_10, &radio_item, 0);
    lv_obj_bind_state_if_eq(radio_10, &micro_steps, LV_STATE_CHECKED, 1);
    
    lv_obj_t * lv_label_2 = lv_label_create(menu);
    lv_label_set_text(lv_label_2, "旋转方向");
    lv_obj_add_style(lv_label_2, &sub_title, 0);
    
    lv_obj_t * row_1 = row_create(menu);
    lv_obj_set_flag(row_1, LV_OBJ_FLAG_EVENT_BUBBLE, true);
    lv_obj_set_flag(row_1, LV_OBJ_FLAG_CLICK_FOCUSABLE, true);
    lv_obj_add_style(row_1, &radios_container, 0);
    lv_obj_t * radio_11 = radio_create(row_1, "CW");
    lv_obj_add_style(radio_11, &radio_item, 0);
    lv_obj_bind_state_if_eq(radio_11, &rotate_dir, LV_STATE_CHECKED, 0);
    
    lv_obj_t * radio_12 = radio_create(row_1, "CCW");
    lv_obj_add_style(radio_12, &radio_item, 0);
    lv_obj_bind_state_if_eq(radio_12, &rotate_dir, LV_STATE_CHECKED, 1);

    LV_TRACE_OBJ_CREATE("finished");

    return column_0;
}

/**********************
 *   STATIC FUNCTIONS
 **********************/

