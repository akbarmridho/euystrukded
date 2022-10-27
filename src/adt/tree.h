#ifndef ADT_NARY_TREE_H
#define ADT_NARY_TREE_H

#include "food.h"

#define TREE_CHILD_MAX 5
#define TREE_LIST_MAX 100
#define CHILDREN_MARK NULL

#define T_ID(p) (p)->id
#define T_METHOD(p) (p)->method
#define T_CHILDREN(p, i) (p)->children[i]

typedef struct treeNode *Address;
typedef struct treeNode
{
    int id;
    enum food_source method;
    Address children[TREE_CHILD_MAX];
} tree_node_t;

typedef Address Tree;

Address new_tree_node(int id, enum food_source method);

void new_tree(int id, enum food_source method, int child_count, Address children[], Tree* p);

void display_tree(Tree t);

typedef struct {
    Tree content[TREE_LIST_MAX];
    int length;
} ListTree;

void lt_create(ListTree *l);

void lt_insert_last(ListTree *l, Tree item);

Tree lt_search_by_id(ListTree *l, int id);

#endif