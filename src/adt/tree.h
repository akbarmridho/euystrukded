#ifndef ADT_NARY_TREE_H
#define ADT_NARY_TREE_H

#include "food.h"
#include "list_food_recipe.h"

#define TREE_CHILD_MAX 5
#define TREE_LIST_MAX 100

#define T_FOOD(p) (p)->food
#define T_ID(p) (p)->food.id
#define T_METHOD(p) (p)->food.method
#define T_CHILDREN(p, i) (p)->children[i]

typedef struct treeNode *Address;
typedef struct treeNode {
    food_t food;
    int children_count;
    Address children[TREE_CHILD_MAX];
} tree_node_t;

typedef Address Tree;

Address new_tree_node(food_t food);

void new_empty_tree(food_t food, Tree *p);

void new_tree(food_t food, int child_count, Address children[], Tree *p);

void tree_insert_child(Address child, Tree p);

void display_tree(Tree t);

typedef struct {
    Tree content[TREE_LIST_MAX];
    int length;
} ListTree;

void lt_create(ListTree *l);

void lt_insert_last(ListTree *l, Tree item);

Tree lt_search_by_id(ListTree *l, int id);

void add_from_food_recipe(ListTree *l, ListFoodRecipe lfr, food_recipe_t fr);

#endif