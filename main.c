#include "seabattle.h"

int main () {
    board player_first_board = {0};
    ships player_first_ships = {0};
    player_first_ships.count = 0;
    board player_second_board = {0};
    ships player_second_ships = {0};
    player_second_ships.count = 0;
    printf ("\033[0d\033[2J");
    int choise = main_menu();
    int mode = 0;
    if (choise == 1) {
        printf ("\033[0d\033[2J");
        mode = hotseat_choise();
        if (mode == 1)
            create_army(&player_first_board, &player_first_ships, 0);
        else
            read_from_file(&player_first_board, &player_first_ships, 0);
        printf ("\033[0d\033[2J");
        mode = hotseat_choise();
        if (mode == 1)
            create_army(&player_second_board, &player_second_ships, 0);
        else
            read_from_file(&player_second_board, &player_second_ships, 1);
        printf ("\033[0d\033[2J");
        draw_game_frame(&player_first_board, &player_second_board, &player_first_ships, &player_second_ships);
    } else if (choise == 2) {
        planer_start();
    }
    return 0;
}
