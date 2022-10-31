#ifndef UTILS_VALIDATOR_H
#define UTILS_VALIDATOR_H

#include "../adt/string.h"
#include "parser.h"
#include <stdio.h>

/* inputs an integer x and returns x if min<=x<=max, else input x until x satisfies range */
int validate_int(int min, int max, string prompt) {
    print_string(prompt);
    putchar('\n');

    advance_word();
    string input = word_to_string(current_word);
    int x;

    sscanf(to_native_str(input), "%d", &x);

    while (x < min || x > max) {
        printf("Input harus berada di antar %d dan %d\n", min, max);
        advance_word();
        deallocate_string(&input);
        input = word_to_string(current_word);
        sscanf(to_native_str(input), "%d", &x);
    }

    deallocate_string(&input);

    return x;
}

#endif