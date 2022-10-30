#include <stdio.h>
#include <stdlib.h>
#include "../data/configdata.h"
#include "../data/delivery.h"
#include "../data/history.h"
#include "../data/simulator.h"


extern simulator_t simulator;

void start_program(){
    initalize_simulator(simulator.name);
    initialize_delivery();
    initialize_history();
    load_map("map.txt");
    load_food_recipe("food.txt","recipe.txt");
    build_tree_recipe();
}