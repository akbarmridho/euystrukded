#include <stdio.h>
#include "string.h"
#include "point.h"
#include "list_food.h"
#include "notification.h"
#include "simulator.h"

/* ------------KONSTRUKTOR------------ */

/* I.S. simulator sembarang
   F.S. simlator terdefinisi, dengan nama pengguna dan lokasi simulator serta inventory makanan tersimpan di dalam simulator*/
void create_simulator (simulator_t *sim) {
    ListFood l;
    time_t t;

    new_string(&(name(*sim)));
    create_point(point(*sim),0,0);
    // create_food()
    create_time(&t,0,0,0);
    create_notification(&notification(*sim));
    create_list_food(&l, CAPACITY);

}

// /* ------------PRIMITIF LAIN------------ */
// void simulator_move(simulator_t sim, string arah);
// /* I.S. posisi dari BNMO terdefinisi
//    F.S. posisi BNMO berubah*/

// void simulator_do(simulator_t sim, string command);
// /* I.S. simulator terdefinisi 
//    F.S. menerima command type string dan melakukan command tersebut */

// boolean is_there_place(simulator_t sim);
// /* Mengecek apakah ada jenis di sekitar BNMO */

// boolean is_there_tembok(simulator_t sim);
// /* Mengecek apakah ada tembok di sekitar BNMO */
// /* Jika ada, dan jika BNMO diberi command untuk menuju ke tembok
//    maka BNMO tidak bergerak */

// boolean cannot_move(simulator_t sim);
// /* Mengembalikan true apabila simulator menabrak tembok atau tempat */