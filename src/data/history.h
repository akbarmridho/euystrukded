#ifndef DATA_HISTORY_H
#define DATA_HISTORY_H

#include "../adt/stack_command.h"

extern StackState history;
extern StackState restore;

void initialize_history();

#endif

// buat action stack sebagai sumber backup state
// buat restore stack untuk action redo
// restore stack akan direset ketika user melakukan undo, lalu melakukan aksi yang memiliki side effect