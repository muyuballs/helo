#ifndef MY_RADIO_H
#define MY_RADIO_H

#ifdef __cplusplus
extern "C" {
#endif

#include "lvgl.h"

lv_obj_t *my_radio_create(lv_obj_t *parent);
lv_obj_t *my_radio_add_item(lv_obj_t *my_radio, const char *text);
lv_obj_t *my_radio_get_selected(lv_obj_t *my_radio);

#ifdef __cplusplus
}
#endif

#endif