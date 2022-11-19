#include "set.h"
#include "../data/configdata.h"


void create_set(Set *set) {
    for (int i = 0; i < MAX_ID + 1; i++) {
        S_ELMT(*set, i) = 0;
    }
    S_NEFF(*set) = 0;
    S_IDX_EFF(*set) = -1;
}

void list_food_to_set(Set *set, ListFood list) {
    for (int i = 0; i < NEFF(list); i++) {
        S_ELMT(*set, FOOD_ID(ELMT(list, i)))++;
        S_NEFF(*set)++;
        if (FOOD_ID(ELMT(list, i)) > S_IDX_EFF(*set)) {
            S_IDX_EFF(*set) = FOOD_ID(ELMT(list, i));
        }
    }
}

void set_to_scratch(Set *set) { 
    boolean scratching;
    do { 
        scratching = false;
        for (int i = 0; i < S_CAP; i++) {
            int recipe_idx = lfr_search_by_food_id(food_recipe, i);
            recipe_t recipe = food_recipe.contents[recipe_idx].recipe;
            if (S_ELMT(*set, i) == 0 || recipe.ingredients_count == 0){
                continue;
            }
            else {
                S_ELMT(*set, i)--;
                S_NEFF(*set)--;
                for (int j = 0; j < recipe.ingredients_count; j ++){
                    S_ELMT(*set, recipe.ingredients[j])++;
                    S_NEFF(*set)++;
                }
                scratching = true;
            }
        }
    } while (scratching);
}

void tree_to_set(Set *set, Tree recipe) {
    if (recipe->children_count == 0) {
        S_ELMT(*set, T_ID(recipe))++;
        S_NEFF(*set)++;
        if (T_ID(recipe) > S_IDX_EFF(*set)) {
            S_IDX_EFF(*set) = T_ID(recipe);
        }
    } else {
        for (int i = 0; i < recipe->children_count; i++) {
            tree_to_set(set, T_CHILDREN(recipe, i));
        }
    }
}

Set set_copy(Set s1){
    Set temp;
    S_NEFF(temp) = 0;
    S_IDX_EFF(temp) = -1; 
    for(int i = 0; i < S_CAP; i++){
        if (S_ELMT(s1, i) > 0){
            S_ELMT(temp, i) = S_ELMT(s1, i);
            S_IDX_EFF(temp) = i;
        }    
        else {
            S_ELMT(temp, i) = 0;
        }
    }   
    return temp;
}

boolean is_subset(Set s1, Set s2) {
    int i = 0;
    while (i < S_CAP) {
        if (S_ELMT(s2, i) < S_ELMT(s1, i)) {
            return false;
        } else {
            i++;
        }
    }
    return true;
}
// void display_set(Set s) {
//     printf("[");
//     for (int i = 0; i < S_CAP; i++) {
//         if (S_ELMT(s, i) > 0) {
//             printf("[%d,%d] ", i, S_ELMT(s, i));
//         }
//     }
//     printf("]\n");
// }
