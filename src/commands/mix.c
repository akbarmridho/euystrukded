/**
 * @file mix.c
 * @brief MIX command
 * @version 1.0
 * @date 2022-10-30
 */

#include "mix.h"

void do_mix() {
    ListFoodRecipe mixables;
    create_lfr(&mixables);

    printf("======================\n");
    printf("=        MIX        =\n");
    printf("======================\n");

    printf("List Bahan Makanan yang Bisa Dibuat:\n");

    /* display and store mixable recipes in mixables */
    int counter = 1;
    for (int i = lfr_get_first_idx(food_recipe); i <= lfr_get_last_idx(food_recipe); i++) {
        food_recipe_t current = LFR_ELMT(food_recipe, i);
        if (FOOD_SOURCE(FR_FOOD(current)) == Mix) {
            lfr_insert_last(&mixables, current);
            printf("   %d. ");
            print_string(FOOD_NAME(FR_FOOD(current)));
            putchar('\n');
        }
    }
    printf("\nKirim 0 untuk exit.\n");

    /* input user choice */
    int choice = validate_int(0, LFR_NEFF(mixables), char_to_string("Enter Command: "));
    while (choice != 0) {
        int result_id = FOOD_ID(FR_FOOD(LFR_ELMT(mixables, choice)));
        string name = FOOD_NAME(FR_FOOD(LFR_ELMT(mixables, choice)));
        Tree recipe_tree = lt_search_by_id(&list_tree_recipe, result_id);

        if (can_mix_food(recipe_tree)) {
            mix(recipe_tree);
            print_string(name);
            printf(" selesai dibuat dan sudah masuk ke inventory!\n");
        } else {
            printf("Gagal membuat ");
            print_string(name);
            printf(" karena kamu tidak memiliki bahan berikut:\n");

            counter = 1;
            for (int i = 0; i < recipe_tree->children_count; i++) {
                food_t raw = T_FOOD(T_CHILDREN(recipe_tree, i));
                if (food_count(inventory(simulator), FOOD_ID(raw)) <= 0) {
                    printf("   %d. ", counter);
                    print_string(FOOD_NAME(raw));
                    putchar('\n');
                    counter++;
                }
            }
        }

        putchar('\n');
        choice = validate_int(0, LFR_NEFF(mixables), char_to_string("Enter Command: "));
    }
}