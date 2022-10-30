#include "../../src/adt/notification.h"
#include <stdio.h>

int main() {
    ListNotification ln;
    string wibu = char_to_string("Wibu bau bawang");
    create_notification(&ln);

    printf("len equal to 0 %d \n", n_list_length(ln));
    n_insert_last(&ln, wibu);

    for (int i = 0; i < n_list_length(ln); i++) {
        print_string(notif(ln, i));
        putchar('\n');
    }

    string res;
    n_delete_last(&ln, &res);
    printf("len equal to 0 %d\n", n_list_length(ln));
    print_string(res);
    putchar('\n');

}