/**
 * @file ui_helo_gen.h
 */

#ifndef UI_HELO_GEN_H
#define UI_HELO_GEN_H

#ifndef UI_SUBJECT_STRING_LENGTH
#define UI_SUBJECT_STRING_LENGTH 256
#endif

#ifdef __cplusplus
extern "C" {
#endif

/*********************
 *      INCLUDES
 *********************/

#ifdef LV_LVGL_H_INCLUDE_SIMPLE
    #include "lvgl.h"
    #include "src/core/lv_obj_class_private.h"
#else
    #include "lvgl/lvgl.h"
    #include "lvgl/src/core/lv_obj_class_private.h"
#endif



/*********************
 *      DEFINES
 *********************/

#define GREY lv_color_hex(0xe2e2e2)

#define WHITE lv_color_hex(0xffffff)

#define GREEN lv_color_hex(0x00ff00)

#define RED lv_color_hex(0xff0000)

#define ACTIVE lv_color_hex(0x165DFF)

#define RUNNING lv_color_hex(0x00B42A)

#define SECTION_TITLE_TEXT lv_color_hex(0x4E5969)

#define DARKGREY lv_color_hex(0x919191)

#define BLACK lv_color_hex(0x000000)

/**********************
 *      TYPEDEFS
 **********************/

/**********************
 * GLOBAL VARIABLES
 **********************/

/*-------------------
 * Permanent screens
 *------------------*/

/*----------------
 * Global styles
 *----------------*/

extern lv_style_t section_title;

/*----------------
 * Fonts
 *----------------*/

extern lv_font_t * font_medium_48;

extern lv_font_t * font_medium;

/*----------------
 * Images
 *----------------*/

/*----------------
 * Subjects
 *----------------*/

extern lv_subject_t stepper_status;
extern lv_subject_t load_str;
extern lv_subject_t driver_type;
extern lv_subject_t micro_steps;
extern lv_subject_t rotate_dir;
extern lv_subject_t rpm;
extern lv_subject_t vol;

/**********************
 * GLOBAL PROTOTYPES
 **********************/

/*----------------
 * Event Callbacks
 *----------------*/

/**
 * Initialize the component library
 */

void ui_helo_init_gen(const char * asset_path);

/**********************
 *      MACROS
 **********************/

/**********************
 *   POST INCLUDES
 **********************/

/*Include all the widgets, components and screens of this library*/
#include "components/column/column_gen.h"
#include "components/driver_switch/driver_switch_gen.h"
#include "components/micro_steps/micro_steps_gen.h"
#include "components/radio/radio_gen.h"
#include "components/rotate_dir/rotate_dir_gen.h"
#include "components/row/row_gen.h"
#include "components/stepper_titlebar/stepper_titlebar_gen.h"
#include "screens/screen_hello_world_gen.h"
#include "screens/stepper_ctrl_screen/stepper_ctrl_screen_gen.h"

#ifdef __cplusplus
} /*extern "C"*/
#endif

#endif /*UI_HELO_GEN_H*/