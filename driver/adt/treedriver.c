#include "../../src/adt/tree.h"
#include <stdio.h>

typedef struct {
    food_t food;
    int ingredient_count;
    int ingredients[10];
} rec_t;

void rec_create(rec_t *r, int id, enum food_source method, int count, int ingredients[])
{
    food_t food;
    day_time_t t;
    create_time(&t, 0,0,0);

    food.id = id;
    food.source = method;
    food.name = "a";
    food.expire_time = t;
    food.delivery_time = t;

    (*r).ingredient_count = count;

    for (int i = 0; i < count; i++) {
        (*r).ingredients[i] = ingredients[i];
    }
}

int main()
{
    rec_t minyak, ayam_tepung, ayam_potong, ayam_mentah, tepung, air, ayam_goreng;
    rec_create(&minyak, 1, Buy, 0, (int[]){0});
    rec_create(&ayam_mentah, 2, Buy, 0, (int[]){0});
    rec_create(&ayam_potong, 3, Chop, 1,(int[]){2});
    rec_create(&tepung, 4, Buy, 0, (int[]){0});
    rec_create(&air, 5, Buy, 0, (int[]){0});
    rec_create(&ayam_tepung, 6, Mix, 3, (int[]){3, 4, 5});
    rec_create(&ayam_goreng,  7, Fry, 2, (int[]){6, 1});

    rec_t rec_list[] = {minyak, ayam_mentah, ayam_potong, tepung, air, ayam_tepung, ayam_goreng};

    ListTree tree_list;

    lt_create(&tree_list);

    for (int i = 0; i < 7; i++) {
        rec_t item = rec_list[i];
        Tree new;
        printf("food id %d ingredients count: %d\n", item.food.id, item.ingredient_count);

        if (item.ingredient_count != 0) {
            Address children[item.ingredient_count];

            for (int j = 0; j < item.ingredient_count; j++) {
//                for (int k = 0; k < tree_list.length; k++) {
//                    printf("tree root id: %d\n", tree_list.content[k]->id);
//                }
//                printf("search id: %d\n", item.ingredients[i])
                Tree child = lt_search_by_id(&tree_list, item.ingredients[j]);

                if (child == NULL) {
                    printf("No child found!\n");
                } else {
//                    printf("child found\n");
                    children[j] = child;
                }
            }

            new_tree(item.food, item.ingredient_count, children, &new);
        } else {
            Address empty[] = {NULL};
            new_tree(item.food, item.ingredient_count, empty, &new);
        }

        lt_insert_last(&tree_list, new);
    }

    printf("tree length %d\n", tree_list.length);

    for (int i = 0; i < 7; i++) {
        Tree each = tree_list.content[i];
        display_tree(each);
        printf("\n");
    }

    return 0;
}