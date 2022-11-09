#ifndef ADT_LIST_FOOD_H
#define ADT_LIST_FOOD_H

#include "boolean.h"
#include "food.h"
#include <stdlib.h>
#include <stdio.h>

/*  Kamus Umum */
#define IDX_MIN 0
/* Indeks minimum list */
#define LF_IDX_UNDEF (-1)
/* Indeks tak terdefinisi*/

/* Definisi elemen dan koleksi objek */
typedef int IdxType;
typedef struct {
    food_t *buffer; /* memori tempat penyimpan elemen (container) */
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
void create_list_food(ListFood *l, int capacity);

/*
I.S. l terdefinisi;
F.S. (l) dikembalikan ke system, CAPACITY(l)=0; NEFF(l)=0 */
void deallocate_list_food(ListFood *l);

/*
Banyaknya elemen
Mengirimkan banyaknya elemen efektif list
Mengirimkan nol jika list l kosong
Daya tampung container *** */
int list_food_length(ListFood l);

/* Mengirimkan true jika list l kosong, mengirimkan false jika tidak */
boolean list_food_is_empty(ListFood l);

/* Mengirimkan true jika list l penuh, mengirimkan false jika tidak */
boolean list_food_is_full(ListFood l);

/* I.S. lIn terdefinisi tidak kosong, lOut sembarang
F.S. lOut berisi salinan dari lIn (identik, nEff dan capacity sama)
Proses : Menyalin isi lIn ke lOut */
void list_food_copy(ListFood lIn, ListFood *lOut);


/*
I.S. l tidak kosong, l sembarang, idx valid pada l
F.S. element pada index idx dihapus
*/
void list_food_delete(ListFood *l, int idx);

/* Menghasilkan berapa banyak kemunculan val di l
Jika l kosong menghasilkan 0 */
int list_food_count_val(ListFood l, food_t val);

/* IDX_UNDEF jika kosong, 0 jika tidk kosong */
int list_food_get_idx_head(ListFood l);

/* IDX_UNDEF jika kosong, neff-1 jika idak kosong*/
int list_food_get_idx_tail(ListFood l);

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
void enqueue_food(ListFood *l, food_t val);

/*
Melakukan proses dequeue list
elemen yang dikeluarkan adalah elemen dengan food_id tertentu dan kadaluarsa
paling dekat.
Pastikan elemen tetap terurut sebelum dan sesudah proses dequeue

return value 0 jika proses berjalan dengan lancar
return value -1 jika tidak ditemukan makanan dengan id food_id atau jika list kosong
*/
int dequeue_food(ListFood *l, int food_id, food_t *val);

/*
Menghitung banyaknya makanan dengan id food_id pada list_food
return nol jika tidak ada, return banyaknya jika ada
*/
int food_count(ListFood l, int food_id);

/*
Proses : Menambahkan capacity l sebanyak num
I.S. List sudah terdefinisi
F.S. Ukuran list bertambah sebanyak num */
void expand_list_food(ListFood *l, int num);

/* Proses : Mengurangi capacity sebanyak num
I.S. List sudah terdefinisi, ukuran capacity > num, dan nEff < capacity - num.
F.S. Ukuran list berkurang sebanyak num. */
void shrink_list_food(ListFood *l, int num);

/* Proses : Mengubah capacity sehingga nEff = capacity
I.S. List tidak kosong
F.S. Ukuran nEff = capacity */
void compress_list_food(ListFood *l);

/* Proses : Menampilkan isi list ke layar */
void display_list_food(ListFood l);

int find_food (string name, ListFood f);

int get_food_id_from_name(string name, ListFood f);

#endif