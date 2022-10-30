#include "delivery.h"

//simulator_t simulator;
//ListDelivery delivery;

/*
Kurangi waktu delivery pada delivery list sebanyak satu tick (menit)
panggil execute delivery
*/
void delivery_next_tick() {
    for (int i = 0; i < list_delivery_length(delivery); i++) {
        pprev_n_minute(&FOOD_DELIVERY_TIME(delivery.buffer[i]), 1);
    }

    int j = 0;

    while (j < list_delivery_length(delivery) && is_deltimefood_zero(ELMT(delivery, 0))) {
        execute_delivery();
        j++;
    }
}

/*
Kirim barang ke inventory
kirim notifikasi
barang yg dikirim adalah barang dengan delivery
time nol
*/
void execute_delivery() {
    food_t food;
    dequeue_delivery(&delivery, &food);

    enqueue_food(&simulator.inventory, food);

    char base[] = "Makanan ";
    char end[] = " telah sampai";


    notify(concat(concat(char_to_string(base), FOOD_NAME(food)), char_to_string(end)));
}

/* Mengembalikan true apabila delivery time dari suatu makanan adalah 0 */
boolean is_deltimefood_zero(food_t food) {
    return time_to_minute(FOOD_DELIVERY_TIME(food)) == 0;
}

/* menambahkan food ke list delivery */
void add_to_delivery_list(food_t purchased) {
    enqueue_delivery(&delivery, purchased);
}