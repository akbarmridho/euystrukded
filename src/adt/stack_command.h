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
/* chore: backup refrigerator state*/

typedef struct {
    state_t *buffer; /* tabel penyimpan elemen */
    int max_capacity;
    int top; /* alamat TOP: elemen puncak */
} StackState;

#define S_IDX_UNDEF (-1)

/*
 * Buat stack of state
 */
void create_stack(StackState *S, int capacity);

/*
 * Periksa stack jika penuh
 */
boolean stack_is_full(StackState S);

/*
 * Perbanyak alokasi memori stack
 */
void expand_stack(StackState *S);

/*
 * Hapus stack
 */
void dealocate_stack(StackState *S);

/*
 * Periksa apakah stack kosong
 */
boolean stack_is_empty(StackState S);

/*
 * Push state ke stack
 */
void stack_push(StackState *S, state_t val);

/*
 * Pop state ke stack
 */
void stack_pop(StackState *S, state_t *val);

#endif