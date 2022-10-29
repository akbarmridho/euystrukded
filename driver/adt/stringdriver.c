#include "../../src/adt/string.h"
#include <stdio.h>

int main() {
    char a[] = "salomo";
    string str;
    new_string(&str, 100);
    printf("Halo %s", a);

    str = char_to_string(a);
    print_string(str);

    printf("%s", &a);

    return 0;
}