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

void pto_native_str(char *output, string input) {
    output = malloc(neff(input) + 1);

    for (int i = 0; i < neff(input); i++) {
        output[i] = letter_at(input, i);
    }

    output[neff(input)] = '\0';
}

int read_next_int(FILE *file) {
    int result = 0;
    char val = fgetc(file); // NOLINT(cppcoreguidelines-narrowing-conversions)

    while (val != '\n' && val != ' ' && val != EOF) {

        if (val >= '0' && val <= '9') {
            result = result * 10 + (val - '0');
        } else {
            printf("Invalid char during read int. Got char %c\n", val);
        }

        val = fgetc(file); // NOLINT(cppcoreguidelines-narrowing-conversions)
    }

    return result;
}

void read_next_line(FILE *file, string *result) {
    new_string(result, 100);

    char val = fgetc(file);// NOLINT(cppcoreguidelines-narrowing-conversions)

    while (val != '\n' && val != EOF) {
        insert_char_last(val, result);
        val = fgetc(file); // NOLINT(cppcoreguidelines-narrowing-conversions)
    }
}