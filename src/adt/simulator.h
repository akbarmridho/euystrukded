#ifndef ADT_SIMULATOR_H
#define ADT_SIMULATOR_H

#include "string.h"
#include "point.h"
#include "time.h"
#include "list_food.h"
#include "notification.h"

typedef struct {
    string name;
    point_t position;
    day_time_t time;
    ListFood inventory;
    ListNotification notification;
} simulator_t;

#define name(sim) (sim).name
#define position(sim) (sim).position
#define time(sim) (sim).time
#define inventory(sim) (sim).inventory
#define notification(sim) (sim).notification


/*
fungsi yang diperlukan????
create simumlator, dll
*/

/* ------------KONSTRUKTOR------------ */

/* I.S. simulator sembarang
   F.S. simlator terdefinisi, dengan nama pengguna dan lokasi simulator serta inventory makanan tersimpan di dalam simulator*/
void create_simulator(simulator_t *sim, string name);

#endif