#ifndef ADT_NOTIFICATION_H
#define ADT_NOTIFICATION_H

#include "string.h"

#define NOTIFCAPACITY 200
#define IDX_MIN 0

typedef string notification;
typedef int idxtype;
typedef string Eltype;

typedef struct {
    notification notifications[NOTIFCAPACITY];
    int length;
    // ubah sesuai dengan implementasi
} ListNotification;

#define notif(n, i) (n).notifications[(i)]
#define length(n) (n).length

// list of string
// implementasi list boleh list statik atau dinamik

// ------------KONSTRUKTOR------------ //

/* I.S. n sembarang 
   F.S. n kosong*/
void create_notification(ListNotification *n);

/* -----------PRIMITIF LAIN------------ */

/* mengembalikan true apabila List Nofitifikasi kosong */
boolean n_is_empty(ListNotification n);

/* Mengirimkan true jika i adalah indeks yang valid utk kapasitas List n */
/* yaitu antara indeks yang terdefinisi utk container*/
boolean n_is_idx_valid(ListNotification n, idxtype i);

/* Mengirimkan true jika i adalah indeks yang terdefinisi utk List n */
boolean n_is_idx_eff(ListNotification n, idxtype i);

/* Mengembalikan panjang list notifikasi */
int n_list_length(ListNotification n);

/* Mengembalikan nilai true apabila suatu notifikasi sama dengan sebuah string */
boolean compare_str_notif(notification n, string s);

/* Mengembalikan indeks terakhir dari list notifikasi */
int n_get_last_idx(ListNotification n);

/* I.S. n terdefinisi, n mungkin kosong
   F.S. s adalah elemen terakhir dari List Notifikasi */
void n_insert_last(ListNotification *n, Eltype s);

/* I.S. n terdefinisi
   F.S. n kosong, panjang n adalah 0 */
void n_delete_last(ListNotification *n, Eltype *val);

/* I.S. n terdefinisi dan tidak kosong
   F.S. n kosong */
void n_delete_list(ListNotification *n);

/* I.S. n terdefinisi, n tidak kosong 
   F.S. copy paste n1 ke dalam n2 */
void copy_notification(ListNotification lIn, ListNotification *lOut);

#endif