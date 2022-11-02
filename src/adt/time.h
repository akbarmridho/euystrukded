/* File: time.h */
/* Definisi ADT TIME */

#ifndef ADT_TIME_H
#define ADT_TIME_H

#include "boolean.h"

/* *** Definisi TYPE TIME <hh:mm:SS> *** */
typedef struct {
    int dd; /* integer >= 0 */
    int hh; /* integer [0..23] */
    int mm; /* integer [0..59] */
} day_time_t;

/* *** Notasi Akses: selektor TIME *** */
#define DAY(T) (T).dd
#define HOUR(T) (T).hh
#define MINUTE(T) (T).mm

/*
Konstruktor: Membentuk sebuah TIME dari komponen-komponennya
Membentuk sebuah TIME dari komponen-komponennya yang valid
Prekondisi : d,h,m valid untuk membentuk TIME
*/
void create_time(day_time_t *t, int d, int h, int m);

/*
I.S. : T sembarang
F.S. : Nilai T ditulis dg format HH:MM
Proses : menulis nilai setiap komponen T ke layar dalam format HH:MM
tanpa karakter apa pun di depan atau belakangnya, termasuk spasi, enter, dll.
Hanya menampilkan jam dan menit, tidak termasuk hari
*/
void write_time(day_time_t t);

/*
 * Menuliskan hari
 */
void write_day(day_time_t t);

/*
 * Menuliskan hari dan waktu
 */
void write_fulltime(day_time_t t);

/*
Diberikan sebuah TIME, mengonversi jumlah menit dari hari ke-nol menuju menit terakhir pada hari tertentu
Rumus : menit = 24*60*day + 60*hour + menit
*/
long time_to_minute(day_time_t t);

/*
Mengonversi menit ke waktu, dimulai dari day nol
*/
day_time_t minute_to_time(long N);

/*
Mengonversi menit ke waktu, dimulai dari day nol, versi pointer
*/
void pminute_to_time(long N, day_time_t *result);

/* Mengirimkan true jika T1=T2 (bagian jam dan menit), false jika tidak */
boolean TEQ(day_time_t t1, day_time_t t2);

/* Mengirimkan true jika T1=T2, false jika tidak */
boolean DTEQ(day_time_t t1, day_time_t t2);

/* Mengirimkan true jika T1<T2 (bagian jam dan menit), false jika tidak */
boolean TLT(day_time_t t1, day_time_t t2);

/* Mengirimkan true jika T1<T2, false jika tidak */
boolean DTLT(day_time_t t1, day_time_t t2);

/* Mengirimkan true jika T1>T2 (bagian jam dan menit), false jika tidak */
boolean TGT(day_time_t t1, day_time_t t2);

/* Mengirimkan true jika T1>T2, false jika tidak */
boolean DTGT(day_time_t t1, day_time_t t2);

/* Menambahkan time t sebanyak n menit*/
void pnext_n_minute(day_time_t *t, int n);

/* Mengurangi time t sebanyak n menit*/
void pprev_n_minute(day_time_t *t, int n);

/* Mengirim N menit setelah T dalam bentuk TIME */
day_time_t next_n_minute(day_time_t t, int n);

/* Mengirim N menit sebelum T dalam bentuk TIME */
day_time_t prev_n_minute(day_time_t t, int n);

/*
Mengirim t_final-t_initial dlm menit, dengan kalkulasi
asumsikan t_final >= t_initial
*/
long time_duration(day_time_t t_initial, day_time_t t_final);

#endif