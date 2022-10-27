#include "tree.h"
#include <stdlib.h>
#include <stdio.h>

Address new_tree_node(int id, enum food_source method)
{
    Address result;

    result = (Address) malloc(sizeof(tree_node_t));

    if (result != NULL) {
        T_ID(result) = id;
        T_METHOD(result) = method;
    }

    for (int i = 0; i < TREE_CHILD_MAX; i++) {
        T_CHILDREN(result, i) = NULL;
    }

    return result;
}

void new_tree(int id, enum food_source method, int child_count, Address children[], Tree* p)
{
    Tree new = new_tree_node(id, method);

    if (new != NULL) {

        for (int i = 0; i < child_count; i++) {
            T_CHILDREN(new, i) = children[i];
        }
    }

    *p = new;
}

void display_tree(Tree t)
{
    putchar('(');
    printf("%d", t->id);
    putchar('[');

    int i = 0;

    while (t->children[i] != NULL) {
        display_tree(t->children[i]);
        putchar(',');
        i++;
    }
    printf("])");
}

void lt_create(ListTree *l)
{
    for (int i = 0; i < TREE_CHILD_MAX; i++) {
        (*l).content[i] = NULL;
    }

    (*l).length = 0;
}

void lt_insert_last(ListTree *l, Tree item)
{
    (*l).content[(*l).length] = item;
    (*l).length++;
}

Tree lt_search_by_id(ListTree *l, int id)
{
    boolean found = false;
    int i = 0;

    while(!found && i < (*l).length) {
        if ((*l).content[i]->id == id) {
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