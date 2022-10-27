#ifndef ADT_SIMULATOR_H
#define ADT_SIMULATOR_H

#include "string.h"
#include "point.h"
#include "list_food.h"
#include "notification.h"

typedef struct
{
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
void create_simulator (simulator_t *sim);
/* I.S. simulator sembarang
   F.S. simlator terdefinisi, dengan nama pengguna dan lokasi simulator serta inventory makanan tersimpan di dalam simulator*/

/* ------------PRIMITIF LAIN------------ */
void simulator_move(simulator_t sim, string arah);
/* I.S. posisi dari BNMO terdefinisi
   F.S. posisi BNMO berubah*/

void simulator_do(simulator_t sim, string command);
/* I.S. simulator terdefinisi 
   F.S. menerima command type string dan melakukan command tersebut */

boolean is_there_place(simulator_t sim);
/* Mengecek apakah ada jenis di sekitar BNMO */

boolean is_there_tembok(simulator_t sim);
/* Mengecek apakah ada tembok di sekitar BNMO */
/* Jika ada, dan jika BNMO diberi command untuk menuju ke tembok
   maka BNMO tidak bergerak */

boolean cannot_move(simulator_t sim);
/* Mengembalikan true apabila simulator menabrak tembok atau tempat */
#endif