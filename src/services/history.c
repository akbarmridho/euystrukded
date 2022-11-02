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

    // notifikasi kosong
    ListNotification notification;
    copy_notification(simulator.notification, &notification);

    state_t backup;

    backup.delivery = delivery_copy;
    backup.time = simulator.time;
    backup.position = simulator.position;
    backup.inventory = inventory_copy;
    backup.notification = notification;

    return backup;
}

void set_state(state_t state) {
    simulator.inventory.capacity = state.inventory.capacity;
    simulator.inventory.nEff = state.inventory.nEff;
    simulator.inventory.buffer = state.inventory.buffer;

    simulator.notification = state.notification;
//    simulator.notification.length = state.notification.length;
//    simulator.notification.notifications = state.notification.notifications;

    simulator.time = state.time;
    simulator.position = state.position;

    delivery.capacity = state.delivery.capacity;
    delivery.nEff = state.delivery.nEff;
    delivery.buffer = state.delivery.buffer;
}

void backup_state() {
    state_t backup = generate_state();
    clear_notification();
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