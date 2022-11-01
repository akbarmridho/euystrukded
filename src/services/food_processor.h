#ifndef SERVICE_FOOD_PROCESSOR_h
#define SERVICE_FOOD_PROCESSOR_h

#include "clock.h"
#include "../data/simulator.h"
#include "../data/configdata.h"
#include "../adt/boolean.h"
#include "../adt/tree.h"

/*
 * FOOD PROCESSOR CHECK
 * mengecek apakah bahan baku tersedia untuk melakukan pemrosesan makanan {FRY|MIX|BOIL|CHOP}
 */
boolean can_process_food(Tree recipe_tree);

/*
 * FOOD PROCESSOR SERVICE
 * dipanggil apabila bahan untuk melakukan pemrosesan makanan mencukupi
 * proses:
 * ambil bahan dari inventory (dequeue)
 * panggil ticker
 * enqueue hasil ke inventory
*/
boolean process_food(Tree recipe_tree);

#endif