#include <stdio.h>
#include "delivery.h"
#include "../adt/boolean.h"
#include "../adt/time.h"
#include "../adt/notification.h"
#include "../commands/inventory.h"

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
void execute_delivery() {
    
}