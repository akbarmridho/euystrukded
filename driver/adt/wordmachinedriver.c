#include <stdio.h>
#include "../../src/adt/charmachine.h"
#include "../../src/adt/wordmachine.h"
#include "../../src/adt/string.h"

word_t current_word;
boolean end_word;

int main() {
    start_word();

    while (!end_word) {
        string val = word_to_string(current_word);
        printf("Read string ");
        print_string(val);
        putchar('\n');

        advance_word();
    }
}