#include "map.h"
#include "simulator.h"
#include "notifier.h"

simulator_t simulator;

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
        string suffixUndo = char_to_string(" telah kembali ke inventori");
        notify(concat(FOOD_NAME(dump), suffix));
        notify_undo(concat(FOOD_NAME(dump), suffixUndo));
        deallocate_string(&suffix);
    }

    pnext_n_minute(&time(simulator), 1);
}

/*
I.S. sembarang
F.S. Info simulator tampil pada layar
*/
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

    display_map();
    printf("\n");
}

/*
    Mengembalikan true jika object disekitar simulator, tepat satu petak secara diagonal atau vertikakl horizontal
    mengembalikan false jika tidak
*/
boolean is_near(point_t object) {
    double del_abs = ABSIS(object) - ABSIS(position(simulator));
    double del_ord = ORDINAT(object) - ORDINAT(position(simulator));
    return (del_abs * del_abs) + (del_ord * del_ord) <= 2;
}

/*
 * Pindahkan posisi player ke destination
 */
void move(point_t destination) {
    position(simulator) = destination;
}

/*
 * Periksa jika berada di sekitar telepon
 */
boolean is_able_to_buy() {
    return is_near(get_delivery_position());
}

/*
 * Periksa jika berada di sekitar chopper
 */
boolean is_able_to_chop() {
    return is_near(get_chopper_position());
}

/*
 * Periksa jika berada di sekitar boiler
 */
boolean is_able_to_boil() {
    return is_near(get_boiler_position());
}

/*
 * Periksa jika berada di sekitar fryer
 */
boolean is_able_to_fry() {
    return is_near(get_fryer_position());
}

/*
 * Periksa jika berada di sekitar mixer
 */
boolean is_able_to_mix() {
    return is_near(get_mixer_position());
}

boolean is_in_inventory(string name){
    boolean found= false;
    int n= 0;
    while (!found && n<NEFF(inventory(simulator))){
        if(compare_str(name, FOOD_NAME(ELMT(inventory(simulator), n)))){
            found= true;
        }else{
            n++;
        }
    }
}