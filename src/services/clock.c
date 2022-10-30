#include "clock.h"
#include "simulator.h"
#include "delivery.h"
#include "../data/simulator.h"

/*
Advance waktu sebanyak satu menit
kurangi waktu kadaluarsa inventory player (simulator next tick)
kurangi waktu delivery (delivery next tick)
*/
void next_tick() {
    pnext_n_minute(&simulator.time, 1); // waktu nambah 1 menit

    simulator_next_tick();
    delivery_next_tick();
}