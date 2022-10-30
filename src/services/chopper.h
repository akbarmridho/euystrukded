#ifndef SERVICE_CHOPPER_H
#define SERVICE_CHOPPER_H

#include "clock.h"
#include "../data/simulator.h"
#include "../adt/boolean.h"
#include "../adt/tree.h"

/*
 * CHOPPER CHECK
 * mengecek apakah bahan baku tersedia untuk melakukan proses chop
 */
boolean can_chop_food(Tree recipe_tree);

/*
 * CHOPPER SERVICE (procedure chop())
 * dipanggil apabila bahan mencukupi
 * proses:
 * ambil bahan dari inventory (dequeue)
 * panggil ticker
 * enqueue hasil ke inventory
*/
void chop(Tree recipe_tree);

#endif