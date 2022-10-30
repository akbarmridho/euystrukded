#include "history.h"

StackState history;
StackState restore;

void initialize_history() {
    create_stack(&history, 20);
    create_stack(&restore, 10);
}