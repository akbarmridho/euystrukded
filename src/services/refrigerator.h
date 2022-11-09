#ifndef SERVICES_REFRIGERATOR_H
#define SERVICES_REFRIGERATOR_H

#include "../data/simulator.h"
#include "../adt/boolean.h"
#include "../adt/list_food.h"
#include "../data/refrigerator.h"
#include "../data/configdata.h"

ListFoodRecipe food_recipe;
simulator_t simulator;
Matrix refrigerator

void store_item_refrigerator();

boolean is_refrigerator_full();

void get_item_refrigerator();

void display_refrigerator();

#endif