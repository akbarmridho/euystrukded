#include <stdio.h>
#include "../../src/adt/recipe.h"

int main(){
    int food_id, count;
    food_id = 42;
    count = 6;

    int ingredients[6] = {3, 4, 1, 8, 2, 0};

    recipe_t r;
    create_recipe(&r, food_id, count, ingredients);
    printf("<ID> <Child> <Ingredient1> <Ingredient2> <...>\n");
    display_recipe(r);

    return 0;
}