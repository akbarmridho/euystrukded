#include <stdio.h>
#include "notification.h"
#include "string.h"
#include "boolean.h"

// ------------KONSTRUKTOR------------ //

/* I.S. n sembarang 
   F.S. n kosong*/
void create_notification (ListNotification *n) {
    int i;
    string s;

    new_string(&s, CAPACITY);
    for (i = IDX_MIN; i < CAPACITY; i++) {
        notif(*n, i) = s ;
    }
}

/* -----------PRIMITIF LAIN------------ */

/* mengembalikan true apabila List Nofitifikasi kosong */
boolean is_empty(ListNotification n) {
    return (list_length(n) == 0);
}

/* Mengirimkan true jika i adalah indeks yang valid utk kapasitas List n */
/* yaitu antara indeks yang terdefinisi utk container*/
boolean is_idx_valid(ListNotification n, idxtype i) {
    return (i >= IDX_MIN && i <= CAPACITY);
}

/* Mengirimkan true jika i adalah indeks yang terdefinisi utk List n */
boolean is_idx_eff(ListNotification n, idxtype i) {
    return (i >= IDX_MIN && i < get_last_idx(n));
}

/* Mengembalikan panjang list notifikasi */
int list_length(ListNotification n) {
    int i = 0;
    boolean mark = false;
    string s; // jadi mark
    notification mark;
    new_string(&s, CAPACITY);
    
    if (is_empty(n)) {
        return 0;
    } else {
        while ((mark == false) && (i < MAX)) {
            if (compare_str_notif(notif(n,i),s)) {
                mark = true;
            } else {
                i += 1;
            }
        } 
        return i;
    }
}

/* Mengembalikan nilai true apabila suatu notifikasi sama dengan sebuah string */
boolean compare_str_notif(notification n, string s){
    int i = 0;
    boolean same = false;

    if (str_len(n) != str_len(s)) {
        same = false;
    } else {
        while (i < str_len(s) && same == true) {
            if (char(n,i) == char(s,i)) {
                i += 1;
            } else {
                same = false;
            }
        }
    }

    return same;
}

/* Mengembalikan indeks terakhir dari list notifikasi */
int get_last_idx(ListNotification n) {
    if (isEmpty(n)) {
        return UNDEF;
    } else {
        return (list_length(n) - 1);
    }
}

/* I.S. n terdefinisi, n mungkin kosong
   F.S. s adalah elemen terakhir dari List Notifikasi */
void insert_last(ListNotification *n, Eltype s) {
    notif(*n, list_length(*n)) = s;
}

/* I.S. n terdefinisi
   F.S. n kosong, panjang n adalah 0 */
void delete_last(ListNotification *n, Eltype *val) {
    string s;
    new_string(&s,CAPACITY);

    *val = notif(*n, get_last_idx(*n));
    notif(*n, get_last_idx(*n)) = s;
}

/* I.S. n terdefinisi dan tidak kosong
   F.S. n kosong */
void delete_list(ListNotification *n) {
    int i, pnjg = list_length(*n);
    Eltype val;

    for (i = 0; i < pnjg; i++) {
        delete_last(&n, &val);
    }
}

/* I.S. n terdefinisi, n mungkin kosong
   F.S. mencetak isi List Notifikasi */
void print_notification(ListNotification n) {
    int i;

   if (list_length(n) == 0) {
        printf("-");
    }
    else {
        for (i = 0; i <= get_last_idx(n)-1; i++) {
            printf("i+1. %c,", notif(n, i));
        }
    }
}

/* I.S. n terdefinisi, n tidak kosong 
   F.S. copy paste n1 ke dalam n2 */
ListNotification copy_notification(ListNotification n1, ListNotification n2) {
    int i = 0;
    create_notification(&n2);

    for (i = 0; i < list_length(n1); i++) {
        insert_last(&n2,notif(n1,i));
    }

    return n2;
}