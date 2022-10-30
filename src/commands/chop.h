#ifndef COMMAND_CHOP_h
#define COMMAND_CHOP_h

#include <stdio.h>
#include "..\services\chopper.h"
#include "..\utils\validator.h"

extern simulator_t simulator;
extern ListFoodRecipe food_recipe;
extern ListTree list_tree_recipe;

void do_chop();

#endif