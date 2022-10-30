#ifndef SERVICE_BOILER_H
#define SERVICE_BOILER_H

#include "clock.h"
#include "../data/simulator.h"
#include "../adt/boolean.h"
#include "../adt/tree.h"

/*
 * BOILER CHECK
 * mengecek apakah bahan baku tersedia untuk melakukan proses boil
 */
boolean can_boil_food(Tree recipe_tree);

/*
 * BOILER SERVICE (procedure boil())
 * dipanggil apabila bahan mencukupi
 * proses:
 * ambil bahan dari inventory (dequeue)
 * panggil ticker
 * enqueue hasil ke inventory
*/
void boil(Tree recipe_tree);

#endif