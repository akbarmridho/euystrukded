#ifndef COMMAND_FRY_h
#define COMMAND_FRY_h

#include <stdio.h>
#include "..\services\fryer.h"
#include "..\utils\validator.h"

extern simulator_t simulator;
extern ListFoodRecipe food_recipe;
extern ListTree list_tree_recipe;

void do_fry();

#endif