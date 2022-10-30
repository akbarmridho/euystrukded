#ifndef __LIST_FOOD_H
#define __LIST_FOOD_H

#include "boolean.h"
#include "food.h"
#include "list_food.h"
#include <stdio.h>
#include <stdlib.h>

/*  Kamus Umum */
#define IDX_MIN 0
/* Indeks minimum list */
#define IDX_UNDEF -1
/* Indeks tak terdefinisi*/

/* Definisi elemen dan koleksi objek */
typedef int IdxType;
typedef struct
{
   food_t * buffer; /* memori tempat penyimpan elemen (container) */
   int nEff;       /* >=0, banyaknya elemen efektif */
   int capacity;   /* ukuran elemen */
} ListFood;
/* Indeks yang digunakan [0..capacity-1] */
/* Jika l adalah : ListFood, cara deklarasi dan akses: */
/* Deklarasi : l : ListFood */
/* Maka cara akses:
   l.nEff      untuk mengetahui banyaknya elemen
   l.buffer    untuk mengakses seluruh nilai elemen list
   l.buffer[i] untuk mengakses elemen ke-i */
/* Definisi :
  list kosong: l.nEff = 0
  Definisi elemen pertama : l.buffer[i] dengan i=0
  Definisi elemen terakhir yang terdefinisi: l.buffer[i] dengan i=l.capacity */

/* ********** SELEKTOR ********** */
#define NEFF(l) (l).nEff
#define BUFFER(l) (l).buffer
#define ELMT(l, i) (l).buffer[i]
#define CAPACITY(l) (l).capacity

/* ********** KONSTRUKTOR ********** */
/*
Konstruktor : create list kosong
I.S. l sembarang, capacity > 0
F.S. Terbentuk list dinamis l kosong dengan kapasitas capacity
*/
void create_list_food(ListFood *l, int capacity){
    CAPACITY(*l) = capacity;
    NEFF(*l) = 0;
    BUFFER(*l) = malloc(capacity*sizeof(food_t));
}
/*
I.S. l terdefinisi;
F.S. (l) dikembalikan ke system, CAPACITY(l)=0; NEFF(l)=0 */
void deallocate_list_food(ListFood *l){
    CAPACITY(*l) = 0;
    NEFF(*l) = 0;
    free(BUFFER(*l));
}
/*
Banyaknya elemen
Mengirimkan banyaknya elemen efektif list
Mengirimkan nol jika list l kosong
Daya tampung container *** */
int list_food_length(ListFood l){
    return NEFF(l);
}

/* Mengirimkan true jika list l kosong, mengirimkan false jika tidak */
boolean list_food_is_empty(ListFood l){
    return (NEFF(l)==0);
}

/* Mengirimkan true jika list l penuh, mengirimkan false jika tidak */
boolean list_food_is_full(ListFood l){
    return NEFF(l) == CAPACITY(l);
}   

/* I.S. lIn terdefinisi tidak kosong, lOut sembarang
F.S. lOut berisi salinan dari lIn (identik, nEff dan capacity sama)
Proses : Menyalin isi lIn ke lOut */
void list_food_copy(ListFood lIn, ListFood *lOut){
    deallocate_list_food(lOut);
    create_list_food(lOut,CAPACITY(lIn));
    NEFF(*lOut) = NEFF(lIn);
    for(int i = 0; i < list_food_length(lIn); i++){
        ELMT(*lOut,i) = ELMT(lIn,i);
    }
}

void list_food_delete(ListFood * l , int idx){
    for (int i = idx; i < list_food_length(*l) - 1; i++){
        ELMT(*l,i) = ELMT(*l,i+1);
    }
    NEFF(*l)--;
}

/* Menghasilkan berapa banyak kemunculan food dengan ID yang sama dengan val di l
Jika l kosong menghasilkan 0 */
int list_food_count_val(ListFood l, food_t val){
    int count = 0;
    for (int i=0;i<list_food_length(l);i++){
        if (FOOD_ID(ELMT(l,i))==FOOD_ID(val)){
            count ++;
        }
    }
    return count;
}

