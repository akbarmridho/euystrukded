#ifndef COMMAND_BUY_h
#define COMMAND_BUY_h

#include <stdio.h>
#include "../services/delivery.h"
#include "../utils/validator.h"
#include "../data/simulator.h"
#include "../data/configdata.h"

extern simulator_t simulator;
extern ListFoodRecipe food_recipe;

/* command buy */
void cmd_buy();

#endif