#ifndef ADT_STACK_COMMAND_H
#define ADT_STACK_COMMAND_H

#include "list_food.h"
#include "list_delivery.h"
#include "point.h"
#include "time.h"
#include "notification.h"
#include "boolean.h"

typedef struct {
    ListFood inventory;
    point_t position;
    day_time_t time;
    ListDelivery delivery;
    ListNotification notification;
} state_t;

typedef struct {
    state_t *buffer; /* tabel penyimpan elemen */
    int max_capacity;
    int top; /* alamat TOP: elemen puncak */
} StackState;

#define S_IDX_UNDEF (-1)

/*
Sisanya implementasi sendiri :)

stack menggunakan pendekatan list dinamis
sehingga setidaknya memiliki fungsi
push, pop, expand list
*/

void create_stack(StackState *S, int capacity);

boolean stack_is_full(StackState S);

void expand_stack(StackState *S);

void dealocate_stack(StackState *S);

boolean stack_is_empty(StackState S);

void stack_push(StackState *S, state_t val);

void stack_pop(StackState *S, state_t *val);

#endif