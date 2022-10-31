#include "tree.h"
#include <stdlib.h>
#include <stdio.h>

Address new_tree_node(food_t food) {
    Address result;

    result = (Address) malloc(sizeof(tree_node_t));

    if (result != NULL) {
        T_FOOD(result) = food;
        result->children_count = 0;

        for (int i = 0; i < TREE_CHILD_MAX; i++) {
            T_CHILDREN(result, i) = NULL;
        }
    }

    return result;
}

void new_empty_tree(food_t food, Tree *p) {
    Tree new = new_tree_node(food);
    *p = new;
}

void new_tree(food_t food, int child_count, Address children[], Tree *p) {
    new_empty_tree(food, p);

    (*p)->children_count = child_count;

    for (int i = 0; i < child_count; i++) {
        T_CHILDREN(*p, i) = children[i];
    }
}

void tree_insert_child(Address child, Tree p) {
    T_CHILDREN(p, p->children_count) = child;
    p->children_count++;
}

void display_tree(Tree t) {
    putchar('(');
    printf("%d", T_ID(t));
    putchar('[');

    for (int i = 0; i < t->children_count; i++) {
        display_tree(T_CHILDREN(t, i));
        if (i != t->children_count - 1) {
            putchar(',');
        }
    }

    printf("])");
}

void lt_create(ListTree *l) {
    for (int i = 0; i < TREE_CHILD_MAX; i++) {
        (*l).content[i] = NULL;
    }

    (*l).length = 0;
}

void lt_insert_last(ListTree *l, Tree item) {
    (*l).content[(*l).length] = item;
    (*l).length++;
}

Tree lt_search_by_id(ListTree *l, int id) {
    boolean found = false;
    int i = 0;

    while (!found && i < (*l).length) {
        if (T_ID((*l).content[i]) == id) {
            found = true;
        } else {
            i++;
        }
    }

    if (found) {
        return (*l).content[i];
    } else {
        return NULL;
    }
}