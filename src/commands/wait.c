#include "../services/clock.h"
#include "wait.h"

void wait(int hour, int minute) {
    backup_state();
    for (int i = 0; i < minute + hour * 60; i++) {
        next_tick();
    }

    clear_display();
    display_info();
    printf("Enter command: ");
}