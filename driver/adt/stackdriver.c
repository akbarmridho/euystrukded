#include <stdio.h>
#include "../../src/adt/stack_command.h"

int main() {
    state_t dummy;
    create_list_food(&dummy.inventory, 10);
    create_point(&dummy.position, 0, 0);
    create_time(&dummy.time, 11, 0, 0);
    create_list_delivery(&dummy.delivery, 10);

    StackState S;

    create_stack(&S, 20);
    printf("is full eq to false %d\n", stack_is_full(S));

    stack_push(&S, dummy);

    printf("is empty eq to false %d\n", stack_is_empty(S));

    stack_pop(&S, &dummy);

    dealocate_stack(&S);
}