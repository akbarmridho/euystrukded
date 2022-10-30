#include <stdio.h>
#include "clock.h"
#include "simulator.h"
#include "delivery.h"
#include "../data/simulator.h"
#include "../adt/list_delivery.h"
#include "../adt/time.h"

extern simulator_t simulator;

/*
Advance waktu sebanyak satu menit
todo:

kurangi waktu kadaluarsa inventory player (simulator next tick)
kurangi waktu delivery (delivery next tick)
*/
void next_tick() {
    pnext_n_minute(&simulator.time, 1); // waktu nambah 1 menit

    simulator_next_tick();
    delivery_next_tick();
}