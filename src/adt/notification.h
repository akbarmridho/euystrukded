#ifndef __NOTIFICATION_H
#define __NOTIFICATION_H

#include "string.h"

#define CAPACITY 100
#define IDX_MIN 0 
#define IDX_UNDEF -1
#define MARK '\0'
#define MARK_LIST "999"

typedef string notification;
typedef int idxtype;
typedef string Eltype;

typedef struct
{
    notification notifications[CAPACITY];
    // ubah sesuai dengan implementasi
} ListNotification;

#define notif(n, i) (n).notifications[(i)]

// list of string
// implementasi list boleh list statik atau dinamik

// ------------KONSTRUKTOR------------ //
void create_notification (ListNotification *n);
/* I.S. n sembarang 
   F.S. n kosong*/

/* -----------PRIMITIF LAIN------------ */
boolean is_empty(ListNotification n);
/* mengembalikan true apabila List Nofitifikasi kosong */

boolean is_idx_valid(ListNotification n, idxtype i);
/* Mengirimkan true jika i adalah indeks yang valid utk kapasitas List n */
/* yaitu antara indeks yang terdefinisi utk container*/

boolean is_idx_eff(ListNotification n, idxtype i);
/* Mengirimkan true jika i adalah indeks yang terdefinisi utk List n */

int list_length(ListNotification n);
/* Mengembalikan panjang list notifikasi */

boolean compare_str_notif(notification n, string s);
/* Mengembalikan nilai true apabila suatu notifikasi sama dengan sebuah string */

int get_last_idx(ListNotification n);
/* Mengembalikan indeks terakhir dari list notifikasi */

void insert_last(ListNotification *n, Eltype s);
/* I.S. n terdefinisi, n mungkin kosong
   F.S. s adalah elemen terakhir dari List Notifikasi */

void delete_last(ListNotification *n, Eltype *val);
/* I.S. n terdefinisi
   F.S. n kosong, panjang n adalah 0 */

void delete_list(ListNotification *n);
/* I.S. n terdefinisi dan tidak kosong
   F.S. n kosong */

void print_notification(ListNotification n);
/* I.S. n terdefinisi, n mungkin kosong
   F.S. mencetak isi List Notifikasi */
#endif