#include "matrix.h"
#include <stdio.h>

void create_matrix(int nRows, int nCols, Matrix *m) {
    MAT_ROW_EFF(*m) = nRows;
    MAT_COL_EFF(*m) = nCols;
}

boolean is_matrix_idx_valid(int i, int j) {
    return (i >= 0 && i < ROW_CAP) && (j >= 0 && j < COL_CAP);
}

IdxType mat_get_last_idx_row(Matrix m) {
    return MAT_ROW_EFF(m) - 1;
}

IdxType mat_get_last_idx_col(Matrix m) {
    return MAT_COL_EFF(m) - 1;
}

boolean mat_is_idx_eff(Matrix m, IdxType i, IdxType j) {
    return i >= 0 && i <= mat_get_last_idx_row(m) && j >= 0 && j <= mat_get_last_idx_col(m);
}

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