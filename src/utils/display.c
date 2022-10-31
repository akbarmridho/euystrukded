#include "display.h"

void clear_display() {
    if (DEBUG) {
        return;
    }
#ifdef __WIN32
    system("cls");
#else
    system("clear");
#endif
}

void print_splash_screen() {
    char *nahida = "\n"
                   "@@@@@@@@@@@@@@@@@@@@@@@@@@@@&&#G7?JJ7J#&#PY@@B#@@@@@@@@@@@@@@@@@@@@@@@@@@@@\n"
                   "@@@@@@@@@@@@@@@@@@@@@@@@&P~....     ...:!YJ5G:G@@@@@@@@@@@@@@@@@@@@@@@@@@@@\n"
                   "@@@@@@@@@@@@@@@@@@@@@@Y~.                 .~J:P@@@@@@@@@@@@@@@@@@@@@@@@@@@@\n"
                   "@@@@@@@@@@@@@@@@@@@&J:                     .^JG#@@@@@@@@@@@@@@@@@@@@@@@@@@@\n"
                   "@@@@@@@@@@@@@@@@@@#:. ..     .             ::55PB@@@@@@@@@@@@@@@@@?&&Y&@@@@\n"
                   "@@@@@@@@@@@@@@@@@B7:....     .        . .  .^!?7?G@@@@@@@@@@@@@@@7.!:J7J@@@\n"
                   "@@@@@@@@@@@@@@@@B~:....    . .. .     .. ^.  ..:!JY&@@@@@@@@@@@@@...:..:?@@\n"
                   "@@@@@@@@@@@@@@@@B::....   . .^:. .    .:..^:.. :^BG#@@@@@@@@@@@@@: .   J@@@\n"
                   "@@@@@@@@@@@@@@@&?::.:..  ....  ...:   .. ......^!?5PB@@@@@@@@@@@@G     7@@@\n"
                   "@@@@@@@@@@@@@@@&7?:.. ..::.::~~^..::. ..!PPPY^~: .^7?YP&@@@@@@@@@#    ^@@@@\n"
                   "@@@@@@@@@@@@@@@@B7......^:~G&#?GJ  ....:GJ^P!5?   .^J#&@@@@@@@@@G    :@@@@@\n"
                   "@@@@@@@@@@@@@@@@&~~^:.  ..PJJ?.^7       ...:..:  .^~:J@@@@@@@@&!     &@@@@@\n"
                   "@@@@@@@@@@@@@@@@7:7.::.  ... ..             ...:^.:^:.&@@@@@@5.     J@@@@@@\n"
                   "@@@@@@@@@@@@@@@Y.:~..:::... ...       .     .:~^. .!::55@@@&~      :@@@@@@@\n"
                   "@@@@@@@@@@@@@@&^...^...^!^^~^:.           .^.:.  .P@&&&BP5J.       B@@@@@@@\n"
                   "@@@@@@@@@@@@@J:~:!J~:...^~:777~^::.    .:^~^....:Y##BPJ~..        J@@@@@@@@\n"
                   "@@@@@@@@@@@@@@@@P#@G.:^:::^!7!??77~^~J5YJ7:.::^::?GBYJ^^.        !5&@@@@@@@\n"
                   "@@@@@@@@@@@@@@@@@@@@5..:~~::^~~:.Y!~JBGG?^:..   ?5#B5?:::....:^~?5#@@@@@@@@\n"
                   "@@@@@@@@@@@@@@@@@@@@@&?. :.     !J??PGBB7!      7JPBGPJ!~~!YPPPGB&@@@@@@@@@\n"
                   "@@@@@@@@@@@@@@@@@@@@@@@@J.   .~!?P#&BY~^!^.      .!?Y55Y5PGGB#&&&&&##&@@@@@\n"
                   "@@@@@@@@@@@@@@@@@&@@@@@#?. ^Y?7J#&&&#P^  .^:.   .:P5555555Y5P&&YJ~!BG?5@@@@\n"
                   "@@@@@@@@@@@@@@@&GYG#5!^::^PBY?G###BGJ:     :!!~?. JP5GGP55PPG&@@#G@@@@@@@@@\n"
                   "@@@@@@@@@@@@@@@@@#G?!!!~!B#Y~JYPPY?~:       .:?5^7YY5PGPPPPPP55G&@@@@@@@@@@\n"
                   "@@@@@@@@@@@@@@@@@@@P~!~^?5Y?~G#G?^:~.       ....555&BPPPPP55555YYYY5PBBPG#&\n"
                   "@@@@@@@@@@@@@@@@@@@@@@J~7P&GBG7:.  ^.        .. JGG&@&G55555555YYYYJJJJ????\n"
                   "@@@@@@@@@@@@@@@@@@@@@P7~.!YBJ:.    :.           .?PPG@@&PYYYYYYYYYYYJYJJJJ?\n"
                   "@@@@@@@@@@@@@@@@@@@B7~~: .7!:      .:           ..:?YG@@@&PYJYYYJJJJJJJJJJJ\n"
                   "@@@@@@@@@@@@@@@@@@B7:.~. ^:^.    . .^          ..^..:!Y&@@@&BYJYYJJYYJJJJJJ\n";

    printf("%s", nahida);
}