#include "food_recommendation.h"

void food_recommendation() {
    // Mengubah inventory menjadi sebuah set;
    Set set_inventory;
    create_set(&set_inventory);
    list_food_to_set(&set_inventory, inventory(simulator));
    printf("Rekomendasi makanan yang dapat dibuat\n");
    int num = 1;
    for (int i = 0; i < list_tree_recipe.length; i++) {
        if (list_tree_recipe.content[i]->children_count == 0) {
            continue;
        } else {
            Set recipe;
            create_set(&recipe);
            tree_to_set(&recipe, list_tree_recipe.content[i]);
            if (isSubset(recipe, set_inventory)) {
                printf("    %d. ", num);
                print_string(FOOD_NAME(list_tree_recipe.content[i]->food));
                printf("\n");
                num++;
            }
        }

    }
}