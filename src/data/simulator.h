#ifndef DATA_SIMULATOR_H
#define DATA_SIMULATOR_H

#include "../adt/simulator.h"

extern simulator_t simulator;

// and other param
void initalize_simulator(string name);

#endif
// menyimpan global variable simulator_t
// berisi nama, posisi, waktu, inventori, notifikasi
// gunakan keyword extern