#include "../../src/adt/notification.h"
#include "../../src/adt/string.h"
#include <stdio.h>

int main() {
    ListNotification ln;
    char a[] = "Bawang";
    char b[] = "Babi";
    string str;
    create_notification(&ln);

    printf("%s \n", a);

    new_string(&str, MAX);
    printf("%s \n", a);

    str = char_to_string(a);
    printf("%s \n", a);


    // n_insert_last(&ln, str);
    printf("%d \n", n_list_length(ln));
    printf("%s", b);

}