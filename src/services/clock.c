#include "clock.h"
#include "simulator.h"
#include "delivery.h"
#include "../data/simulator.h"

//simulator_t simulator;

/*
Advance waktu sebanyak satu menit
kurangi waktu kadaluarsa inventory player (simulator next tick)
kurangi waktu delivery (delivery next tick)
*/
void next_tick() {
    simulator_next_tick();
    delivery_next_tick();
}