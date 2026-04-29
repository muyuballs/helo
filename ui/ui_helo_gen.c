/**
 * @file ui_helo_gen.c
 */

/*********************
 *      INCLUDES
 *********************/

#include "ui_helo_gen.h"

#if LV_USE_XML
#endif /* LV_USE_XML */

/*********************
 *      DEFINES
 *********************/

/**********************
 *      TYPEDEFS
 **********************/

/**********************
 *  STATIC PROTOTYPES
 **********************/

/**********************
 *  STATIC VARIABLES
 **********************/

/*----------------
 * Translations
 *----------------*/

/**********************
 *  GLOBAL VARIABLES
 **********************/

/*--------------------
 *  Permanent screens
 *-------------------*/

/*----------------
 * Fonts
 *----------------*/

lv_font_t * misan_16;
extern lv_font_t misan_16_data;
lv_font_t * font_medium_48;
extern lv_font_t font_medium_48_data;
lv_font_t * font_medium;
extern lv_font_t font_medium_data;

/*----------------
 * Images
 *----------------*/

const void * main_bg;
extern const void * main_bg_data;
const void * mitem_bg;
extern const void * mitem_bg_data;
const void * ic_info_30;
extern const void * ic_info_30_data;
const void * ic_more_24;
extern const void * ic_more_24_data;
const void * ic_motor_30;
extern const void * ic_motor_30_data;
const void * ic_setting_20;
extern const void * ic_setting_20_data;
const void * ic_stepper_30;
extern const void * ic_stepper_30_data;

/*----------------
 * Global styles
 *----------------*/

lv_style_t section_title;

/*----------------
 * Subjects
 *----------------*/

lv_subject_t stepper_status;
lv_subject_t load_str;
lv_subject_t driver_type;
lv_subject_t micro_steps;
lv_subject_t rotate_dir;
lv_subject_t rpm;
lv_subject_t vol;

/**********************
 *      MACROS
 **********************/

/**********************
 *   GLOBAL FUNCTIONS
 **********************/

void ui_helo_init_gen(const char * asset_path)
{
    char buf[256];


    /*----------------
     * Fonts
     *----------------*/

    /* get font 'misan_16' from a C array */
    misan_16 = &misan_16_data;
    /* get font 'font_medium_48' from a C array */
    font_medium_48 = &font_medium_48_data;
    /* get font 'font_medium' from a C array */
    font_medium = &font_medium_data;


    /*----------------
     * Images
     *----------------*/
    main_bg = &main_bg_data;
    mitem_bg = &mitem_bg_data;
    ic_info_30 = &ic_info_30_data;
    ic_more_24 = &ic_more_24_data;
    ic_motor_30 = &ic_motor_30_data;
    ic_setting_20 = &ic_setting_20_data;
    ic_stepper_30 = &ic_stepper_30_data;

    /*----------------
     * Global styles
     *----------------*/

    static bool style_inited = false;

    if (!style_inited) {
        lv_style_init(&section_title);
        lv_style_set_text_color(&section_title, SECTION_TITLE_TEXT);

        style_inited = true;
    }

    /*----------------
     * Subjects
     *----------------*/
    lv_subject_init_int(&stepper_status, 1);
    static char load_str_buf[UI_SUBJECT_STRING_LENGTH];
    static char load_str_prev_buf[UI_SUBJECT_STRING_LENGTH];
    lv_subject_init_string(&load_str,
                           load_str_buf,
                           load_str_prev_buf,
                           UI_SUBJECT_STRING_LENGTH,
                           "0.0 mA"
                          );
    lv_subject_init_int(&driver_type, 0);
    lv_subject_init_int(&micro_steps, 8);
    lv_subject_init_int(&rotate_dir, 0);
    lv_subject_init_float(&rpm, 0.0);
    lv_subject_init_float(&vol, 0.0);

    /*----------------
     * Translations
     *----------------*/

#if LV_USE_XML
    /* Register widgets */

    /* Register fonts */
    lv_xml_register_font(NULL, "misan_16", misan_16);
    lv_xml_register_font(NULL, "font_medium_48", font_medium_48);
    lv_xml_register_font(NULL, "font_medium", font_medium);

    /* Register subjects */
    lv_xml_register_subject(NULL, "stepper_status", &stepper_status);
    lv_xml_register_subject(NULL, "load_str", &load_str);
    lv_xml_register_subject(NULL, "driver_type", &driver_type);
    lv_xml_register_subject(NULL, "micro_steps", &micro_steps);
    lv_xml_register_subject(NULL, "rotate_dir", &rotate_dir);
    lv_xml_register_subject(NULL, "rpm", &rpm);
    lv_xml_register_subject(NULL, "vol", &vol);

    /* Register callbacks */
    lv_xml_register_event_cb(NULL, "on_menu_item_focus_changed", on_menu_item_focus_changed);
    lv_xml_register_event_cb(NULL, "on_screen_created", on_screen_created);
    lv_xml_register_event_cb(NULL, "on_stepper_ctrl_keyevent", on_stepper_ctrl_keyevent);
#endif

    /* Register all the global assets so that they won't be created again when globals.xml is parsed.
     * While running in the editor skip this step to update the preview when the XML changes */
#if LV_USE_XML && !defined(LV_EDITOR_PREVIEW)
    /* Register images */
    lv_xml_register_image(NULL, "main_bg", main_bg);
    lv_xml_register_image(NULL, "mitem_bg", mitem_bg);
    lv_xml_register_image(NULL, "ic_info_30", ic_info_30);
    lv_xml_register_image(NULL, "ic_more_24", ic_more_24);
    lv_xml_register_image(NULL, "ic_motor_30", ic_motor_30);
    lv_xml_register_image(NULL, "ic_setting_20", ic_setting_20);
    lv_xml_register_image(NULL, "ic_stepper_30", ic_stepper_30);
#endif

#if LV_USE_XML == 0
    /*--------------------
     *  Permanent screens
     *-------------------*/
    /* If XML is enabled it's assumed that the permanent screens are created
     * manaully from XML using lv_xml_create() */
#endif
}

/* Callbacks */
#if defined(LV_EDITOR_PREVIEW)
void __attribute__((weak)) on_menu_item_focus_changed(lv_event_t * e)
{
    LV_UNUSED(e);
    LV_LOG("on_menu_item_focus_changed was called\n");
}
void __attribute__((weak)) on_screen_created(lv_event_t * e)
{
    LV_UNUSED(e);
    LV_LOG("on_screen_created was called\n");
}
void __attribute__((weak)) on_stepper_ctrl_keyevent(lv_event_t * e)
{
    LV_UNUSED(e);
    LV_LOG("on_stepper_ctrl_keyevent was called\n");
}
#endif

/**********************
 *   STATIC FUNCTIONS
 **********************/