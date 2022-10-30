/**
 * @file chopper.c
 * @brief chopper service
 * @version 1.1
 * @date 2022-10-29
 */

#include "chopper.h"

simulator_t simulator;
ListFoodRecipe food_recipe;
ListTree list_tree_recipe;

/*
 * CHOPPER CHECK
 * mengecek apakah bahan baku tersedia untuk melakukan proses chop
 */
boolean can_chop_food(int result_id, Tree recipe_tree){
    /* Cek apakah bahan tersedia di inventory */
    /* (bahan untuk chop dipastikan hanya ada satu) */
    food_t raw = T_FOOD(T_CHILDREN(recipe_tree, 0));
    if (food_count(inventory(simulator), FOOD_ID(raw)) > 0){
        return true;
    }
    else{
        return false;
    }
}

/*
 * CHOPPER SERVICE (procedure chop())
 * dipanggil apabila bahan mencukupi
 * proses:
 * ambil bahan dari inventory (dequeue)
 * panggil ticker
 * enqueue hasil ke inventory
*/
void chop(int result_id, Tree recipe_tree){
    food_t result = T_FOOD(recipe_tree);
    food_t raw = T_FOOD(T_CHILDREN(recipe_tree, 0));
    
    dequeue_food(&inventory(simulator), FOOD_ID(raw), &raw);     /* mengonsumsi bahan */
    
    next_tick();    /* penambahan waktu 1 menit */
                    /* next_tick() dipanggil sebanyak time_to_minute(process_time(food)) pada bonus */
    
    enqueue_food(&inventory(simulator), result);              /* chop bahan, menambahkan hasil ke inventory */
}
