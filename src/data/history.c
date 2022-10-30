#include "history.h"

void initialize_history() {
    create_stack(&history, 20);
    create_stack(&restore, 10);
}