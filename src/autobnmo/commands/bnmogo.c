#include "bnmogo.h"

void bnmogo() {
    int retcode = start_line("autobnmo.txt");
    string AUTOPROCESS = char_to_string("AUTOPROCESS");
    string AUTOMOVE = char_to_string("AUTOMOVE");

    if (retcode == 1) {
        return;
    }

    boolean fail = false;

    while (!end_line && !fail) {
        string cline_str = word_to_string(current_line);

        if (startwith(cline_str, AUTOPROCESS)) {
            char *first_line_str = to_native_str(cline_str);
            char dump[15];
            int food_id;

            int result = sscanf(first_line_str, "%s %d", dump, &food_id);

            if (result != 2) {
                printf("Parse autoprocess failed\n");
            } else {
                int ret = autoprocess(food_id);
                if (ret == 1) {
                    fail = true;
                }
            }
        } else if (startwith(cline_str, AUTOMOVE)) {
            char destination = cline_str.chars[9];
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
            } else {
                printf("Destination invalid!\n");
                valid = false;
            }

            if (valid) {
                move_auto_to(dest_point);
            } else {
                fail = true;
            }
        } else {
            if (cline_str.neff >= 2) {
                printf("Readline fail got string:\n");
                print_string(cline_str);
                putchar('\n');
                fail = true;
            }
        }

        deallocate_string(&cline_str);
        advance_line();
    }

    force_close();
}