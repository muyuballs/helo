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

lv_font_t * font_medium_48;
extern lv_font_t font_medium_48_data;
lv_font_t * font_medium;
extern lv_font_t font_medium_data;

/*----------------
 * Images
 *----------------*/

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

    /* get font 'font_medium_48' from a C array */
    font_medium_48 = &font_medium_48_data;
    /* get font 'font_medium' from a C array */
    font_medium = &font_medium_data;


    /*----------------
     * Images
     *----------------*/
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
#endif

    /* Register all the global assets so that they won't be created again when globals.xml is parsed.
     * While running in the editor skip this step to update the preview when the XML changes */
#if LV_USE_XML && !defined(LV_EDITOR_PREVIEW)
    /* Register images */
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

/**********************
 *   STATIC FUNCTIONS
 **********************/