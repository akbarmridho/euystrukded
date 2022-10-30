#ifndef SERVICE_DELIVERY_H
#define SERVICE_DELIVERY_H

#include "../adt/boolean.h"
#include "../adt/time.h"
#include "../adt/notification.h"
#include "../commands/inventory.h"
#include "../adt/list_food.h"
#include "../adt/list_delivery.h"
#include "../adt/food.h"
#include "notifier.h"
#include "../data/delivery.h"
// terdapat delivery queue

extern ListDelivery delivery;

/*
Kurangi waktu delivery pada delivery list sebanyak satu tick (menit)
panggil execute delivery
*/
void delivery_next_tick();

/*
Kirim barang ke inventory
kirim notifikasi
barang yg dikirim adalah barang dengan delivery
time nol
*/
void execute_delivery();

/* Mengembalikan true apabila delivery time dari suatu makanan adalah 0 */
boolean is_deltimefood_zero(food_t food);

/* menambahkan food ke list delivery */
void add_to_delivery_list(food_t food);

#endif