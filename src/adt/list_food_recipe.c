/**
 * ADT LIST FOOD-RECIPE
 * @file: list_food_recipe.c
 * ver: 2022/10/28
 */

#include "list_food_recipe.h"


/* **** FOOD_RECIPE **** */
/* ** KONSTRUKTOR food_recipe_t ** */
/*
 * create_food_recipe
 * I.S: fr sembarang, food, recipe terdefinisi
 * F.S: fr terdefinisi
*/
void create_food_recipe(food_recipe_t *fr, food_t food, recipe_t recipe){
   FR_FOOD(*fr) = food;
   FR_RECIPE(*fr) = recipe;
}


/* *** LFR *** */
/* I.S. lfr sembarang
F.S. Terbentuk List lfr kosong dengan kapasitas CAPACITY
Proses: Inisialisasi semua elemen List lfr dengan MARK */
void create_lfr(ListFoodRecipe *lfr){
   LFR_NEFF(*lfr) = 0;
}

/*Banyaknya elemen
Mengirimkan banyaknya elemen efektif List
Mengirimkan nol jika List kosong */
int lfr_length(ListFoodRecipe lfr){
   return LFR_NEFF(lfr);
}

/*
Prekondisi : List lfr tidak kosong
Mengirimkan indeks elemen lfr pertama */
IdxType lfr_get_first_idx(ListFoodRecipe lfr){
   return 0;
}

/*
Prekondisi : List lfr tidak kosong
Mengirimkan indeks elemen lfr terakhir */
IdxType lfr_get_last_idx(ListFoodRecipe lfr){
   return LFR_NEFF(lfr) - 1;
}

/*
Mengirimkan true jika i adalah indeks yang valid utk kapasitas List lfr
yaitu antara indeks yang terdefinisi utk container
*/
boolean lfr_is_idx_valid(ListFoodRecipe lfr, IdxType i){
   return (0 <= i && i < CAPACITY);
}

/*
Mengirimkan true jika i adalah indeks yang terdefinisi utk List lfr
yaitu antara 0..length(lfr)-1
*/
boolean lfr_is_idx_eff(ListFoodRecipe lfr, IdxType i){
   return (lfr_get_first_idx(lfr) <= i && i <= lfr_get_last_idx(lfr));
}

/* Mengirimkan true jika List lfr kosong, mengirimkan false jika tidak */
boolean lfr_is_empty(ListFoodRecipe lfr){
   return (LFR_NEFF(lfr) == 0);
}

/* Mengirimkan true jika List lfr penuh, mengirimkan false jika tidak */
boolean lfr_is_full(ListFoodRecipe lfr){
   return (LFR_NEFF(lfr) == CAPACITY);
}

/* Proses: Menambahkan val sebagai elemen pada index idx List */
/* I.S. List lfr tidak penuh, idx merupakan index yang efektif di lfr */
/* F.S. val adalah elemen yang disisipkan pada index idx lfr */
/* *** Menambahkan elemen pada idx*** */
void lfr_insert_at(ListFoodRecipe *lfr, food_recipe_t val, IdxType idx){
   if (idx == 0){
      lfr_insert_first(lfr, val);
   }
   else if (idx == LFR_NEFF(*lfr)){
      lfr_insert_last(lfr, val);
   }
   else{
      IdxType last = lfr_get_last_idx(*lfr);
      for (int i = last + 1; i > idx; i--){
         LFR_ELMT(*lfr, i) = LFR_ELMT(*lfr, i - 1);
      }  /* i == idx */
      LFR_ELMT(*lfr, idx) = val;
      LFR_NEFF(*lfr)++;
   }
}

/* Proses: Menambahkan val sebagai elemen pada index awal List */
/* I.S. List lfr tidak penuh */
/* F.S. val adalah elemen yang disisipkan pada awal lfr */
/* *** Menambahkan elemen pada idx *** */
void lfr_insert_first(ListFoodRecipe *lfr, food_recipe_t val){
   if (lfr_is_empty(*lfr)){
      LFR_ELMT(*lfr, 0) = val;
      LFR_NEFF(*lfr)++;
   }
   else{
      IdxType last = lfr_get_last_idx(*lfr);
      for (int i = last + 1; i > 0; i--){
         LFR_ELMT(*lfr, i) = LFR_ELMT(*lfr, i - 1);
      }  /* i == idx */
      LFR_ELMT(*lfr, 0) = val;
      LFR_NEFF(*lfr)++;
   }
}