/* IDX_UNDEF jika kosong, 0 jika tidk kosong */
int list_food_get_idx_head(ListFood l){
    if (list_food_is_empty(l)){
        return IDX_UNDEF;
    } else {
        return 0;
    }
}

/* IDX_UNDEF jika kosong, neff-1 jika idak kosong*/
int list_food_get_idx_tail(ListFood l){
    if (list_food_is_empty(l)){
        return IDX_UNDEF;
    } else {
        return (NEFF(l)-1);
    }
}

/*
Proses : Menambahkan capacity l sebanyak num
I.S. List sudah terdefinisi
F.S. Ukuran list bertambah sebanyak num */
void expand_list_food(ListFood *l, int num){
    ListFood l2;
    create_list_food(&l2, CAPACITY(*l) + num);
    NEFF(l2) = NEFF(*l);
    for(int i = 0; i < list_food_length(*l); i++){
        ELMT(l2, i) = ELMT(*l, i);
    }
    free(BUFFER(*l));
    *l = l2;
}

/* Proses : Mengurangi capacity sebanyak num
I.S. List sudah terdefinisi, ukuran capacity > num, dan nEff < capacity - num.
F.S. Ukuran list berkurang sebanyak num. */
void shrink_list_food(ListFood *l, int num){
    ListFood l2; 
    create_list_food(&l2, CAPACITY(*l) - num);
    NEFF(l2) = NEFF(*l);
    if(NEFF(l2) > CAPACITY(l2)){
        NEFF(l2) = CAPACITY(l2);
    }
    for(int i = 0; i < list_food_length(*l); i++){
        ELMT(l2, i) = ELMT(*l, i);
    }
    *l = l2;
}

/* Proses : Mengubah capacity sehingga nEff = capacity
I.S. List tidak kosong
F.S. Ukuran nEff = capacity */
void compress_list_food(ListFood *l){
    shrink_list_food(l,CAPACITY(*l)-NEFF(*l));
}

/*
Memasukkan food ke dalam list.
List food diibaratkan sebagai priority queue, dengan kata lain,
sebagai sorted list dengan waktu kadaluarsa paling kecil diprioritaskan
dalam queue

Proses enqueue mencari posisi yang tepat bagi val, lalu menggeser elemen
lain bila diperlukan

Periksa is_full!
jika penuh, panggil fungsi expand list
*/
void enqueue_food(ListFood *l, food_t val){
    if (list_food_is_full(*l)){
        expand_list_food(l,CAPACITY(*l));
    }
    int i = list_food_length(*l);
    while (i>0){
        if (TGT(FOOD_EXPIRE_TIME(ELMT(*l,i-1)),FOOD_EXPIRE_TIME(val))){
            ELMT(*l,i) = ELMT(*l,i-1);
            i--;
        } else{
            ELMT(*l,i) = val;
            NEFF(*l)++;
            return;
        }
    }
    ELMT(*l,0) = val;
    NEFF(*l)++;
}

/*
Melakukan proses dequeue list
elemen yang dikeluarkan adalah elemen dengan food_id tertentu dan kadaluarsa
paling dekat.
Pastikan elemen tetap terurut sebelum dan sesudah proses dequeue

return value 0 jika proses berjalan dengan lancar
return value -1 jika tidak ditemukan makanan dengan id food_id atau jika list kosong
*/
int dequeue_food(ListFood *l, int food_id, food_t *val){
    int i = 0;
    while(i<list_food_length(*l)){
        if (FOOD_ID(ELMT(*l,i))== food_id){
            *val = ELMT(*l,i);
            list_food_delete(l,i);
            return 0;
        } else{ i++;}
    }
    return -1;
}

/*
Menghitung banyaknya makanan dengan id food_id pada list_food
return nol jika tidak ada, return banyaknya jika ada
*/
int food_count(ListFood l, int food_id){
    int count =0;
    for (int i =0;i<list_food_length(l);i++){
        if (FOOD_ID(ELMT(l,i))==food_id){
            count++;
        }
    }
    return count;
}

/* Proses : Menampilkan isi list ke layar */
void display_list_food(ListFood l){
    printf("--------------------------------------\n");
    for (int i =0;i<list_food_length(l);i++){
        display_food(ELMT(l,i));
        printf("--------------------------------------\n");
    }
}
#endif