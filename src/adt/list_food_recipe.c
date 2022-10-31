/**
 * ADT LIST FOOD-RECIPE
 * @file: list_food_recipe.c
 * @date: 2022-10-28
 */

#include "list_food_recipe.h"


/* **** FOOD_RECIPE **** */
/* ** KONSTRUKTOR food_recipe_t ** */
/*
 * create_food_recipe
 * I.S: fr sembarang, food, recipe terdefinisi
 * F.S: fr terdefinisi
*/
void create_food_recipe(food_recipe_t *fr, food_t food, recipe_t recipe) {
    FR_FOOD(*fr) = food;
    FR_RECIPE(*fr) = recipe;
}


/* *** LFR *** */
/* I.S. lfr sembarang
F.S. Terbentuk List lfr kosong dengan kapasitas CAPACITY
Proses: Inisialisasi semua elemen List lfr dengan neff = 0 */
void create_lfr(ListFoodRecipe *lfr) {
    LFR_NEFF(*lfr) = 0;
}

/*Banyaknya elemen
Mengirimkan banyaknya elemen efektif List
Mengirimkan nol jika List kosong */
int lfr_length(ListFoodRecipe lfr) {
    return LFR_NEFF(lfr);
}

/*
Prekondisi : List lfr tidak kosong
Mengirimkan indeks elemen lfr pertama */
IdxType lfr_get_first_idx(ListFoodRecipe lfr) {
    return 0;
}

/*
Prekondisi : List lfr tidak kosong
Mengirimkan indeks elemen lfr terakhir */
IdxType lfr_get_last_idx(ListFoodRecipe lfr) {
    return LFR_NEFF(lfr) - 1;
}

/* Mengirimkan true jika List lfr kosong, mengirimkan false jika tidak */
boolean lfr_is_empty(ListFoodRecipe lfr) {
    return (LFR_NEFF(lfr) == 0);
}

/* Mengirimkan true jika List lfr penuh, mengirimkan false jika tidak */
boolean lfr_is_full(ListFoodRecipe lfr) {
    return (LFR_NEFF(lfr) == LFR_CAPACITY);
}

/* Proses: Menambahkan val sebagai elemen pada index idx List */
/* I.S. List lfr tidak penuh, idx merupakan index yang efektif di lfr */
/* F.S. val adalah elemen yang disisipkan pada index idx lfr */
/* *** Menambahkan elemen pada idx*** */
void lfr_insert_at(ListFoodRecipe *lfr, food_recipe_t val, IdxType idx) {
    if (idx == 0) {
        lfr_insert_first(lfr, val);
    } else if (idx == LFR_NEFF(*lfr)) {
        lfr_insert_last(lfr, val);
    } else {
        IdxType last = lfr_get_last_idx(*lfr);
        for (int i = last + 1; i > idx; i--) {
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
void lfr_insert_first(ListFoodRecipe *lfr, food_recipe_t val) {
    if (lfr_is_empty(*lfr)) {
        LFR_ELMT(*lfr, 0) = val;
        LFR_NEFF(*lfr)++;
    } else {
        IdxType last = lfr_get_last_idx(*lfr);
        for (int i = last + 1; i > 0; i--) {
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
void lfr_insert_last(ListFoodRecipe *lfr, food_recipe_t val) {
    LFR_ELMT(*lfr, LFR_NEFF(*lfr)) = val;
    LFR_NEFF(*lfr)++;
}

/* Proses : Menghapus elemen pada index idx List */
/* I.S. List tidak kosong, idx adalah index yang efektif di lfr */
/* F.S. val adalah nilai elemen pada index idx lfr sebelum penghapusan, */
/*      Banyaknya elemen List berkurang satu */
/*      List lfr mungkin menjadi kosong */
/* *** Menghapus elemen pada idx *** */
void lfr_delete_at(ListFoodRecipe *lfr, food_recipe_t *val, IdxType idx) {
    *val = LFR_ELMT(*lfr, idx);
    if (idx == lfr_get_first_idx(*lfr)) {
        lfr_delete_first(lfr, val);
    } else if (idx == lfr_get_last_idx(*lfr)) {
        lfr_delete_last(lfr, val);
    } else {
        for (int i = idx; i < lfr_get_last_idx(*lfr); i++) {
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
void lfr_delete_first(ListFoodRecipe *lfr, food_recipe_t *val) {
    *val = LFR_ELMT(*lfr, lfr_get_first_idx(*lfr));
    if (LFR_NEFF(*lfr) > 1) {
        for (int i = lfr_get_first_idx(*lfr); i < lfr_get_last_idx(*lfr); i++) {
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
void lfr_delete_last(ListFoodRecipe *lfr, food_recipe_t *val) {
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

void display_lfr(ListFoodRecipe lfr) {
    printf("List Resep\n");
    printf("(aksi yang diperlukan - bahan...)\n");
    if (!lfr_is_empty(lfr)) {
        for (int i = lfr_get_first_idx(lfr); i <= lfr_get_last_idx(lfr); i++) {
            recipe_t rec = FR_RECIPE(LFR_ELMT(lfr, i));
            food_t food = FR_FOOD(LFR_ELMT(lfr, i));

            printf("   %d. ", (i + 1));
            print_string(FOOD_NAME(food));
            putchar('\n');
            switch (FOOD_SOURCE(food)) {
                case (Buy):
                    printf("      Buy - ");
                    break;

                case (Chop):
                    printf("      Chop - ");
                    break;

                case (Mix):
                    printf("      Mix - ");
                    break;

                case (Fry):
                    printf("      Fry - ");
                    break;

                case (Boil):
                    printf("      Boil - ");
                    break;
            }
            for (int j = 0; j < R_ING_COUNT(rec); j++) {
                int id = lfr_search_by_food_id(lfr, R_ING_LIST_ELMT(rec, j));
                print_string(FOOD_NAME(FR_FOOD(LFR_ELMT(lfr, id))));
                if (j != R_ING_COUNT(rec) - 1) {
                    printf(" - ");
                }
                putchar('\n');
            }
        }
    }
}

/* mencari idx resep pada lfr berdasarkan food_id, return IDX_UNDEF jika tidak ada */
IdxType lfr_search_by_food_id(ListFoodRecipe lfr, int food_id) {
    IdxType found_idx = LFR_IDX_UNDEF;
    IdxType i = lfr_get_first_idx(lfr);
    while (i <= lfr_get_last_idx(lfr) && found_idx == LFR_IDX_UNDEF) {
        food_recipe_t current = LFR_ELMT(lfr, i);
        if (R_FOOD_ID(FR_RECIPE(current)) == food_id) {
            found_idx = i;
        } else {
            i++;
        }
    }
    return found_idx;
}

/* Mencari indeks makanan ke-nth dengan food_source source */
IdxType lfr_search_n_first_by_source(ListFoodRecipe lfr, enum food_source source, int nth) {
    boolean found = false;

    int i = 0;
    while (!found && i <= lfr_get_last_idx(lfr)) {
        if (FR_FOOD(LFR_ELMT(lfr, i)).source == source) {
            if (nth == 1) {
                found = true;
            } else {
                nth--;
            }
        } else {
            i++;
        }
    }

    if (found) {
        return i;
    }

    return LFR_IDX_UNDEF;
}