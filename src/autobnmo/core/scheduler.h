#ifndef AUTOBNMO_CORE_SCHEDULER_H
#define AUTOBNMO_CORE_SCHEDULER_H

#include "action_list.h"
#include "../../adt/tree.h"
#include "../../data/configdata.h"
#include "../../data/simulator.h"

void tranverse_tree(list_action_t *list, Tree t, int depth, action_t *parent);

#endif
