#include <stdio.h>
#include "delivery.h"
#include "../adt/boolean.h"
#include "../adt/time.h"
#include "../adt/notification.h"
#include "../commands/inventory.h"
#include "../adt/list_food.h"
#include "../adt/list_delivery.h"
#include "../adt/food.h"
#include "notifier.h"
#include "../data/delivery.h"
#include "../data/simulator.h"

ListDelivery delivery;
simulator_t simulator;

/*
Kurangi waktu delivery pada delivery list sebanyak satu tick (menit)
panggil execute delivery
*/
void delivery_next_tick() {
    int i = 0;
    for (i = 0; i < list_delivery_length; i++) {
        pprev_n_minute(&DELIVERY_TIME(ELMT(simulator.inventory,i)), 1);

        if (is_deltimefood_zero(ELMT(simulator.inventory,i))) {
            execute_delivery(ELMT(simulator.inventory,i)); 
        }
    }
}

/*
Kirim barang ke inventory
kirim notifikasi
barang yg dikirim adalah barang dengan delivery
time nol
*/
void execute_delivery(food_t food) {
    enqueue(&simulator.inventory, food);
    dequeue_delivery(&delivery, &food);
    notify(NAME(food));
}

/* Mengembalikan true apabila delivery time dari suatu makanan adalah 0 */
boolean is_deltimefood_zero(food_t food) {
    return (&DELIVERY_TIME(food) == 0);
}