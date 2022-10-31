#include "history.h"

//StackState history;
//StackState restore;

state_t generate_state() {
    // copy inventory
    ListFood inventory_copy;
    list_food_copy(simulator.inventory, &inventory_copy);

    // copy list delivery
    ListDelivery delivery_copy;
    list_delivery_copy(delivery, &delivery_copy);

    state_t backup;

    backup.delivery = delivery_copy;
    backup.time = simulator.time;
    backup.position = simulator.position;
    backup.inventory = inventory_copy;

    return backup;
}

void set_state(state_t state) {
    list_food_copy(state.inventory, &simulator.inventory);
    simulator.time = state.time;
    simulator.position = state.position;
    list_delivery_copy(state.delivery, &delivery);
}

void backup_state() {
    state_t backup = generate_state();
    printf("before stack push\n");
    stack_push(&history, backup);

    state_t dump;
    // kosongkan restore stack
    while (!stack_is_empty(restore)) {
        stack_pop(&restore, &dump);
    }
}

void restore_state() {
    state_t prev_state;
    state_t current_state = generate_state();

    stack_pop(&history, &prev_state);
    stack_push(&restore, current_state);

    set_state(prev_state);
}

void restore_backup_state() {
    state_t next_state;
    stack_pop(&restore, &next_state);

    state_t current_state = generate_state();
    stack_push(&history, current_state);

    set_state(next_state);
}

boolean is_able_to_restore() {
    return !stack_is_empty(history);
}

boolean is_able_to_restore_backup() {
    return !stack_is_empty(restore);
}