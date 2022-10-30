#include "start.h"

void start_program(string name) {
    initalize_simulator(name);
    initialize_delivery();
    initialize_history();
    load_map("../src/config/map.txt");
    load_food_recipe("../src/config/food.txt", "../src/config/recipe.txt");
    build_tree_recipe();
}