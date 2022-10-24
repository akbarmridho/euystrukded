#include "../../src/adt/matrix.h"
#include <stdio.h>

int main() {
    char maps[5][10] = {
            {'S', '#', '#', '#', '#', '#', '#', '#', '#', '#',},
            {'#', '#', '#', '#', 'T', '#', '#', 'X', '#', '#'},
            {'#', 'M', '#', '#', '#', '#', '#', 'X', '#', '#'},
            {'#', 'X', '#', '#', '#', '#', '#', '#', 'C', '#'},
            {'#', 'X', 'X', 'X', '#', '#', 'F', '#', '#', '#'}
    };

    Matrix map;

    create_matrix(5, 10, &map);

    for (int i = 0; i < 5; i++) {
        for (int j = 0; j < 10; j++) {
            MAT_ELMT(map, i, j) = maps[i][j];
        }
    }

    display_matrix(map);

    return 0;
}