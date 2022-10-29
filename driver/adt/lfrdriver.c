#include <stdio.h>
#include "../../src/adt/list_food_recipe.h"

int main(){
    food_t f1, f2, f3, f4;
    create_food(&f1, 12, char_to_string("Sate ayam"), minute_to_time(120), minute_to_time(10), Mix);
    create_food(&f2, 45, char_to_string("Ayam geprek"), minute_to_time(200), minute_to_time(15), Buy);
    create_food(&f3, 26, char_to_string("Nasi goreng"), minute_to_time(150), minute_to_time(9), Fry);
    create_food(&f4, 5, char_to_string("Jus Alpukat"), minute_to_time(100), minute_to_time(11), Mix);

    recipe_t r1, r2, r3, r4;
    int ingredients[5] = {0, 1, 2, 3, 4}; 
    create_recipe(&r1, 12, 5, ingredients);
    create_recipe(&r2, 45, 5, ingredients);
    create_recipe(&r3, 26, 5, ingredients);
    create_recipe(&r4, 5, 5, ingredients);

    food_recipe_t fr1, fr2, fr3, fr4, val;
    create_food_recipe(&fr1, f1, r1); 
    create_food_recipe(&fr2, f2, r2); 
    create_food_recipe(&fr3, f3, r3); 
    create_food_recipe(&fr4, f4, r4); 

    /* print kosong */
    ListFoodRecipe lfr;
    create_lfr(&lfr);
    display_lfr(lfr);
    printf("(empty)\n\n");


    lfr_insert_first(&lfr, fr1);
    lfr_insert_last(&lfr, fr3);
    lfr_insert_at(&lfr, fr2, 1);
    lfr_insert_at(&lfr, fr4, 0);
    display_lfr(lfr);
    putchar('\n');
    /*
     * expected order:
     * Jus Alpukat
     * Sate ayam
     * Ayam geprek
     * Nasi goreng
     */

    /* search by food id test, r1 is "Sate ayam" */
    printf("'Sate ayam' located at index: %d\n\n", lfr_search_by_food_id(lfr, R_FOOD_ID(r1)));

    lfr_delete_at(&lfr, &val, 3);   /* delete last test */
    lfr_delete_at(&lfr, &val, 1);   /* delete test */
    lfr_delete_at(&lfr, &val, 0);   /* delete first test*/
    display_lfr(lfr);
    /*
     * expected order:
     * Ayam geprek
     */

    return 0;
}