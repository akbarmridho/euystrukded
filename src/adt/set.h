#ifndef ADT_SET_H
#define ADT_SET_H

#include "boolean.h"
#include "tree.h"
#include "list_food.h"


#define MAX_ID 99           
#define S_CAP 100

typedef struct {
    int contents[S_CAP];        // Buffer
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

/*  proses: mendekonstuksi elemen pada set food ke bahan paling sederhana
    I.S. set merepresentasikan list makanan
    F.s. set tersusun oleh ingredien-ingredient paling sederhana
*/
void set_to_scratch(Set *set);

/*  proses: mengonversi tree recipe dalam bentuk set
    I.S. set sembarang
    F.s. set merepresentasikan ingridient-ingridient pada tree recipe paling sederhana
*/
void tree_to_set(Set *set, Tree recipe);

/*  fungsi: mengembalikan Set yang merupakan salinan dari s1
*/
Set set_copy(Set s1);

/* Mengembalikan apakah s1 merupakan subset dari s2 */
boolean is_subset(Set s1, Set s2);

// /* Menampilkan elemen set dan jumlahnya */
// void display_set(Set s);

#endif
