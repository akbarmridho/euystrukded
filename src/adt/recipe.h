#ifndef __RECIPE_h
#define __RECIPE_h

#define MAX_RECIPE 10

typedef struct
{
    int food_id;
    int ingredients_count;
    int ingredients[MAX_RECIPE];
} recipe_t;

void create_recipe(recipe_t *r, int food_id, int ingredients_count, int ingredients[]);

#endif