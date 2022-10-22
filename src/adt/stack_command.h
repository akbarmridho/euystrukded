#ifndef __STACK_COMMAND_H
#define __STACK_COMMAND_H

#include "list_food.h"
#include "list_delivery.h"
#include "point.h"
#include "time.h"
#include "notification.h"

typedef struct
{
    ListFood inventory;
    point_t position;
    time_t time;
    ListDelivery delivery;
    ListNotification notification;
} state_t;

typedef int state_t;

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