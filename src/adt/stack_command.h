#ifndef ADT_STACK_COMMAND_H
#define ADT_STACK_COMMAND_H

#include "list_food.h"
#include "list_delivery.h"
#include "point.h"
#include "time.h"
#include "notification.h"

typedef struct
{
    ListFood inventory;
    point_t position;
    day_time_t time;
    ListDelivery delivery;
    ListNotification notification;
} state_t;

typedef struct
{
    state_t *buffer; /* tabel penyimpan elemen */
    int capacity;
    int top; /* alamat TOP: elemen puncak */
} StackState;

/*
Sisanya implementasi sendiri :)

stack menggunakan pendekatan list dinamis
sehingga setidaknya memiliki fungsi
push, pop, expand list
*/

#endif