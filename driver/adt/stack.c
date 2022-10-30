#include <stdio.h>
#include "../../src/adt/stack_command.h"
#include "../../src/adt/point.h"
#include "../../src/adt/time.h"
#include "../../src/adt/list_delivery.h"

//gcc stack.c ../../src/adt/stack_command.c ../../src/adt/point.c ../../src/adt/time.c ../../src/adt/list_delivery.c -o a

int main(){
    state_t dummy;
    create_list_food(&dummy.inventory, 10);
    create_point(&dummy.position, 0, 0);
    create_time(&dummy.time, 11, 0, 0);
    create_list_delivery(&dummy.delivery, 10);
    StackState S;
    create_stack(&S, 20);
    printf("%d\n", stack_is_full(S));
    printf("%d\n", stack_is_empty(S));
    stack_push(&S, dummy);
    stack_pop(&S, &dummy);
    dealocate_stack(&S);
}