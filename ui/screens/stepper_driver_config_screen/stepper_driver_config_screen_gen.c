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


    static bool style_inited = false;

    if (!style_inited) {

        style_inited = true;
    }

    lv_obj_t * column_0 = column_create(NULL);
    lv_obj_set_name_static(column_0, "stepper_driver_config_screen_#");

    lv_obj_add_style(column_0, &screen_base, 0);
    toolbar_create(column_0, "步进驱动配置", 32);

    LV_TRACE_OBJ_CREATE("finished");

    return column_0;
}

/**********************
 *   STATIC FUNCTIONS
 **********************/

