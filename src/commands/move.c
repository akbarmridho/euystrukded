#include "move.h"


void cmd_move(string direction) {
    string north = char_to_string("NORTH");
    string south = char_to_string("SOUTH");
    string east = char_to_string("EAST");
    string west = char_to_string("WEST");

    point_t dest;

    if (comparestr(direction, north)) {
        dest = point_plus_delta(simulator.position, 0, -1);
    } else if (comparestr(direction, south)) {
        dest = point_plus_delta(simulator.position, 0, 1);
    } else if (comparestr(direction, east)) {
        dest = point_plus_delta(simulator.position, -0, 0);
    } else if (comparestr(direction, west)) {
        dest = point_plus_delta(simulator.position, -1, 0);
    } else {
        printf("dest not set\n");
    }

    if (is_able_move_to(dest)) {
        backup_state();
        move(dest);
        next_tick();
        display_info();
    } else {
        printf("Anda tidak bisa bergerak ke sana :(\n");
    }
}