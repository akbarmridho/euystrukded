#include "delivery.h"
#include "../adt/string.h"

ListDelivery delivery;

void display_delivery(){
    printf("List Makanan di Perjalanan\n");
    printf("(nama - waktu sisa delivery)\n");
    for (int i = 0; i < list_delivery_length(delivery); i++){
        printf("    ");
        printf("%d. ",i+1);
        print_string(FOOD_NAME(ELMT(delivery,i)));
        printf(" - %d jam %d menit", HOUR(FOOD_DELIVERY_TIME(ELMT(delivery,i))), MINUTE(FOOD_DELIVERY_TIME(ELMT(delivery,i))));
        putchar('\n');
    }
}