#include "../../src/adt/parsermachine.h"
#include <stdio.h>

int main() {
    start_line("example.txt");

    int j = 0;
    do {
        for (int i = 0; i < current_line.length; i++) {
            putchar(current_line.tab_word[i]);
        }
        printf("\n");
        advance_line();
        j++;

        if (j >= 10) {
            printf("SOMETHING WRONG\n");
            break;
        }
    } while (!end_line);

    return 0;
}