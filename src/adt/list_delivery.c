#include "boolean.h"
#include "list_delivery.h"
#include "list_food.h"
#include <stdio.h>
#include <stdlib.h>

/* ********** KONSTRUKTOR ********** */
/*
Konstruktor : create list kosong
I.S. l sembarang, capacity > 0
F.S. Terbentuk list dinamis l kosong dengan kapasitas capacity
*/
void create_list_delivery(ListDelivery *l, int capacity) {
    CAPACITY(*l) = capacity;
    NEFF(*l) = 0;
    BUFFER(*l) = malloc(capacity * sizeof(food_t));
}

/*
I.S. l terdefinisi;
F.S. (l) dikembalikan ke system, CAPACITY(l)=0; NEFF(l)=0 */
void deallocate_list_delivery(ListDelivery *l) {
    CAPACITY(*l) = 0;
    NEFF(*l) = 0;
    free(BUFFER(*l));
}

/*
Banyaknya elemen
Mengirimkan banyaknya elemen efektif listlist_deliver
Mengirimkan nol jika list l kosong
Daya tampung container *** */
int list_delivery_length(ListDelivery l) {
    return NEFF(l);
}

/* Mengirimkan true jika list l kosong, mengirimkan false jika tidak */
boolean list_delivery_is_empty(ListDelivery l) {
    return (NEFF(l) == 0);
}

/* Mengirimkan true jika list l penuh, mengirimkan false jika tidak */
boolean list_delivery_is_full(ListDelivery l) {
    return NEFF(l) == CAPACITY(l);
}

/* I.S. lIn terdefinisi tidak kosong, lOut sembarang
F.S. lOut berisi salinan dari lIn (identik, nEff dan capacity sama)
Proses : Menyalin isi lIn ke lOut */
void list_delivery_copy(ListDelivery lIn, ListDelivery *lOut) {
    deallocate_list_delivery(lOut);
    create_list_delivery(lOut, CAPACITY(lIn));
    NEFF(*lOut) = NEFF(lIn);
    for (int i = 0; i < list_delivery_length(lIn); i++) {
        ELMT(*lOut, i) = ELMT(lIn, i);
    }
}

/*
I.S. l tidak kosong, l sembarang, idx valid pada l
F.S. element pada index idx dihapus
*/
void list_delivery_delete(ListDelivery *l, int idx) {
    if (idx == list_delivery_length(*l) - 1) {
        NEFF(*l)--;
        return;
    }
    for (int i = idx; i < list_delivery_length(*l) - 1; i++) {
        ELMT(*l, i) = ELMT(*l, i + 1);
    }
    NEFF(*l)--;
}

/* Menghasilkan berapa banyak kemunculan val di l
Jika l kosong menghasilkan 0 */
int list_delivery_count_val(ListDelivery l, food_t val) {
    int count = 0;
    for (int i = 0; i < list_delivery_length(l); i++) {
        if (FOOD_ID(ELMT(l, i)) == FOOD_ID(val)) {
            count++;
        }
    }
    return count;
}

/* IDX_UNDEF jika kosong, 0 jika tidk kosong */
int list_delivery_get_idx_head(ListDelivery l) {
    if (list_delivery_is_empty(l)) {
        return LD_IDX_UNDEF;
    } else {
        return 0;
    }
}

/* IDX_UNDEF jika kosong, neff-1 jika idak kosong*/
int list_delivery_get_idx_tail(ListDelivery l) {
    if (list_delivery_is_empty(l)) {
        return LD_IDX_UNDEF;
    } else {
        return NEFF(l) - 1;
    }
}

/*
Proses : Menambahkan capacity l sebanyak num
I.S. List sudah terdefinisi
F.S. Ukuran list bertambah sebanyak num */
void expand_list_delivery(ListDelivery *l, int num) {
    ListDelivery l2;
    create_list_delivery(&l2, CAPACITY(*l) + num);
    NEFF(l2) = NEFF(*l);
    for (int i = 0; i < list_delivery_length(*l); i++) {
        ELMT(l2, i) = ELMT(*l, i);
    }
    free(BUFFER(*l));
    *l = l2;
}

/* Proses : Mengurangi capacity sebanyak num
I.S. List sudah terdefinisi, ukuran capacity > num, dan nEff < capacity - num.
F.S. Ukuran list berkurang sebanyak num. */
void shrink_list_delivery(ListDelivery *l, int num) {
    ListDelivery l2;
    create_list_delivery(&l2, CAPACITY(*l) - num);
    NEFF(l2) = NEFF(*l);
    if (NEFF(l2) > CAPACITY(l2)) {
        NEFF(l2) = CAPACITY(l2);
    }
    for (int i = 0; i < list_delivery_length(*l); i++) {
        ELMT(l2, i) = ELMT(*l, i);
    }
    *l = l2;
}

/* Proses : Mengubah capacity sehingga nEff = capacity
I.S. List tidak kosong
F.S. Ukuran nEff = capacity */
void compress_list_delivery(ListDelivery *l) {
    shrink_list_delivery(l, CAPACITY(*l) - NEFF(*l));
}

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
void enqueue_delivery(ListDelivery *l, food_t val) {
    if (list_delivery_is_full(*l)) {
        expand_list_delivery(l, CAPACITY(*l));
    }
    int i = list_delivery_length(*l);
    while (i > 0) {
        if (TGT(FOOD_DELIVERY_TIME(ELMT(*l, i - 1)), FOOD_DELIVERY_TIME(val))) {
            ELMT(*l, i) = ELMT(*l, i - 1);
            i--;
        } else {
            ELMT(*l, i) = val;
            NEFF(*l)++;
            return;
        }
    }
    ELMT(*l, 0) = val;
    NEFF(*l)++;
}

/*
Melakukan proses dequeue list
elemen yang dikeluarkan adalah elemen dengan waktu delivery nol
Pastikan elemen tetap terurut sebelum dan sesudah proses dequeue

return value 0 jika proses berjalan dengan lancar
return value -1 jika tidak ditemukan makanan dengan delivery time nol atau jika list kosong
*/
int dequeue_delivery(ListDelivery *l, food_t *val) {
    if (list_delivery_is_empty(*l)) {
        return -1;
    }
    if (time_to_minute(FOOD_DELIVERY_TIME(ELMT(*l, 0))) <= 0) {
        *val = ELMT(*l, 0);
        list_delivery_delete(l, 0);
        return 0;
    }
    return -1;
}

/* Hitung banyaknya makanan yang bisa dideliver sekarang (delivery time nol)*/
int count_to_deliver(ListDelivery *l) {
    int i = 0;
    while (i < list_delivery_length(*l)) {
        if (time_to_minute(FOOD_DELIVERY_TIME(ELMT(*l, i))) <= 0) {
            i++;
        } else {
            return i;
        }
    }
    return 0;
}


/* Proses : Menampilkan isi list ke layar */
void display_list_delivery(ListDelivery l) {
    printf("--------------------------------------\n");
    for (int i = 0; i < list_delivery_length(l); i++) {
        display_food(ELMT(l, i));
        printf("--------------------------------------\n");
    }
}