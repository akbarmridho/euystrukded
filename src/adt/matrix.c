#include "matrix.h"
#include <stdio.h>

/*
 * Membuat matriks kosong
 */
void create_matrix(int nRows, int nCols, Matrix *m) {
    MAT_ROW_EFF(*m) = nRows;
    MAT_COL_EFF(*m) = nCols;
}

/*
 * Mengembalikan indeks baris terakhir
 */
IdxType mat_get_last_idx_row(Matrix m) {
    return MAT_ROW_EFF(m) - 1;
}

/*
 * Mengembalikan indeks kolom terakhir
 */
IdxType mat_get_last_idx_col(Matrix m) {
    return MAT_COL_EFF(m) - 1;
}

/*
 * Mengecek apakah indeks matriks balik
 */
boolean mat_is_idx_valid(Matrix m, int i, int j) {
    return i >= 0 && j >= 0 && j <= mat_get_last_idx_col(m) && i <= mat_get_last_idx_row(m);
}

/*
 * Menampilkan isi matriks, dengan elemen # dianggap kosong
 */
void display_matrix(Matrix m) {
    for (int i = 0; i < MAT_COL_EFF(m) + 2; i++) {
        putchar('*');
    }
    putchar('\n');

    for (int i = 0; i < MAT_ROW_EFF(m); i++) {
        putchar('*');

        for (int j = 0; j < MAT_COL_EFF(m); j++) {
            char elmt = MAT_ELMT(m, i, j);

            if (elmt == '#') {
                elmt = ' ';
            }

            putchar(elmt);
        }

        printf("*\n");
    }

    for (int i = 0; i < MAT_COL_EFF(m) + 2; i++) {
        putchar('*');
    }
    putchar('\n');
}