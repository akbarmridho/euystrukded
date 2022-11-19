#include "start.h"

void start_program(string name) {
    initalize_simulator(name);
    initialize_delivery(); // buat delivery kosong
    initialize_history(); // buat history kosong
    initialize_refrigerator();
    load_map("../src/config/map.txt"); // load map
    load_food_recipe("../src/config/food.txt", "../src/config/recipe.txt"); // load makanan dan resep
    build_tree_recipe(); // buat tree recipe
}