#include "string.h"
#include "point.h"
#include "food.h"
#include "list_food.h"
#include "notification.h"
#include "simulator.h"


/* ------------KONSTRUKTOR------------ */

/* I.S. simulator sembarang
   F.S. simlator terdefinisi, dengan nama pengguna dan lokasi simulator serta inventory makanan tersimpan di dalam simulator*/
void create_simulator(simulator_t *sim, string name) {
    new_string(&name, MAX);
    create_point(&position(*sim), 0, 0);
    create_time(&time(*sim), 0, 0, 0);
    create_notification(&notification(*sim));
    create_list_food(&inventory(*sim), 50);

}