/**
 * @file food_processor.c
 * @brief food_processor command for BOIL, CHOP, FRY, MIX
 * @version 1.1
 * @date 2022-11-01
 */

#include "food_processor.h"

/*
 * FOOD PROCESSOR CHECK
 * mengecek apakah bahan baku tersedia untuk melakukan pemrosesan makanan {FRY|MIX|BOIL|CHOP}
 */
boolean can_process_food(Tree recipe_tree){
    /* Cek apakah bahan tersedia di inventory */
    /* (bahan untuk pemrosesan sebanyak recipe_tree.childer_count) */
    int i = 0;
    while (i < recipe_tree->children_count) {
        food_t raw = T_FOOD(T_CHILDREN(recipe_tree, i));
        if (food_count(inventory(simulator), FOOD_ID(raw)) <= 0) {
            return false;
        } else {
            i++;
        }
    }
    return true;
}

/*
 * FOOD PROCESSOR SERVICE
 * dipanggil apabila bahan untuk melakukan pemrosesan makanan mencukupi
 * proses:
 * ambil bahan dari inventory (dequeue)
 * panggil ticker
 * enqueue hasil ke inventory
*/
boolean process_food(Tree recipe_tree){
    food_t result = T_FOOD(recipe_tree);
    for (int i = 0; i < recipe_tree->children_count; i++) {
        food_t raw = T_FOOD(T_CHILDREN(recipe_tree, i));
        dequeue_food(&inventory(simulator), FOOD_ID(raw), &raw);     /* mengonsumsi bahan */
    }
    
    long processing_time = time_to_minute(FOOD_DELIVERY_TIME(result));
    if (processing_time > 0){
        /* DELIVERY TIME pada konfigurasi digunakan sebagai waktu pemrosesan*/
        for (int i = 0; i < processing_time; i++){
            next_tick();
            /* memajukan waktu sebanyak processing_time (bonus) */
        }
    }
    else{
        next_tick();
    }

    enqueue_food(&inventory(simulator), result);              /* menambahkan hasil ke inventory */
}