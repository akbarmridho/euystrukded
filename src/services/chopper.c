/**
 * @file chopper.c
 * @brief chopper service
 * @version 1.0
 * @date 2022-10-29
 */

#include "chopper.h"
#include "../data/simulator.h"

extern simulator_t simulator;
extern ListFoodRecipe food_recipe;

/*
 * CHOPPER CHECK
 * mengecek apakah bahan baku tersedia untuk melakukan proses chop
 */
boolean can_chop_food(int result_id){
    int lfr_pos = lfr_search_by_food_id(food_recipe, result_id);
    int raw_id = R_ING_LIST_ELMT(FR_RECIPE(LFR_ELMT(food_recipe, lfr_pos)), 0);
    /* bahan untuk chop dipastikan hanya ada satu */
    if (food_count(inventory(simulator), raw_id) > 0){
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
void chop(int result_id){
    int lfr_pos = lfr_search_by_food_id(food_recipe, result_id);        /* posisi resep pada LFR data food_recipe */
    int raw_id = R_ING_LIST_ELMT(FR_RECIPE(LFR_ELMT(food_recipe, lfr_pos)), 0);
    food_t food;
    
    dequeue_food(&inventory(simulator), raw_id, &food);     /* mengonsumsi bahan */
    
    next_tick();    /* penambahan waktu 1 menit */
                    /* next_tick() dipanggil sebanyak time_to_minute(process_time(food)) pada bonus */
    
    food = FR_FOOD(LFR_ELMT(food_recipe, lfr_pos));         /* boil bahan, menambahkan hasil ke inventory */
    enqueue_food(&inventory(simulator), food);
}
