#include "history.h"

simulator_t simulator;
StackState history;
StackState restore;
ListDelivery delivery;

state_t generate_state() {
    // copy inventory
    ListFood inventory_copy;
    list_food_copy(simulator.inventory, &inventory_copy);

    // copy position
    point_t point_copy;
    create_point(&point_copy, simulator.position.x, simulator.position.y);

    // copy time
    day_time_t dt_copy;
    create_time(&dt_copy, simulator.time.dd, simulator.time.hh, simulator.time.mm);

    // copy list delivery
    ListDelivery delivery_copy;
    list_delivery_copy(delivery, &delivery_copy);

    // copy notification
    ListNotification notification_copy;
    copy_notification(simulator.notification, &notification_copy);

    state_t backup;

    backup.notification = notification_copy;
    backup.delivery = delivery_copy;
    backup.time = dt_copy;
    backup.position = point_copy;
    backup.inventory = inventory_copy;

    return backup;
}

void set_state(state_t state) {
    list_food_copy(state.inventory, &simulator.inventory);
    create_point(&simulator.position, state.position.x, state.position.y);
    create_time(&simulator.time, state.time.dd, state.time.hh, state.time.mm);
    list_delivery_copy(state.delivery, &delivery);
    copy_notification(state.notification, &simulator.notification);
}

void backup_state() {
    state_t backup = generate_state();
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