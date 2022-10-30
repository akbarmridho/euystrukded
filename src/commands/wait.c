#include "../services/clock.h"
#include "wait.h"

void wait(int x, int y) {
    backup_state();
    for (int i = 0; i < y + x * 60; i++) {
        next_tick();
    }
}