#include "my_radio.h"

typedef struct {
    lv_obj_t obj;
    lv_obj_t *selected;
} my_radio_t;

typedef struct {
    lv_obj_t obj;
} my_radio_item_t;

static void my_radio_constructor(const lv_obj_class_t *class_p, lv_obj_t *obj);
static void my_radio_item_constructor(const lv_obj_class_t *class_p, lv_obj_t *obj);
static void item_event_cb(lv_event_t *e);

static const lv_obj_class_t my_radio_class = {
    .base_class = &lv_obj_class,
    .constructor_cb = my_radio_constructor,
    .instance_size = sizeof(my_radio_t),
};

static const lv_obj_class_t my_radio_item_class = {
    .base_class = &lv_obj_class,
    .constructor_cb = my_radio_item_constructor,
    .instance_size = sizeof(my_radio_item_t),
};

lv_obj_t *my_radio_create(lv_obj_t *parent) {
    lv_obj_t *obj = lv_obj_class_create_obj(&my_radio_class, parent);
    return obj;
}

lv_obj_t *my_radio_add_item(lv_obj_t *parent, const char *text) {
    lv_obj_t *item = lv_obj_class_create_obj(&my_radio_item_class, parent);

    lv_obj_t *label = lv_label_create(item);
    lv_label_set_text(label, text);
    lv_obj_center(label);

    lv_obj_add_event_cb(item, item_event_cb, LV_EVENT_CLICKED, NULL);
    lv_obj_add_event_cb(item, item_event_cb, LV_EVENT_FOCUSED, NULL);

    return item;
}

static void my_radio_constructor(const lv_obj_class_t *class_p, lv_obj_t *obj) {
    LV_UNUSED(class_p);
    my_radio_t *root = (my_radio_t *)obj;

    lv_obj_set_flex_flow(obj, LV_FLEX_FLOW_ROW);
    lv_obj_set_flex_align(obj,
        LV_FLEX_ALIGN_CENTER,
        LV_FLEX_ALIGN_CENTER,
        LV_FLEX_ALIGN_CENTER
    );

    lv_obj_set_style_flex_grow(obj, 1, LV_PART_MAIN | LV_STATE_DEFAULT);
    root->selected = NULL;
}

static void my_radio_item_constructor(const lv_obj_class_t *class_p, lv_obj_t *obj) {
    LV_UNUSED(class_p);

    lv_obj_set_size(obj, LV_SIZE_CONTENT, LV_SIZE_CONTENT);
    lv_obj_set_style_flex_grow(obj, 1, 0);
    lv_obj_set_style_radius(obj, 4, 0);
    lv_obj_set_style_pad_all(obj, 8, 0);
    lv_obj_set_style_border_width(obj, 1, 0);
    lv_obj_set_style_border_color(obj, lv_color_hex(0x888888), 0);

    lv_obj_set_style_bg_color(obj, lv_color_hex(0x0078D7), LV_STATE_CHECKED);
    lv_obj_set_style_text_color(obj, lv_color_white(), LV_STATE_CHECKED);

    lv_obj_set_style_border_color(obj, lv_color_hex(0xFFD700), LV_STATE_FOCUSED);
    lv_obj_set_style_border_width(obj, 2, LV_STATE_FOCUSED);
}

static void item_event_cb(lv_event_t *e) {
    lv_obj_t *item = lv_event_get_target(e);
    lv_obj_t *radio = lv_obj_get_parent(item);
    my_radio_t *root = (my_radio_t *)radio;

    if (lv_event_get_code(e) == LV_EVENT_CLICKED) {
        if (root->selected) {
            lv_obj_clear_state(root->selected, LV_STATE_CHECKED);
        }
        lv_obj_add_state(item, LV_STATE_CHECKED);
        root->selected = item;
    }
}

lv_obj_t *my_radio_get_selected(lv_obj_t *radio) {
    return ((my_radio_t *)radio)->selected;
}