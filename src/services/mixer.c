/**
 * @file mixer.c
 * @brief mixer service
 * @version 1.0
 * @date 2022-10-30
 */

#include "mixer.h"

/*
 * MIXER CHECK
 * mengecek apakah bahan baku tersedia untuk melakukan proses mix
 */
boolean can_mix_food(Tree recipe_tree){
    /* Cek apakah bahan tersedia di inventory */
    /* (bahan untuk mix sebanyak recipe_tree.children_count) */
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
 * MIXER SERVICE (procedure mix())
 * dipanggil apabila bahan mencukupi
 * proses:
 * ambil bahan dari inventory (dequeue)
 * panggil ticker
 * enqueue hasil ke inventory
*/
boolean mix(Tree recipe_tree){
    food_t result = T_FOOD(recipe_tree);
    for (int i = 0; i < recipe_tree->children_count; i++) {
        food_t raw = T_FOOD(T_CHILDREN(recipe_tree, i));
        dequeue_food(&inventory(simulator), FOOD_ID(raw), &raw);     /* mengonsumsi bahan */
    }
    next_tick();    /* penambahan waktu 1 menit */
    /* next_tick() dipanggil sebanyak time_to_minute(process_time(food)) pada bonus */

    enqueue_food(&inventory(simulator), result);              /* menambahkan hasil ke inventory */
}
