#ifndef SERVICE_BOILER_H
#define SERVICE_BOILER_H

#include "clock.h"
#include "../data/simulator.h"
#include "../data/configdata.h"
#include "../adt/boolean.h"

extern simulator_t simulator;
extern ListFoodRecipe food_recipe;

/*
 * BOILER CHECK
 * mengecek apakah bahan baku tersedia untuk melakukan proses boil
 */
boolean can_boil_food(int result_id);

/*
 * BOILER SERVICE (procedure boil())
 * dipanggil apabila bahan mencukupi
 * proses:
 * ambil bahan dari inventory (dequeue)
 * panggil ticker
 * enqueue hasil ke inventory
*/
void boil(int result_id);
#endif