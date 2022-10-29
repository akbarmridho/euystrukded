#ifndef SERVICE_HISTORY_H
#define SERVICE_HISTORY_H

#include "../data/simulator.h"
#include "../data/delivery.h"
#include "../data/history.h"

/* Lakukan copy semua data penting ke state */
state_t generate_state();

/* set state program sekarang berdasarkan input */
void set_state(state_t state);

/* Copy current state, lalu push ke stack history */
void backup_state();

/* Pop stack history, lalu timpa current state. Untuk perintah UNDO */
void restore_state();

/* Pop stack restore, push current state ke history, timpa hasil restore ke current state. Untuk perintah REDO */
void restore_backup_state();

/* cek jika bisa undo */
boolean is_able_to_restore();

/* cek jika bisa redo */
boolean is_able_to_restore_backup();

#endif