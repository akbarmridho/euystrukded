/**
 * @file fry.c
 * @brief FRY command
 * @version 1.0
 * @date 2022-10-30
 */

#include "fry.h"


void do_fry() {
    ListFoodRecipe fryables;
    create_lfr(&fryables);

    printf("======================\n");
    printf("=        FRY         =\n");
    printf("======================\n");

    printf("List Bahan Makanan yang Bisa Dibuat:\n");

    /* display and store fryable recipes in fryables */
    int counter = 1;
    for (int i = lfr_get_first_idx(food_recipe); i <= lfr_get_last_idx(food_recipe); i++) {
        food_recipe_t current = LFR_ELMT(food_recipe, i);
        if (FOOD_SOURCE(FR_FOOD(current)) == Fry) {
            lfr_insert_last(&fryables, current);
            printf("   %d. ", counter);
            print_string(FOOD_NAME(FR_FOOD(current)));
            putchar('\n');
            counter++;
        }
    }
    printf("\nKirim 0 untuk exit.\n");

    /* input user choice */
    int choice = validate_int(0, LFR_NEFF(fryables), char_to_string("Enter Command: "));
    while (choice != 0) {
        int result_id = FOOD_ID(FR_FOOD(LFR_ELMT(fryables, choice)));
        string name = FOOD_NAME(FR_FOOD(LFR_ELMT(fryables, choice)));
        Tree recipe_tree = lt_search_by_id(&list_tree_recipe, result_id);

        if (can_fry_food(recipe_tree)) {
            fry(recipe_tree);
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
        choice = validate_int(0, LFR_NEFF(fryables), char_to_string("Enter Command: "));
    }
}