#include <stdlib.h>
#include "stack_command.h"


void create_stack(StackState *S, int capacity) {
    (*S).max_capacity = capacity;
    (*S).buffer = (state_t *) malloc((*S).max_capacity * sizeof(state_t));
    (*S).top = IDX_UNDEF;
}

boolean stack_is_full(StackState S) {
    return ((S).top) == (S).max_capacity;
}

void expand_stack(StackState *S) {
    (*S).max_capacity *= 2;
    (*S).buffer = (state_t *) realloc((*S).buffer, (*S).max_capacity * sizeof(state_t));
}

void dealocate_stack(StackState *S) {
    (*S).max_capacity = 0;
    (*S).top = IDX_UNDEF;
    free((*S).buffer);
}

boolean stack_is_empty(StackState S) {
    return (S.top == IDX_UNDEF);
}

void stack_push(StackState *S, state_t val) {
    if (stack_is_full(*S)) {
        expand_stack(S);
    }
    (*S).top += 1;
    (*S).buffer[(*S).top] = val;
}

void stack_pop(StackState *S, state_t *val) {
    *val = (*S).buffer[(*S).top];
    (*S).top -= 1;
}