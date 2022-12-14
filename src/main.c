#include <stdio.h>
#include "adt/charmachine.h"
#include "adt/wordmachine.h"
#include "commands/buy.h"
#include "commands/catalog.h"
#include "commands/cookbook.h"
#include "commands/delivery.h"
#include "commands/exit.h"
#include "commands/inventory.h"
#include "commands/move.h"
#include "commands/redo.h"
#include "commands/start.h"
#include "commands/undo.h"
#include "commands/wait.h"
#include "commands/processor.h"
#include "commands/clear.h"
#include "commands/help.h"
#include "commands/recommend.h"
#include "utils/display.h"
#include "autobnmo/commands/automove.h"
#include "autobnmo/commands/autoprocess.h"
#include "autobnmo/commands/autobnmo.h"
#include "autobnmo/commands/bnmogo.h"
#include "commands/refrigerator.h"

/*
 * Meminta nama kepada user
 */
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
    setbuf(stdout, 0);
    clear_display();
    print_splash_screen();

    printf("\nSelamat datang di Sumeru! Nikmati berbagai hidangan khas yang ada di Sumeru\n");

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
    string CLEAR = char_to_string("CLEAR");
    string HELP = char_to_string("HELP");
    string AUTOMOVE = char_to_string("AUTOMOVE");
    string AUTOBNMO = char_to_string("AUTOBNMO");
    string AUTOPROCESS = char_to_string("AUTOPROCESS");
    string BNMOGO = char_to_string("BNMOGO");
    string RECOMMEND = char_to_string("RECOMMEND");
    string REFRIGERATOR = char_to_string("REFRIGERATOR");
    string FRIDGE = char_to_string("FRIDGE");
    string FREEZE = char_to_string("FREEZE");
    string DEFROST = char_to_string("DEFROST");


    string name;

    if (!DEBUG) {
        printf("\nKetik START untuk mulai atau EXIT untuk keluar\n");
        start_word();
        while (!comparestr(START, word_to_string(current_word))) {
            if (comparestr(EXIT, word_to_string(current_word))) {
                printf("Bye Bye!~\n");
                return 0;
            } else if (!comparestr(START, word_to_string(current_word))) {
                printf("Perintah tidak dikenali. Ketik START untuk mulai atau EXIT untuk keluar.\n");
                advance_word();
            }
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
        /*
         * Tambahkan semua makanan ke inventory
         */

        for (int i = 0; i < food_recipe.neff; i++) {
            for (int j = 0; j < 3; j++) {
                if (food_recipe.contents[i].food.source == Buy) {
                    add_to_delivery_list(food_recipe.contents[i].food);
                }
            }
        }

        for (int i = 0; i < 35; i++) {
            next_tick();
        }
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
        } else if (comparestr(CLEAR, current_input)) {
            cmd_clear();
        } else if (comparestr(HELP, current_input)) {
            cmd_main_help();
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
                printf("Format WAIT salah! Gunakan \"WAIT [hour] <minute>\"\n");
                printf("\nEnter command: ");
            }

            deallocate_string(&time);
        } else if (startwith(current_input, AUTOMOVE)) {
            if (current_input.neff < 10) {
                printf("Perintah salah!\n");
            } else {
                char destination = current_input.chars[9];
                point_t dest_point;

                boolean valid = true;

                if (destination == 'T') {
                    dest_point = get_delivery_position();
                } else if (destination == 'B') {
                    dest_point = get_boiler_position();
                } else if (destination == 'F') {
                    dest_point = get_fryer_position();
                } else if (destination == 'C') {
                    dest_point = get_chopper_position();
                } else if (destination == 'M') {
                    dest_point = get_mixer_position();
                } else if (destination == 'R') {
                    dest_point = get_refrigerator_position();
                } else {
                    printf("Destination invalid!\n");
                    valid = false;
                }

                if (valid) {
                    move_auto_to(dest_point);
                    printf("\nEnter command: ");
                }
            }
        } else if (startwith(current_input, AUTOBNMO)) {
            int food_id;
            char dump[15];
            int result = sscanf(to_native_str(current_input), "%s %d", dump, &food_id);

            if (result != 2) {
                printf("Invalid command! Cannot parse food id\n");
            } else {
                autobnmo(food_id);
            }

        } else if (startwith(current_input, AUTOPROCESS)) {
            int food_id;
            char dump[15];
            int result = sscanf(to_native_str(current_input), "%s %d", dump, &food_id);

            if (result != 2) {
                printf("Invalid command! Cannot parse food id\n");
            } else {
                autoprocess(food_id);
            }

        } else if (startwith(current_input, BNMOGO)) {
            bnmogo();
        } else if (comparestr(current_input, RECOMMEND)) {
            recommend();

        } else if (comparestr(current_input, REFRIGERATOR) || comparestr(current_input, FRIDGE)) {
            cmd_refrigerator();
        } else if (startwith(current_input, FREEZE)) {
            int food_id;
            char dump[15];
            int result = sscanf(to_native_str(current_input), "%s %d", dump, &food_id);

            if (result != 2) {
                printf("Invalid command!\n");
            } else {
                cmd_freeze(food_id - 1);
            }
        } else if (startwith(current_input, DEFROST)) {
            int food_id;
            char dump[15];
            int result = sscanf(to_native_str(current_input), "%s %d", dump, &food_id);

            if (result != 2) {
                printf("Invalid command!\n");
            } else {
                cmd_defrost(food_id - 1);
            }

        } else {
            printf("Perintah tidak dikenali. Ketik HELP untuk melihat daftar perintah.\n");
            printf("\nEnter command: ");
        }

        deallocate_string(&current_input);
        advance_word();
    }

    printf("Bye Bye, ");
    print_string(name);
    printf("!~ <3");
    putchar('\n');
    return 0;
}