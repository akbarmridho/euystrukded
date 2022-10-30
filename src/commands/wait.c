#include "../services/clock.h"

void wait(int x, int y) {
    for (int i = 0; i < y + x * 60; i++) {
        next_tick();
    }
}