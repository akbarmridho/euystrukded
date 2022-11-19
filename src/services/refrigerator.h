#ifndef SERVICES_REFRIGERATOR_H
#define SERVICES_REFRIGERATOR_H

#include "../adt/boolean.h"
#include "../adt/list_food.h"
#include "../data/refrigerator.h"
#include "../data/configdata.h"
#include "simulator.h"

void store_item_refrigerator(food_t item, point_t loc);//service

void retract_item_refrigerator(food_t item);

#endif