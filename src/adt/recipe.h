#ifndef __RECIPE_h
#define __RECIPE_h

#define MAX_RECIPE 10

typedef struct
{
    int food_id;
    int ingredients_count;
    int ingredients[MAX_RECIPE];
} recipe_t;

/* *** SELEKTOR *** */
#define R_FOOD_ID(recipe) (recipe).food_id
#define R_ING_COUNT(recipe) (recipe).ingredients_count 
#define R_ING_LIST_ELMT(recipe, idx) (recipe).ingredients[idx]

/* *** KONSTRUKTOR *** */
/*
 * create_recipe
 * I.S: r tidak terdefinisi, food_id, ingredients_count, ingredients[] dipastikan valid
 * F.S: r terdefinisi
 */
void create_recipe(recipe_t *r, int food_id, int ingredients_count, int ingredients[]);


/* *** OUTPUT/DISPLAY *** */
/*
 * display_recipe
 * I.S: r terdefinisi
 * F.S: r tercetak dengan format
 * <food_id> <ingredients_count> <ingredients[0]> <ingredients[1]> <...>
 */
void display_recipe(recipe_t r);

#endif
