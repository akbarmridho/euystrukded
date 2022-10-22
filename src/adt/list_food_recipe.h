#ifndef __LIST_FOOD_RECIPE_H
#define __LIST_FOOD_RECIPE_H

#include "boolean.h"
#include "recipe.h"
#include "food.h"

/*  Kamus Umum */
/* Kapasitas penyimpanan */
#define CAPACITY 100

/* Indeks minimum list */
#define IDX_MIN 0

/* Indeks tak terdefinisi*/
#define IDX_UNDEF -1

/* Nilai elemen tak terdefinisi*/
#define MARK -9999

typedef struct
{
   food_t food;
   recipe_t recipe;
} food_recipe_t;

void create_food_recipe(food_t food, recipe_t recipe);

/* Definisi elemen dan koleksi objek */
typedef food_recipe_t ElType; /* type elemen List */
typedef int IdxType;
typedef struct
{
   ElType contents[CAPACITY]; /* memori tempat penyimpan elemen (container) */
} ListFoodRecipe;
/* Indeks yang digunakan [0..CAPACITY-1] */
/* Jika l adalah ListFoodRecipe, cara deklarasi dan akses: */
/* Deklarasi : l : ListFoodRecipe */
/* Maka cara akses:
   ELMT(l,i) untuk mengakses elemen ke-i */
/* Definisi :
   List kosong: semua elemen bernilai MARK
   Definisi elemen pertama: ELMT(l,i) dengan i=0 */

/* Ke depannya, ListFoodRecipe, list food recipe, dll
disingkat menjadi lfr
 */

/* ********** SELEKTOR ********** */
#define LFR_ELMT(l, i) (l).contents[(i)]

/* I.S. l sembarang
F.S. Terbentuk List l kosong dengan kapasitas CAPACITY
Proses: Inisialisasi semua elemen List l dengan MARK */
void create_lfr(ListFoodRecipe *l);

/*Banyaknya elemen
Mengirimkan banyaknya elemen efektif List
Mengirimkan nol jika List kosong */
int lfr_length(ListFoodRecipe l);

/*
Prekondisi : List l tidak kosong
Mengirimkan indeks elemen l pertama */
IdxType lfr_get_first_idx(ListFoodRecipe l);

/*
Prekondisi : List l tidak kosong
Mengirimkan indeks elemen l terakhir */
IdxType lfr_get_last_idx(ListFoodRecipe l);

/*
Mengirimkan true jika i adalah indeks yang valid utk kapasitas List l
yaitu antara indeks yang terdefinisi utk container
*/
boolean lfr_is_idx_valid(ListFoodRecipe l, IdxType i);

/*
Mengirimkan true jika i adalah indeks yang terdefinisi utk List l
yaitu antara 0..length(l)-1
*/
boolean lfr_is_idx_eff(ListFoodRecipe l, IdxType i);

/* Mengirimkan true jika List l kosong, mengirimkan false jika tidak */
boolean lfr_is_empty(ListFoodRecipe l);

/* Mengirimkan true jika List l penuh, mengirimkan false jika tidak */
boolean lfr_is_full(ListFoodRecipe l);

/* Proses: Menambahkan val sebagai elemen pada index idx List */
/* I.S. List l tidak kosong dan tidak penuh, idx merupakan index yang valid di l */
/* F.S. val adalah elemen yang disisipkan pada index idx l */
/* *** Menambahkan elemen terakhir *** */
void lfr_insert_at(ListFoodRecipe *l, ElType val, IdxType idx);

/* Proses : Menghapus elemen pada index idx List */
/* I.S. List tidak kosong, idx adalah index yang valid di l */
/* F.S. val adalah nilai elemen pada index idx l sebelum penghapusan, */
/*      Banyaknya elemen List berkurang satu */
/*      List l mungkin menjadi kosong */
/* *** Menghapus elemen terakhir *** */
void lfr_delete_at(ListFoodRecipe *l, ElType *val, IdxType idx);

#endif