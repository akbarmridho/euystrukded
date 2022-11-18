#ifndef ADT_SET_H
#define ADT_SET_H

#include "boolean.h"
#include "tree.h"
#include "list_food.h"


#define MAX_ID 99           //Max food ID

typedef struct {
    char contents[MAX_ID + 1];  // Buffer
    int neff;                   // Banyaknya elm pada set
    int idx_eff;                // Nilai IDX paling besar
} Set;

/* SELEKTOR */
#define S_ELMT(s, i) (s).contents[(i)]
#define S_NEFF(s) (s).neff
#define S_IDX_EFF(s) (s).idx_eff

/* KONSTRUKTOR */

/*  proses: Menginialisasi set set
    I.S. set sembarang
    F.S. set terdefinisi
*/
void create_set(Set *set);

/*  proses: mengonversi List Food dalam bentuk set
    I.S. set sembarang
    F.s. set merepresentasikan element element pada list
*/
void list_food_to_set(Set *set, ListFood list);

/*  proses: mengonversi tree recipe dalam bentuk set
    I.S. set sembarang
    F.s. set merepresentasikan ingridient-ingridient pada tree recipe
*/
void tree_to_set(Set *set, Tree recipe);

/* Mengembalikan apakah s1 merupakan subset dari s2 */
boolean isSubset(Set s1, Set s2);

/* Menampilkan elemen set dan jumlahnya */
void display_set(Set s);

#endif
