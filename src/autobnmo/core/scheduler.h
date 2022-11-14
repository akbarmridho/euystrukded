#ifndef AUTOBNMO_CORE_SCHEDULER_H
#define AUTOBNMO_CORE_SCHEDULER_H

#include "action_list.h"
#include "writer.h"
#include "../../adt/tree.h"
#include "../../data/configdata.h"
#include "../../data/simulator.h"

void tranverse_tree(list_action_t *list, Tree t, int depth, action_t *parent);

void schedule(int target_food_id);

void group_list_action(list_of_action_list_t *list, list_action_t action_list);

void create_action_priority(list_action_t *list, int target);


#endif
