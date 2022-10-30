#include "clock.h"
#include "../data/simulator.h"
#include "../data/configdata.h"
#include "../adt/boolean.h"
#include "../adt/tree.h"

extern simulator_t simulator;
extern ListFoodRecipe food_recipe;
extern ListTree list_tree_recipe;


/*
 * FRYER CHECK
 * mengecek apakah bahan baku tersedia untuk melakukan proses fry
 */
boolean can_fry_food(Tree recipe_tree);

/*
 * FRYER SERVICE (procedure fry())
 * dipanggil apabila bahan mencukupi
 * proses:
 * ambil bahan dari inventory (dequeue)
 * panggil ticker
 * enqueue hasil ke inventory
*/
boolean fry(Tree recipe_tree);