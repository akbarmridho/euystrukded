#ifndef COMMAND_REFRIGERATOR_H
#define COMMAND_REFRIGERATOR_H

#include "../services/refrigerator.h"
#include "../services/history.h"
#include "../services/simulator.h"
#include "../services/delivery.h"
#include "../utils/display.h"


/* display refrigerator */
void cmd_refrigerator();

/* memasukkan makanan ke kulkas */
void cmd_freeze(int food_idx);

/* mengeluarkan makanan dari kulkas */
void cmd_defrost(int food_idx);

#endif