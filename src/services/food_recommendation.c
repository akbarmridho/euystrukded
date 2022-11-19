#include "food_recommendation.h"
#include "food_recommendation.h"

boolean is_path_exist(Tree recipe, Set inventory){
    int main_recipe_count = S_ELMT(inventory, FOOD_ID(T_FOOD(recipe)));

    if (recipe->children_count == 0){
        return (main_recipe_count > 0);
    }
    else {
        int val = 1;
        for (int i = 0; i < recipe->children_count; i++){
            val *= is_path_exist(T_CHILDREN(recipe, i), inventory);
        }
        return (val != 0) || (main_recipe_count > 0);
    }
}

void food_recommendation() {
    // arrray dari nama makanan yang bisa dibuat
    string food_name[100]; 
    int num = 0;

    // Menyimpan inventory dalam bentuk set
    Set set_inventory;
    create_set(&set_inventory);
    list_food_to_set(&set_inventory, inventory(simulator));


    for (int i = 0; i < list_tree_recipe.length; i++) {
        Tree recipe = list_tree_recipe.content[i];
        if (recipe->children_count == 0) {
            continue;
        } else {
            
            // menyimpan resep dalam bentuk set
            Set set_recipe;
            create_set(&set_recipe);
            tree_to_set(&set_recipe, recipe);

            // menyimpan hasil dekomposisi inventory dalam bentuk set
            Set inventory_scratch = set_copy(set_inventory);
            set_to_scratch(&inventory_scratch);

            // inventory yang sedang di proses, di nol kan agar tidak mengecek diri sendiri
            Set temp_inventory = set_copy(set_inventory);
            S_ELMT(temp_inventory, recipe->food.id) = 0;

            if (is_path_exist(recipe, temp_inventory) && is_subset(set_recipe, inventory_scratch)) {
                food_name[num] = (FOOD_NAME(recipe->food));
                num++;
            }
        }

    }
    if (num == 0){
        printf("Tidak ada makanan yang dapat dibuat.\n");
    }
    else {
        printf("Rekomendasi makanan yang dapat dibuat: \n");
        for (int i = 0; i < num; i++){
            printf("    %d. ", i + 1);
            print_string(food_name[i]);
            putchar('\n');
        }
    }
}


