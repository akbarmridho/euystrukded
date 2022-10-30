#include "../adt/simulator.h"
#include "../adt/list_food.h"
#include "../adt/time.h"
#include "../data/simulator.h"
#include "map.h"
#include "simulator.h"
#include "notifier.h"
#include <math.h>

simulator_t simulator;

/*
Kurangi waktu kadaluarsa inventory
bila ada yg kadaluarsa, tambahkan ke notification lalu tambahkan ke food history

tambahkan waktu program juga
*/
void simulator_next_tick(){
    for (int i = 0; i < list_food_length(inventory(simulator)); i++){
        pprev_n_minute(&FOOD_EXPIRE_TIME(ELMT(inventory(simulator),i)),1);
        if (time_to_minute(FOOD_EXPIRE_TIME(ELMT(inventory(simulator),i)))<=0){
            food_t dump;
            list_food_delete(&(inventory(simulator)),i);
            char ntf [] = {' ','k','e','d','a','l','u','a','r','s','a','.','.',' ',':',' ','('};
            string ntf_s = char_to_string(ntf);
            notify(concat(FOOD_NAME(dump),ntf_s));
        } 
        else {
            continue;
        }
    }
    pnext_n_minute(&time(simulator),1);
}

void display_info(simulator_t sim){
    printf("BNMO di posisi: ");
    write_point(position(sim));
    printf("\n");
    
    write_day(time(sim));
    printf(" Time: ");
    write_time(time(simulator));

    display_notification();
    clear_notification();

    display_map();
    printf("\n");
    pritnf("Enter Command: ");
}

boolean is_near(point_t object){
    double del_abs = ABSIS(object)-ABSIS(position(simulator));
    double del_ord = ORDINAT(object)-ORDINAT(position(simulator));
    return (pow(del_abs,2)+pow(del_ord,2))<=2;
}

void move(point_t destination){
    position(simulator) = destination;
}

boolean is_able_to_buy(){
    return is_near(get_delivery_position());
}

boolean is_able_to_chop(){
    return is_near(get_chopper_position());
}

boolean is_able_to_boil(){
    return is_near(get_boiler_position());
}

boolean is_able_to_fry(){
    return is_near(get_fryer_position());
}

boolean is_able_to_mix(){
    return is_near(get_mixer_position());
}