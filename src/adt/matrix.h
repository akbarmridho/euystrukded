/* ********** Definisi TYPE Matrix dengan Index dan elemen integer ********** */

#ifndef ADT_MATRIX_H
#define ADT_MATRIX_H

#include "boolean.h"

/* Ukuran maksimum baris dan kolom */
#define ROW_CAP 100
#define COL_CAP 100

typedef int IdxType; /* Index baris, kolom */
typedef char ElType;
typedef struct {
    ElType mem[ROW_CAP][COL_CAP];
    int rowEff; /* banyaknya/ukuran baris yg terdefinisi */
    int colEff; /* banyaknya/ukuran kolom yg terdefinisi */
} Matrix;
/* rowEff >= 1 dan colEff >= 1 */
/* Indeks matriks yang digunakan: [0..ROW_CAP-1][0..COL_CAP-1] */
/* Memori matriks yang dipakai selalu di "ujung kiri atas" */

/*
Membentuk sebuah Matrix "kosong" yang siap diisi berukuran nRow x nCol di "ujung kiri" memori
I.S. nRow dan nCol adalah valid untuk memori matriks yang dibuat
F.S. Matriks m sesuai dengan definisi di atas terbentuk
*/
void create_matrix(int nRows, int nCols, Matrix *m);

/* *** Selektor *** */
#define MAT_ROW_EFF(M) (M).rowEff
#define MAT_COL_EFF(M) (M).colEff
#define MAT_ELMT(M, i, j) (M).mem[(i)][(j)]

/* Mengirimkan Index baris terbesar m */
IdxType mat_get_last_idx_row(Matrix m);

/* Mengirimkan Index kolom terbesar m */
IdxType mat_get_last_idx_col(Matrix m);

boolean mat_is_idx_valid(Matrix m, int i, int j);

/* I.S. m terdefinisi
F.S. Nilai m(i,j) ditulis ke layar per baris per kolom, masing-masing elemen per baris
dipisahkan sebuah spasi. Baris terakhir tidak diakhiri dengan newline
Proses: Menulis nilai setiap elemen m ke layar dengan traversal per baris dan per kolom

matriks dengan konten # ditampilkan menjadi spasi
*/
void display_matrix(Matrix m);

#endif