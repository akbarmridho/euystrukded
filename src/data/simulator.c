#include "simulator.h"

simulator_t simulator;

void initalize_simulator(string name) {
    create_simulator(&simulator, name);
}