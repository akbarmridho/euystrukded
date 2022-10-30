#ifndef COMMAND_MIX_h
#define COMMAND_MIX_h

#include <stdio.h>
#include "..\services\mixer.h"
#include "..\utils\validator.h"

extern simulator_t simulator;
extern ListFoodRecipe food_recipe;
extern ListTree list_tree_recipe;

void do_mix();

#endif