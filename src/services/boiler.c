/**
 * @file boiler.c
 * @brief boiler service
 * @version 1.1
 * @date 2022-10-29
 */

#include "boiler.h"

simulator_t simulator;
ListFoodRecipe food_recipe;
ListTree list_tree_recipe;

/*
 * BOILER CHECK
 * mengecek apakah bahan baku tersedia untuk melakukan proses boil
 */
boolean can_boil_food(int result_id, Tree recipe_tree){
    /* Cek apakah bahan tersedia di inventory */
    /* (bahan untuk boil dipastikan hanya ada satu) */
    food_t raw = T_FOOD(T_CHILDREN(recipe_tree, 0));
    if (food_count(inventory(simulator), FOOD_ID(raw)) > 0){
        return true;
    }
    else{
        return false;
    }
}

/*
 * BOILER SERVICE (procedure boil())
 * dipanggil apabila bahan mencukupi
 * proses:
 * ambil bahan dari inventory (dequeue)
 * panggil ticker
 * enqueue hasil ke inventory
*/
void boil(int result_id, Tree recipe_tree){
    food_t result = T_FOOD(recipe_tree);
    food_t raw = T_FOOD(T_CHILDREN(recipe_tree, 0));
    
    dequeue_food(&inventory(simulator), FOOD_ID(raw), &raw);     /* mengonsumsi bahan */
    
    next_tick();    /* penambahan waktu 1 menit */
                    /* next_tick() dipanggil sebanyak time_to_minute(process_time(food)) pada bonus */
    
    enqueue_food(&inventory(simulator), result);              /* boil bahan, menambahkan hasil ke inventory */
}
    