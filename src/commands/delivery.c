#include "delivery.h"

void display_delivery() {
    printf("List Makanan di Perjalanan\n");
    printf("(nama - waktu sisa delivery)\n");

    if (list_delivery_length(delivery) == 0) {
        printf("Tidak ada makanan dalam perjalanan\n");
    } else {
        for (int i = 0; i < list_delivery_length(delivery); i++) {
            printf("    ");
            printf("%d. ", i + 1);
            print_string(FOOD_NAME(ELMT(delivery, i)));
            printf(" - ");
            write_fulltime(FOOD_DELIVERY_TIME(ELMT(delivery, i)));
            putchar('\n');
        }
    }
}