/* Proses: Menambahkan val sebagai elemen pada index akhir List */
/* I.S. List lfr tidak penuh */
/* F.S. val adalah elemen yang disisipkan pada akhir lfr */
/* *** Menambahkan elemen pada idx *** */
void lfr_insert_last(ListFoodRecipe *lfr, food_recipe_t val){
   LFR_ELMT(*lfr, LFR_NEFF(*lfr)) = val;
   LFR_NEFF(*lfr)++;
}

/* Proses : Menghapus elemen pada index idx List */
/* I.S. List tidak kosong, idx adalah index yang efektif di lfr */
/* F.S. val adalah nilai elemen pada index idx lfr sebelum penghapusan, */
/*      Banyaknya elemen List berkurang satu */
/*      List lfr mungkin menjadi kosong */
/* *** Menghapus elemen pada idx *** */
void lfr_delete_at(ListFoodRecipe *lfr, food_recipe_t *val, IdxType idx){
   *val = LFR_ELMT(*lfr, idx);
   if (idx == lfr_get_first_idx(*lfr)){
      lfr_delete_first(lfr, val);
   }
   else if (idx == lfr_get_last_idx(*lfr)){
      lfr_delete_last(lfr, val);
   }
   else{
      for (int i = idx; i < lfr_get_last_idx(*lfr); i++){
         LFR_ELMT(*lfr, i) = LFR_ELMT(*lfr, i + 1);
      }
      LFR_NEFF(*lfr)--;
   }
}

/* Proses : Menghapus elemen awal List */
/* I.S. List tidak kosong */
/* F.S. val adalah nilai elemen pada index 0 lfr sebelum penghapusan, */
/*      Banyaknya elemen List berkurang satu */
/*      List lfr mungkin menjadi kosong */
/* *** Menghapus elemen pada awal lfr *** */
void lfr_delete_first(ListFoodRecipe *lfr, food_recipe_t *val){
   *val = LFR_ELMT(*lfr, lfr_get_first_idx(*lfr));
   if (LFR_NEFF(*lfr) > 1){
      for (int i = lfr_get_first_idx(*lfr); i < lfr_get_last_idx(*lfr); i++){
         LFR_ELMT(*lfr, i) = LFR_ELMT(*lfr, i + 1);
      }
   }
   LFR_NEFF(*lfr)--;
}

/* Proses : Menghapus elemen terakhir List */
/* I.S. List tidak kosong */
/* F.S. val adalah nilai elemen pada index idx lfr sebelum penghapusan, */
/*      Banyaknya elemen List berkurang satu */
/*      List lfr mungkin menjadi kosong */
/* *** Menghapus elemen pada akhir lfr *** */
void lfr_delete_last(ListFoodRecipe *lfr, food_recipe_t *val){
   *val = LFR_ELMT(*lfr, lfr_get_last_idx(*lfr));
   LFR_NEFF(*lfr)--;
}

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
void display_lfr(ListFoodRecipe lfr){
   printf("List Resep\n");
   printf("(aksi yang diperlukan - bahan...)\n");
   if (!lfr_is_empty(lfr)){
      for (int i = lfr_get_first_idx(lfr); i <= lfr_get_last_idx(lfr); i++){
         recipe_t rec = FR_RECIPE(LFR_ELMT(lfr, i));
         food_t food = FR_FOOD(LFR_ELMT(lfr, i));

         printf("   %d. ", (i + 1));
         print_string(NAME(food));
         putchar('\n');
         printf("      <Source-%d> - ", SOURCE(food));
         for (int j = 0; j < R_ING_COUNT(rec); j++){
            printf("<Ingredient-%d>", R_ING_LIST_ELMT(rec, j));
            if (j != R_ING_COUNT(rec) - 1){
               printf(" - ");
            }
         }
         putchar('\n');
      }
   }
}