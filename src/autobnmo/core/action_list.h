#ifndef AUTOBNMO_CORE_ACTION_LIST_H
#define AUTOBNMO_CORE_ACTION_LIST_H

#define MAX_ACTION 200
#define MAX_DEPTH 10

#include <stdlib.h>
#include "../../adt/boolean.h"
#include "../../adt/list_food_recipe.h"

typedef struct action {
    food_t food;
    int priority;
    int unmet_prereq_count;
    struct action *parent;
} action_t;

typedef struct list_action {
    action_t *contents[MAX_ACTION];
    int length;
} list_action_t;

typedef struct list_of_action_list {
    list_action_t contents[MAX_DEPTH];
    int length;
} list_of_action_list_t;

void create_list_action(list_action_t *list);

void insert_list_action(list_action_t *list, action_t *action);

void delete_list_action(list_action_t *list, int index);

void create_list_of_list_action(list_of_action_list_t *list);

void insert_list_of_list_action(list_of_action_list_t *list, list_action_t action);

void delete_list_of_list_action(list_of_action_list_t *list, int index);

#endif
