#include "../../src/adt/string.h"
#include <stdio.h>

int main() {
    char a[] = "salomo";
    printf("Halo %s", a);

    string str = char_to_string(a);
    print_string(str);

    printf("%s\n", a);

    return 0;
}