#include "autoprocess.h"

void autoprocess(int id) {
    int lfr_food_index = lfr_search_by_food_id(food_recipe, id);
    food_t food = FR_FOOD(LFR_ELMT(food_recipe, lfr_food_index));
    int food_id = FOOD_ID(food);
    string name = FOOD_NAME(food);
    Tree recipe_tree = lt_search_by_id(&list_tree_recipe, food_id);

    boolean lack_ingredient = false;

    if (can_process_food(recipe_tree)) {
        backup_state();
        process_food(recipe_tree);
    } else {
        lack_ingredient = true;
    }

    if (lack_ingredient) {
        printf("Gagal membuat ");
        print_string(name);
        printf(" karena anda tidak memiliki bahan berikut:\n");

        for (int i = 0; i < recipe_tree->children_count; i++) {
            food_t food_ingredient = T_FOOD(T_CHILDREN(recipe_tree, i));

            if (food_count(inventory(simulator), FOOD_ID(food_ingredient)) <= 0) {
                printf("  %d. ", i + 1);
                print_string(FOOD_NAME(food_ingredient));
                putchar('\n');
            }
        }

        printf("Enter command: ");
    } else {
        notify(concat(name, char_to_string(" selesai dibuat")));
        notify_undo(concat(name, char_to_string(" tidak jadi dibuat.")));
        clear_display();
        display_info();
        printf("Enter command: ");
    }
}