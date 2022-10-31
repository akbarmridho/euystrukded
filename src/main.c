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
#include "commands/processor.h"
#include "utils/display.h"

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

    string START = char_to_string("START");
    string EXIT = char_to_string("EXIT");
    string BOIL = char_to_string("BOIL");
    string BUY = char_to_string("BUY");
    string CATALOG = char_to_string("CATALOG");
    string CHOP = char_to_string("CHOP");
    string COOKBOOK = char_to_string("COOKBOOK");
    string DELIVERY = char_to_string("DELIVERY");
    string FRY = char_to_string("FRY");
    string INVENTORY = char_to_string("INVENTORY");
    string MIX = char_to_string("MIX");
    string MOVE = char_to_string("MOVE");
    string REDO = char_to_string("REDO");
    string UNDO = char_to_string("UNDO");
    string WAIT = char_to_string("WAIT");

    string name;

    if (!DEBUG) {
        printf("Ketik START untuk mulai atau EXIT untuk keluar\n");
        start_word();
        if (!comparestr(START, word_to_string(current_word))) {
            return 0;
        }
        printf("Masukkan nama anda: ");
        advance_word();
        name = word_to_string(current_word);
    } else {
        name = char_to_string("DEBUG PROFILE");
    }

    start_program(name);
    clear_display();
    display_info();
    printf("Enter command: ");

    if (DEBUG) {
        start_word();
    } else {
        advance_word();
    }

    boolean exit = false;

    while (!exit) {
        string current_input = word_to_string(current_word);

        if (comparestr(EXIT, current_input)) {
            exit = true;
            continue;
        } else if (comparestr(BOIL, current_input)) {
            process_request(Boil);
        } else if (comparestr(BUY, current_input)) {
            cmd_buy();
        } else if (comparestr(CATALOG, current_input)) {
            display_catalog();
        } else if (comparestr(CHOP, current_input)) {
            process_request(Chop);
        } else if (comparestr(COOKBOOK, current_input)) {
            cookbook();
        } else if (comparestr(DELIVERY, current_input)) {
            display_delivery();
        } else if (comparestr(FRY, current_input)) {
            process_request(Fry);
        } else if (comparestr(INVENTORY, current_input)) {
            cmd_inventory();
        } else if (comparestr(MIX, current_input)) {
            process_request(Mix);
        } else if (startwith(current_input, MOVE)) {
            string direction = cut_str(current_input, 5, current_input.neff - 1);

            cmd_move(direction);
            deallocate_string(&direction);
        } else if (comparestr(REDO, current_input)) {
            redo();
        } else if (comparestr(UNDO, current_input)) {
            undo();
        } else if (startwith(current_input, WAIT)) {
            string time = cut_str(current_input, 5, current_input.neff - 1);

            char time_s[time.neff + 1];

            for (int l = 0; l < time.neff; l++) {
                time_s[l] = letter_at(time, l);
            }

            time_s[time.neff] = '\0';

            int hour;
            int minute;

            int valcount = sscanf(time_s, "%d %d", &hour, &minute); //NOLINT

            if (valcount == 1) {
                // hanya satu angka, anggap menit
                wait(0, hour);
            } else if (valcount == 2) {
                wait(hour, minute);
            } else {
                printf("Format wait salah! Gunakan WAIT JAM MENIT atau WAIT MENIT\n");
                printf("\nEnter command: ");
            }
            
            deallocate_string(&time);
        } else {
            printf("Perintah tidak dikenali.\n");
        }

        deallocate_string(&current_input);
        advance_word();
    }

    return 0;
}