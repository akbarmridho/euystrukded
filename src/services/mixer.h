#ifndef SERVICE_MIXER_H
#define SERVICE_MIXER_H

#include "clock.h"
#include "../data/simulator.h"
#include "../data/configdata.h"
#include "../adt/boolean.h"
#include "../adt/tree.h"


/*
 * MIXER CHECK
 * mengecek apakah bahan baku tersedia untuk melakukan proses mix
 */
boolean can_mix_food(Tree recipe_tree);

/*
 * MIXER SERVICE (procedure mix())
 * dipanggil apabila bahan mencukupi
 * proses:
 * ambil bahan dari inventory (dequeue)
 * panggil ticker
 * enqueue hasil ke inventory
*/
boolean mix(Tree recipe_tree);

#endif