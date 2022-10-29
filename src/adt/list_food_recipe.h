#ifndef ADT_LIST_FOOD_RECIPE_H
#define ADT_LIST_FOOD_RECIPE_H

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

typedef struct
{
   food_t food;
   recipe_t recipe;
} food_recipe_t;

/* SELEKTOR food_recipe_t */
#define FR_FOOD(fr) (fr).food
#define FR_RECIPE(fr) (fr).recipe

/* KONSTRUKTOR food_recipe_t */
void create_food_recipe(food_recipe_t *fr, food_t food, recipe_t recipe);


/* *** LIST FOOD RECIPE *** */
/* Definisi elemen dan koleksi objek */
typedef int IdxType;
typedef struct
{
   food_recipe_t contents[CAPACITY]; /* memori tempat penyimpan elemen (container) */
   int neff;  /* banyak elemen efektif*/
} ListFoodRecipe;
/* Indeks yang digunakan [0..CAPACITY-1] */
/* Jika lfr adalah ListFoodRecipe, cara deklarasi dan akses: */
/* Deklarasi : lfr : ListFoodRecipe */
/* Maka cara akses:
   ELMT(lfr,i) untuk mengakses elemen ke-i */
/* Definisi :
   List kosong: neff = 0
   Definisi elemen pertama: ELMT(lfr,i) dengan i=0 */

/* Ke depannya, ListFoodRecipe, list food recipe, dll
disingkat menjadi lfr
 */

/* ********** SELEKTOR ********** */
#define LFR_ELMT(l, i) (l).contents[(i)]
#define LFR_NEFF(l) (l).neff

/* I.S. lfr sembarang
F.S. Terbentuk List lfr kosong dengan kapasitas CAPACITY
Proses: Inisialisasi semua elemen List lfr dengan neff = 0 */
void create_lfr(ListFoodRecipe *lfr);

/*Banyaknya elemen
Mengirimkan banyaknya elemen efektif List
Mengirimkan nol jika List kosong */
int lfr_length(ListFoodRecipe lfr);

/*
Prekondisi : List lfr tidak kosong
Mengirimkan indeks elemen lfr pertama */
IdxType lfr_get_first_idx(ListFoodRecipe lfr);

/*
Prekondisi : List lfr tidak kosong
Mengirimkan indeks elemen lfr terakhir */
IdxType lfr_get_last_idx(ListFoodRecipe lfr);

/*
Mengirimkan true jika i adalah indeks yang valid utk kapasitas List lfr
yaitu antara indeks yang terdefinisi utk container
*/
boolean lfr_is_idx_valid(ListFoodRecipe lfr, IdxType i);

/*
Mengirimkan true jika i adalah indeks yang terdefinisi utk List lfr
yaitu antara 0..length(lfr)-1
*/
boolean lfr_is_idx_eff(ListFoodRecipe lfr, IdxType i);

/* Mengirimkan true jika List lfr kosong, mengirimkan false jika tidak */
boolean lfr_is_empty(ListFoodRecipe lfr);

/* Mengirimkan true jika List lfr penuh, mengirimkan false jika tidak */
boolean lfr_is_full(ListFoodRecipe lfr);

/* Proses: Menambahkan val sebagai elemen pada index idx List */
/* I.S. List lfr tidak penuh, idx merupakan index yang efektif di lfr */
/* F.S. val adalah elemen yang disisipkan pada index idx lfr */
/* *** Menambahkan elemen pada idx *** */
void lfr_insert_at(ListFoodRecipe *lfr, food_recipe_t val, IdxType idx);

/* Proses: Menambahkan val sebagai elemen pada index awal List */
/* I.S. List lfr tidak penuh */
/* F.S. val adalah elemen yang disisipkan pada awal lfr */
/* *** Menambahkan elemen pada idx *** */
void lfr_insert_first(ListFoodRecipe *lfr, food_recipe_t val);

/* Proses: Menambahkan val sebagai elemen pada index akhir List */
/* I.S. List lfr tidak penuh */
/* F.S. val adalah elemen yang disisipkan pada akhir lfr */
/* *** Menambahkan elemen pada idx *** */
void lfr_insert_last(ListFoodRecipe *lfr, food_recipe_t val);

/* Proses : Menghapus elemen pada index idx List */
/* I.S. List tidak kosong, idx adalah index yang efektif di lfr */
/* F.S. val adalah nilai elemen pada index idx lfr sebelum penghapusan, */
/*      Banyaknya elemen List berkurang satu */
/*      List lfr mungkin menjadi kosong */
/* *** Menghapus elemen pada idx *** */
void lfr_delete_at(ListFoodRecipe *lfr, food_recipe_t *val, IdxType idx);

/* Proses : Menghapus elemen awal List */
/* I.S. List tidak kosong */
/* F.S. val adalah nilai elemen pada index 0 lfr sebelum penghapusan, */
/*      Banyaknya elemen List berkurang satu */
/*      List lfr mungkin menjadi kosong */
/* *** Menghapus elemen pada awal lfr *** */
void lfr_delete_first(ListFoodRecipe *lfr, food_recipe_t *val);

/* Proses : Menghapus elemen terakhir List */
/* I.S. List tidak kosong */
/* F.S. val adalah nilai elemen pada index idx lfr sebelum penghapusan, */
/*      Banyaknya elemen List berkurang satu */
/*      List lfr mungkin menjadi kosong */
/* *** Menghapus elemen pada akhir lfr *** */
void lfr_delete_last(ListFoodRecipe *lfr, food_recipe_t *val);


/* OUTPUT/DISPLAY */
/*
 * display_lfr
 * I.S: lfr sembarang
 * F.S: lfr tercetak dengan format
 * List Resep
 * (aksi yang diperlukan - bahan...)
 *    1. Ayam Goreng
 *       FRY - Ayam Potong - Minyak Goreng
 *    2. Telur Rebus
 *       BOIL - Telur
 *    ...
 */
void display_lfr(ListFoodRecipe lfr);

/* mencari idx resep pada lfr berdasarkan food_id*/
IdxType lfr_search_by_food_id(ListFoodRecipe lfr, int food_id);

#endif