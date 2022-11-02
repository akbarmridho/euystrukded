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

    string prefix = char_to_string("Makanan ");
    string postfix = char_to_string(" telah sampai");
    string postfixCancel = char_to_string(" tidak jadi sampai");

    string withPrefix = concat(prefix, FOOD_NAME(food));
    string message = concat(withPrefix, postfix);
    notify(message);
    string messageUndo = concat(withPrefix, postfixCancel);
    notify_undo(messageUndo);

    deallocate_string(&prefix);
    deallocate_string(&postfix);
    deallocate_string(&withPrefix);
    deallocate_string(&postfixCancel);
}

/* Mengembalikan true apabila delivery time dari suatu makanan adalah 0 */
boolean is_deltimefood_zero(food_t food) {
    return time_to_minute(FOOD_DELIVERY_TIME(food)) == 0;
}

/* menambahkan food ke list delivery */
void add_to_delivery_list(food_t purchased) {
    enqueue_delivery(&delivery, purchased);
}