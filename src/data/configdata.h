#ifndef DATA_CONFIG_DATA_H
#define DATA_CONFIG_DATA_H

#include "../adt/list_food_recipe.h"
#include "../adt/matrix.h"

extern ListFoodRecipe food_recipe;
extern Matrix map;

void load_map();

void load_food_recipe();

#endif


// global variable
// load data folder config

// buat list food recipe
// buat list tree recipe
// variable list food recipe dan list of tree recipe disimpan sebagai global variable menggunakan extern