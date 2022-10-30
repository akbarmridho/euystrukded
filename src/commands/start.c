#include "start.h"

void start_program(string name) {
    load_map("config/map.txt");
    load_food_recipe("config/food.txt", "config/recipe.txt");
    build_tree_recipe();
    initalize_simulator(name);
    initialize_delivery();
    initialize_history();
}