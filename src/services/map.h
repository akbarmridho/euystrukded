#ifndef SERVICE_MAP_H
#define SERVICE_MAP_H

#include "../adt/point.h"
#include "../data/simulator.h"
#include "../data/configdata.h"

/*
 * Menampilkan peta dan juga posisi player saat ini
 */
void display_map();

/*
 * Periksa jika pemain bisa bergerak ke suatu titik
 */
boolean is_able_move_to(point_t destination);

point_t get_char_pos(char c);

// mendapatkan posisi boiler
point_t get_boiler_position();

// mendapatkan posisi fryer
point_t get_fryer_position();

// mendapatkan posisi mixer
point_t get_mixer_position();

// mendapatkan posisi telepon
point_t get_delivery_position();

// mendapatkan posisi chopper
point_t get_chopper_position();

// mendapatkan posisi kulkas
point_t get_refrigerator_position();

#endif