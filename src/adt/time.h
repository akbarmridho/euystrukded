/* File: time.h */
/* Definisi ADT TIME */

#ifndef TIME_H
#define TIME_H

#include "boolean.h"

/* *** Definisi TYPE TIME <hh:mm:SS> *** */
typedef struct
{
   int dd; /* integer >= 0 */
   int hh; /* integer [0..23] */
   int mm; /* integer [0..59] */
} time_t;

/* *** Notasi Akses: selektor TIME *** */
#define DAY(T) (T).dd
#define HOUR(T) (T).hh
#define MINUTE(T) (T).mm

/*
Mengirim true jika d,h,m dapat membentuk T yang valid
dipakai untuk mentest SEBELUM membentuk sebuah Jam
*/
boolean is_time_valid(int d, int h, int m);

/*
Konstruktor: Membentuk sebuah TIME dari komponen-komponennya
Membentuk sebuah TIME dari komponen-komponennya yang valid
Prekondisi : d,h,m valid untuk membentuk TIME
*/
void create_time(time_t *t, int d, int h, int m);

/*
I.S. : T sembarang
F.S. : Nilai T ditulis dg format HH:MM
Proses : menulis nilai setiap komponen T ke layar dalam format HH:MM
tanpa karakter apa pun di depan atau belakangnya, termasuk spasi, enter, dll.
Hanya menampilkan jam dan menit, tidak termasuk hari
*/
void write_time(time_t t);

/*
Diberikan sebuah TIME, mengonversi jumlah menit dari hari ke-nol menuju menit terakhir pada hari tertentu
Rumus : menit = 24*60*day + 60*hour + menit
*/
long time_to_minute(time_t t);

/*
Mengonversi menit ke waktu, dimulai dari day nol
*/
time_t minute_to_time(long N);

/* Mengirimkan true jika T1=T2, false jika tidak */
boolean TEQ(time_t t1, time_t t2);

/* Mengirimkan true jika T1<T2, false jika tidak */
boolean TLT(time_t t1, time_t t2);

/* Mengirimkan true jika T1>T2, false jika tidak */
/* *** Operator aritmatika TIME *** */
boolean TGT(time_t t1, time_t t2);

/* Menambahkan time t sebanyak n menit*/
void pnext_n_minute(time_t *t, int n);

/* Mengurangi time t sebanyak n menit*/
void pprev_n_minute(time_t *t, int n);

/* Mengirim N menit setelah T dalam bentuk TIME */
time_t next_n_minute(time_t t, int n);

/* Mengirim N menit sebelum T dalam bentuk TIME */
time_t prev_n_minute(time_t t, int n);

/*
Mengirim t_final-t_initial dlm menit, dengan kalkulasi
asumsikan t_final >= t_initial
*/
long time_duration(time_t t_initial, time_t t_final);

#endif