#ifndef DATA_CONFIG_DATA_H
#define DATA_CONFIG_DATA_H

#include "../adt/list_food_recipe.h"
#include "../adt/matrix.h"
#include "../adt/tree.h"
#include "../adt/list_food.h"
#include "../adt/recipe.h"
#include "../adt/string.h"
#include "../adt/list_delivery.h"
#include "../adt/food.h"
#include "../adt/simulator.h"
#include "../adt/parsermachine.h"
#include "../utils/parser.h"

extern ListFoodRecipe food_recipe;
extern Matrix map;
extern ListTree list_tree_recipe;

extern boolean DEBUG;
extern boolean CONFIG_DEBUG;

void load_map(char *path);

void load_food_recipe(char *path_food, char *path_recipe);

void build_tree_recipe();

#endif


// global variable
// load data folder config

// buat list food recipe
// buat list tree recipe
// variable list food recipe dan list of tree recipe disimpan sebagai global variable menggunakan extern