#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "stack_command.h"


void create_stack(StackState *S, int capacity){
    (*S).max_capacity= capacity;
    (*S).buffer= (state_t * ) malloc ((*S).max_capacity * sizeof(state_t));
    (*S).top= IDX_UNDEF;
}

boolean isFull(StackState S){
    return ((S).top) == (S).max_capacity;
}

void expand_stack(StackState * S){
    (*S).max_capacity *= 2;
    (*S).buffer= (state_t *) realloc ((*S).buffer, (*S).max_capacity * sizeof(state_t));
}

void dealocate_stack(StackState * S){
    (*S).max_capacity = 0;
    (*S).top= IDX_UNDEF;
    free((*S).buffer);
}

boolean isEmpty(StackState S){
    return (S.top == IDX_UNDEF);
}

void push(StackState *S, state_t val){
    if(isFull(*S)){
        expand_stack(S);
    }
    (*S).top +=1;
    (*S).buffer[(*S).top] = val;
}

void pop(StackState * S, state_t * val){
    *val = (*S).buffer[(*S).top];
    (*S).top -=1;
}