#ifndef __NARY_TREE_H
#define __NARY_TREE_H

#include "recipe.h"

typedef int ElType;
typedef struct treeNode *Address;
typedef struct treeNode
{
    ElType id;
    int child_count;
    Address *children;
} tree_node_t;

typedef Address Tree;

/*
Implementasi dibebaskan :>
buat juga list of tree untuk menyimpan semua tree resep

referensi: https://github.com/malikrafsan/Praktikum-STEI-IF-ITB/blob/main/Algoritma-dan-Struktur-Data/Praktikum13/bintree.h
*/

#endif