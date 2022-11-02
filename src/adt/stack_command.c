#include <stdlib.h>
#include "stack_command.h"

/*
 * Buat stack of state
 */
void create_stack(StackState *S, int capacity) {
    (*S).max_capacity = capacity;
    (*S).buffer = (state_t *) malloc((*S).max_capacity * sizeof(state_t));
    (*S).top = S_IDX_UNDEF;
}

/*
 * Periksa stack jika penuh
 */
boolean stack_is_full(StackState S) {
    return ((S).top + 1) == (S).max_capacity;
}

/*
 * Perbanyak alokasi memori stack
 */
void expand_stack(StackState *S) {
    (*S).max_capacity *= 10;
    (*S).buffer = (state_t *) realloc((*S).buffer, (*S).max_capacity * sizeof(state_t));
}

/*
 * Hapus stack
 */
void dealocate_stack(StackState *S) {
    (*S).max_capacity = 0;
    (*S).top = S_IDX_UNDEF;
    free((*S).buffer);
}

/*
 * Periksa apakah stack kosong
 */
boolean stack_is_empty(StackState S) {
    return (S.top == S_IDX_UNDEF);
}

/*
 * Push state ke stack
 */
void stack_push(StackState *S, state_t val) {
    if (stack_is_full(*S)) {
        expand_stack(S);
    }
    (*S).top += 1;
    (*S).buffer[(*S).top] = val;
}

/*
 * Pop state ke stack
 */
void stack_pop(StackState *S, state_t *val) {
    *val = (*S).buffer[(*S).top];
    (*S).top -= 1;
}