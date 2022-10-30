#include "map.h"
#include "simulator.h"
#include "notifier.h"

//simulator_t simulator;

/*
Kurangi waktu kadaluarsa inventory
bila ada yg kadaluarsa, tambahkan ke notification lalu tambahkan ke food history

tambahkan waktu program juga
*/
void simulator_next_tick() {
    for (int i = 0; i < list_food_length(inventory(simulator)); i++) {
        pprev_n_minute(&FOOD_EXPIRE_TIME(ELMT(inventory(simulator), i)), 1);
    }

    int j = 0;

    while (j < list_food_length(inventory(simulator)) &&
           time_to_minute(FOOD_EXPIRE_TIME(ELMT(inventory(simulator), 0))) <= 0) {
        food_t dump = ELMT(inventory(simulator), 0);
        list_food_delete(&(inventory(simulator)), 0);
        string suffix = char_to_string(" telah kadaluarsa :(");
        notify(concat(FOOD_NAME(dump), suffix));
        deallocate_string(&suffix);
    }

    pnext_n_minute(&time(simulator), 1);
}

void display_info() {
    printf("BNMO di posisi: ");
    write_point(position(simulator));
    printf("\n");

    write_day(time(simulator));
    printf(" Time: ");
    write_time(time(simulator));
    printf("\n");

    display_notification();
    putchar('\n');
    clear_notification();

    display_map();
    printf("\n");
    printf("Enter Command: ");
}

boolean is_near(point_t object) {
    double del_abs = ABSIS(object) - ABSIS(position(simulator));
    double del_ord = ORDINAT(object) - ORDINAT(position(simulator));
    return (del_abs * del_abs) + (del_ord * del_ord) <= 2;
}

void move(point_t destination) {
    position(simulator) = destination;
}

boolean is_able_to_buy() {
    return is_near(get_delivery_position());
}

boolean is_able_to_chop() {
    return is_near(get_chopper_position());
}

boolean is_able_to_boil() {
    return is_near(get_boiler_position());
}

boolean is_able_to_fry() {
    return is_near(get_fryer_position());
}

boolean is_able_to_mix() {
    return is_near(get_mixer_position());
}