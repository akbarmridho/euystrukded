#ifndef __LIST_DELIVERY_H
#define __LIST_DELIVERY_H

#include "boolean.h"
#include "list_food.h"

/*  didefinisikan di list_food.h */
// #define IDX_MIN 0
// #define IDX_UNDEF -1

/* Definisi elemen dan koleksi objek */
typedef food_t food_t; /* type elemen list */
typedef int IdxType;
typedef struct
{
    food_t *buffer; /* memori tempat penyimpan elemen (container) */
    int nEff;       /* >=0, banyaknya elemen efektif */
    int capacity;   /* ukuran elemen */
} ListDelivery;

/* didefinisikan di list_food.h */
// #define NEFF(l) (l).nEff
// #define BUFFER(l) (l).buffer
// #define ELMT(l, i) (l).buffer[i]
// #define CAPACITY(l) (l).capacity

/* ********** KONSTRUKTOR ********** */
/*
Konstruktor : create list kosong
I.S. l sembarang, capacity > 0
F.S. Terbentuk list dinamis l kosong dengan kapasitas capacity
*/
void create_list_delivery(ListDelivery *l, int capacity);

/*
I.S. l terdefinisi;
F.S. (l) dikembalikan ke system, CAPACITY(l)=0; NEFF(l)=0 */
void deallocate_list_delivery(ListDelivery *l);

/*
Banyaknya elemen
Mengirimkan banyaknya elemen efektif list
Mengirimkan nol jika list l kosong
Daya tampung container *** */
int list_delivery_length(ListDelivery l);

/* Mengirimkan true jika list l kosong, mengirimkan false jika tidak */
boolean list_delivery_is_empty(ListDelivery l);

/* Mengirimkan true jika list l penuh, mengirimkan false jika tidak */
boolean list_delivery_is_full(ListDelivery l);

/* I.S. lIn terdefinisi tidak kosong, lOut sembarang
F.S. lOut berisi salinan dari lIn (identik, nEff dan capacity sama)
Proses : Menyalin isi lIn ke lOut */
void list_delivery_copy(ListDelivery lIn, ListDelivery *lOut);

/* Menghasilkan berapa banyak kemunculan val di l
Jika l kosong menghasilkan 0 */
int list_delivery_count_val(ListDelivery l, food_t val);

/* IDX_UNDEF jika kosong, 0 jika tidk kosong */
int list_delivery_get_idx_head(ListDelivery l);

/* IDX_UNDEF jika kosong, neff-1 jika idak kosong*/
int list_delivery_get_idx_tail(ListDelivery l);

/*
Memasukkan food ke dalam list.
List food diibaratkan sebagai priority queue, dengan kata lain,
sebagai sorted list dengan waktu pengiriman paling kecil diprioritaskan
dalam queue

Proses enqueue mencari posisi yang tepat bagi val, lalu menggeser elemen
lain bila diperlukan

Periksa is_full!
jika penuh, panggil fungsi expand list
*/
void enqueue_delivery(ListDelivery *l, food_t val);

/*
Melakukan proses dequeue list
elemen yang dikeluarkan adalah elemen dengan waktu delivery nol
Pastikan elemen tetap terurut sebelum dan sesudah proses dequeue

return value 0 jika proses berjalan dengan lancar
return value -1 jika tidak ditemukan makanan dengan delivery time nol atau jika list kosong
*/
int dequeue_delivery(ListDelivery *l, food_t *val);

/* Hitung banyaknya makanan yang bisa dideliver sekarang (delivery time nol)*/
int count_to_deliver(ListDelivery *l);
/*
Proses : Menambahkan capacity l sebanyak num
I.S. List sudah terdefinisi
F.S. Ukuran list bertambah sebanyak num */
void expand_list_delivery(ListDelivery *l, int num);

/* Proses : Mengurangi capacity sebanyak num
I.S. List sudah terdefinisi, ukuran capacity > num, dan nEff < capacity - num.
F.S. Ukuran list berkurang sebanyak num. */
void shrink_list_delivery(ListDelivery *l, int num);

/* Proses : Mengubah capacity sehingga nEff = capacity
I.S. List tidak kosong
F.S. Ukuran nEff = capacity */
void compress_list_delivery(ListDelivery *l);

#endif