/* File: point.h */
/* Tanggal: 3 September 2022 */
/* *** Definisi ABSTRACT DATA TYPE POINT *** */

#ifndef ADT_POINT_H
#define ADT_POINT_H

#include "boolean.h"

typedef struct {
    int x; /* absis   */
    int y; /* ordinat */
} point_t;

/* *** Notasi Akses: Selektor point_t *** */
#define ABSIS(p) (p).x
#define ORDINAT(p) (p).y

/* Membentuk sebuah point_t dari komponen-komponennya */
void create_point(point_t *p, int x, int y);

/*
Nilai p ditulis ke layar dengan format "(X,Y)"
tanpa spasi, enter, atau karakter lain di depan, belakang,
atau di antaranya
Output X dan Y harus dituliskan dalam bilangan riil dengan 2 angka di belakang koma.
I.S. p terdefinisi
F.S. p tertulis di layar dengan format "(X,Y)"
*/
void write_point(point_t p);

/* Mengirimkan true jika p1 = p2 : absis dan ordinatnya sama */
boolean is_point_equal(point_t p1, point_t p2);

/* Mengirim salinan p yang absisnya adalah Absis(p) + deltaX dan ordinatnya adalah Ordinat(p) + deltaY */
point_t point_plus_delta(point_t p, int delta_x, int delta_y);

/*
I.S. p terdefinisi
F.S. p digeser, absisnya sebesar deltaX dan ordinatnya sebesar deltaY\
*/
void point_move(point_t *p, int delta_x, int delta_y);

#endif