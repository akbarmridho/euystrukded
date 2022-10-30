#include <stdio.h>
#include <stdlib.h>
#include "../data/simulator.h"
#include "../services/clock.h"

extern simulator_t simulator;

void wait(int x, int y) {
    int i = 0;
    pnext_n_minute(HOUR(simulator.time),x*60);
    pnext_n_minute(MINUTE(simulator.time),y);

    for (i = 0; i < y + x*60; i++) {
        next_tick();
    }
}