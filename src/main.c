#include <stdio.h>
#include "adt/charmachine.h"
#include "adt/wordmachine.h"
#include "commands/boil.h"
#include "commands/buy.h"
#include "commands/catalog.h"
#include "commands/chop.h"
#include "commands/cookbook.h"
#include "commands/delivery.h"
#include "commands/exit.h"
#include "commands/fry.h"
#include "commands/inventory.h"
#include "commands/mix.h"
#include "commands/move.h"
#include "commands/redo.h"
#include "commands/start.h"
#include "commands/undo.h"
#include "commands/wait.h"

word_t current_word;
boolean end_word;
simulator_t simulator;
ListDelivery delivery;
StackState history;
StackState restore;
ListFoodRecipe food_recipe;
Matrix map;
ListTree list_tree_recipe;

string get_name() {
    start_word();
    string result;
    boolean defined = false;

    while (!end_word) {
        if (defined) {
            result = concat(result, concat(char_to_string(" "), word_to_string(current_word)));
        } else {
            result = word_to_string(current_word);
            defined = true;
        }

        advance_word();
    }

    return result;
}

int main() {
    printf("Selamat datang di dinner dash!\n");
    printf("Ketik START untuk mulai atau EXIT untuk keluar\n");

    string START = char_to_string("START");
    string EXIT = char_to_string("EXIT");

    start_word();

    if (!comparestr(START, word_to_string(current_word))) {
        return 0;
    }

    printf("Masukkan nama anda: ");
    string name = get_name();

    start_program(name);
    display_info();
}