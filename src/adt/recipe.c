/**
 * ADT RECIPE
 * @file: recipe.c
 * ver: 2022/10/26
 */

#include <stdio.h>
#include "recipe.h"

/* *** DEFINISI ADT RECIPE *** */
/*
#define MAX_RECIPE 10
typedef struct
{
    int food_id;
    int ingredients_count;
    int ingredients[MAX_RECIPE];
} recipe_t;
*/


/* *** KONSTRUKTOR *** */
/*
 * create_recipe
 * I.S: r tidak terdefinisi, food_id, ingredients_count, ingredients[] dipastikan valid
 * F.S: r terdefinisi
 */
void create_recipe(recipe_t *r, int food_id, int ingredients_count, int ingredients[]){
    R_FOOD_ID(*r) = food_id;
    R_ING_COUNT(*r) = ingredients_count;
    for (int i = 0; i < ingredients_count; i++){
        R_ING_LIST_ELMT(*r, i) = ingredients[i];
    }
}

/* *** OUTPUT/DISPLAY *** */
/*
 * display_recipe
 * I.S: r terdefinisi
 * F.S: r tercetak dengan format
 * <food_id> <ingredients_count> <ingredients[0]> <ingredients[1]> <...>
 * 
 * tidak mencetak '\n'
 */
void display_recipe(recipe_t r){
    printf("%d ", R_FOOD_ID(r));

    int count = R_ING_COUNT(r);
    printf("%d ", count);

    for (int i = 0; i < count; i++){
        printf("%d", R_ING_LIST_ELMT(r, i));
        if (i != count - 1){
            putchar(' ');
        }
    }
}
