#ifndef SERVICE_MAP_H
#define SERVICE_MAP_H

#include "../adt/point.h"
#include "../data/simulator.h"
#include "../data/configdata.h"

simulator_t simulator;

// tampilkan juga posisi player saat ini
void display_map();

boolean is_able_move_to(point_t destination);

point_t get_boiler_position();

point_t get_fryer_position();

point_t get_mixer_position();

point_t get_delivery_position();

point_t get_chopper_position();

#endif