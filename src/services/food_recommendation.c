#include "food_recommendation.h"

simulator_t simulator;
ListTree list_tree_recipe;



void create_set(Set *set){
    for (int i = 0; i < MAX_ID + 1; i ++){
        S_ELMT(*set, i) = 0;
    }
    S_NEFF(*set) = 0;
    S_IDX_EFF(*set) = -1;
}

void list_food_to_set (Set *set, ListFood list){
    for (int i = 0; i < NEFF(list); i++){
        S_ELMT(*set, FOOD_ID(ELMT(list, i))) ++;
        S_NEFF(*set) ++;
        if (FOOD_ID(ELMT(list, i)) > S_IDX_EFF(*set)){
            S_IDX_EFF(*set) = FOOD_ID(ELMT(list, i));
        }
    }
}

void tree_to_set(Set *set, Tree recipe){
    if (recipe->children_count == 0){
        S_ELMT(*set, T_ID(recipe)) ++;
        S_NEFF(*set) ++;
        if (T_ID(recipe) > S_IDX_EFF(*set)){
            S_IDX_EFF(*set) = T_ID(recipe);
        }
    }
    else {
        for (int i = 0; i < recipe->children_count; i++){
            tree_to_set(set, T_CHILDREN(recipe, i));
        }
    }
}

boolean isSubset(Set s1, Set s2){
    if (S_IDX_EFF(s1) > S_IDX_EFF(s2) || S_NEFF(s1) > S_NEFF(s2)){
        return false;
    }
    else {
        int i = 0;
        while (i <= S_IDX_EFF(s1)){
            if (S_ELMT(s2, i) < S_ELMT(s1, i)){
                return false;
            }
            else {
                i++;
            }
        }
        return true;
    }
}

void display_set(Set s){
    for (int i = 0; i <= S_IDX_EFF(s); i++){
        if (S_ELMT(s, i) > 0 ){
            printf("%d,%d\n",i,S_ELMT(s, i));
        }
    }
}

void food_recommendation(){
    // Mengubah inventory menjadi sebuah set;
    Set set_inventory;
    create_set(&set_inventory);
    list_food_to_set(&set_inventory, inventory(simulator));
    printf("Rekomendasi makanan yang dapat dibuat\n");
    int num = 1;
    for (int i = 0; i < list_tree_recipe.length; i++){
        if (list_tree_recipe.content[i]->children_count == 0){
            continue;
        }
        else {
            Set recipe;
            create_set(&recipe);
            tree_to_set(&recipe, list_tree_recipe.content[i]);
            if (isSubset(recipe , set_inventory)){
                printf("    %d. ",num);
                print_string(FOOD_NAME(list_tree_recipe.content[i]->food));
                printf("\n");
                num++;
            }
        }

    }
}