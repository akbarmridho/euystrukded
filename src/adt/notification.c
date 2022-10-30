#include "notification.h"
#include "string.h"
#include "boolean.h"

// ------------KONSTRUKTOR------------ //

/* I.S. n sembarang 
   F.S. n kosong*/
void create_notification(ListNotification *n) {
    length(*n) = 0;
}

/* -----------PRIMITIF LAIN------------ */

/* mengembalikan true apabila List Nofitifikasi kosong */
boolean n_is_empty(ListNotification n) {
    return (n_list_length(n) == 0);
}

/* Mengirimkan true jika i adalah indeks yang valid utk kapasitas List n */
/* yaitu antara indeks yang terdefinisi utk container*/
boolean n_is_idx_valid(ListNotification n, idxtype i) {
    return (i >= IDX_MIN && i <= NOTIFCAPACITY);
}

/* Mengirimkan true jika i adalah indeks yang terdefinisi utk List n */
boolean n_is_idx_eff(ListNotification n, idxtype i) {
    return (i >= IDX_MIN && i < n_get_last_idx(n));
}

/* Mengembalikan panjang list notifikasi */
int n_list_length(ListNotification n) {
    return (length(n));
}

/* Mengembalikan nilai true apabila suatu notifikasi sama dengan sebuah string */
boolean compare_str_notif(notification n, string s) {
    int i = 0;
    boolean same = true;

    if (str_len(n) != str_len(s)) {
        same = false;
    } else {
        while (i < str_len(s) && same) {
            if (char(n, i) == char(s, i)) {
                i += 1;
            } else {
                same = false;
            }
        }
    }

    return same;
}

/* Mengembalikan indeks terakhir dari list notifikasi */
int n_get_last_idx(ListNotification n) {
    if (n_is_empty(n)) {
        return UNDEF;
    } else {
        return (n_list_length(n) - 1);
    }
}

/* I.S. n terdefinisi, n mungkin kosong
   F.S. s adalah elemen terakhir dari List Notifikasi */
void n_insert_last(ListNotification *n, Eltype s) {
    notif(*n, n_list_length(*n)) = s;
    length(*n) += 1;
}

/* I.S. n terdefinisi
   F.S. n kosong, panjang n adalah 0 */
void n_delete_last(ListNotification *n, Eltype *val) {
    *val = notif(*n, n_get_last_idx(*n));
    length(*n) -= 1;
}

/* I.S. n terdefinisi dan tidak kosong
   F.S. n kosong */
void n_delete_list(ListNotification *n) {
    int i, len = n_list_length(*n);
    Eltype val;

    for (i = 0; i < len; i++) {
        n_delete_last(n, &val);
    }
}

/* I.S. n terdefinisi, n mungkin kosong
   F.S. mencetak isi List Notifikasi */

/* I.S. n terdefinisi, n tidak kosong 
   F.S. copy paste n1 ke dalam n2 */
void copy_notification(ListNotification lIn, ListNotification *lOut) {
    create_notification(lOut);

    for (int i = 0; i < n_list_length(lIn); i++) {
        n_insert_last(lOut, notif(lIn, i));
    }
}