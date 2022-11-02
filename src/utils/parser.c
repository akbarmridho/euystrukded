#include "parser.h"
#include <stdlib.h>

char *to_native_str(string str) {
    char *result;

    result = malloc(neff(str) + 1);

    for (int i = 0; i < neff(str); i++) {
        result[i] = letter_at(str, i);
    }

    result[neff(str)] = '\0';

    return result;
}
