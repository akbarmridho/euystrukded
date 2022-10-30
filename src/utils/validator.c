#ifndef UTILS_VALIDATOR_H
#define UTILS_VALIDATOR_H

#include "../adt/string.h"
#include <stdio.h>

/* inputs an integer x and returns x if min<=x<=max, else input x until x satisfies range */
int validate_int(int min, int max, string prompt) {
    int x;
    print_string(prompt);
    putchar('\n');
    scanf("%d", &x);

    while (x < min || x > max) {
        print_string(prompt);
        putchar('\n');
        scanf("%d", &x);
    }
    return x;
}

#endif