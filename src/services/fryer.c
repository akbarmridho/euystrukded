#include "fryer.h"

simulator_t simulator;
ListFoodRecipe food_recipe;
ListTree list_tree_recipe;

boolean can_fry_food(Tree recipe_tree){
    /* Cek apakah bahan tersedia di inventory */
    /* (bahan untuk fry sebanyak recipe_tree.childer_count) */
    int i = 0;
    while (i < recipe_tree->children_count){
        food_t raw = T_FOOD(T_CHILDREN(recipe_tree, i));
        if (food_count(inventory(simulator), FOOD_ID(raw)) <= 0){
            return false;
        }
        else{
            i++;
        }
    }
    return true;

}

boolean fry(Tree recipe_tree){
    food_t result = T_FOOD(recipe_tree);
    for (int i = 0; i < recipe_tree->children_count; i++){
        food_t raw = T_FOOD(T_CHILDREN(recipe_tree, i));
        dequeue_food(&inventory(simulator), FOOD_ID(raw), &raw);     /* mengonsumsi bahan */
    }
    next_tick();    /* penambahan waktu 1 menit */
                    /* next_tick() dipanggil sebanyak time_to_minute(process_time(food)) pada bonus */
    
    enqueue_food(&inventory(simulator), result);              /* menambahkan hasil ke inventory */
}