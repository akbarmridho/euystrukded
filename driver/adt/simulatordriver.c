#include "../../src/adt/simulator.h"
#include <stdio.h>

int main() {
    simulator_t sim;
    char a[] = "salomo";
    string name;

    name = char_to_string(a);
    create_simulator(&sim, name);
}