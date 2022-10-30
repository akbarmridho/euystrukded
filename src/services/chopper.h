#ifndef SERVICE_CHOPPER_H
#define SERVICE_CHOPPER_H

#include "clock.h"
#include "../data/simulator.h"
#include "../data/configdata.h"
#include "../adt/boolean.h"
#include "../adt/tree.h"

extern simulator_t simulator;
extern ListFoodRecipe food_recipe;
extern ListTree list_tree_recipe;

/*
 * CHOPPER CHECK
 * mengecek apakah bahan baku tersedia untuk melakukan proses chop
 */
boolean can_chop_food(int result_id, Tree recipe_tree);

/*
 * CHOPPER SERVICE (procedure chop())
 * dipanggil apabila bahan mencukupi
 * proses:
 * ambil bahan dari inventory (dequeue)
 * panggil ticker
 * enqueue hasil ke inventory
*/
void chop(int result_id, Tree recipe_tree);

#endif