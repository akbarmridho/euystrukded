#include "action_list.h"

void create_list_action(list_action_t *list) {
    list->length = 0;
}

void insert_list_action(list_action_t *list, action_t *action) {
    (*list).contents[list->length] = action;
    list->length = list->length + 1;
}

void delete_list_action(list_action_t *list, int index) {
    if (list->length - 1 == index) {
        list->length = list->length - 1;
    } else {
//        free(list->contents[index]);
        for (int i = index; i < list->length - 1; i++) {
            list->contents[i] = list->contents[i + 1];
        }
        list->length = list->length - 1;
    }
}

void create_list_of_list_action(list_of_action_list_t *list) {
    list->length = 0;
}

void insert_list_of_list_action(list_of_action_list_t *list, list_action_t action) {
    (*list).contents[list->length] = action;
    list->length = list->length + 1;
}

void delete_list_of_list_action(list_of_action_list_t *list, int index) {
    if (list->length - 1 == index) {
        list->length = list->length - 1;
    } else {
//        free(list->contents[index]);
        for (int i = index; i < list->length - 1; i++) {
            list->contents[index] = list->contents[index + 1];
        }
        list->length = list->length - 1;
    }
}