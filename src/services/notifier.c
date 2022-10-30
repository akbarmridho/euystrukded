#include "notifier.h"

//simulator_t simulator;

void notify(string notification) {
    n_insert_last(&simulator.notification, notification);
}

void clear_notification() {
    n_delete_list(&simulator.notification);
}

void display_notification() {
    if (n_list_length(simulator.notification) == 0) {
        printf("Notifikasi: -\n");
    } else {
        printf("Notifikasi:\n");
        for (int i = 0; i < n_list_length(simulator.notification); i++) {
            printf("    %d. ", i + 1);
            print_string(notif(simulator.notification, i));
            putchar('\n');
        }
    }
}
