#include "seabattle.h"

int main () {
    board player_first_board = {0};
    ships player_first_ships = {0};
    player_first_ships.count = 0;
    board player_second_board = {0};
    ships player_second_ships = {0};
    player_second_ships.count = 0;
    printf ("\033[0d\033[2J");
    printf("Создание поля для игрока 1\n");
    create_army(&player_first_board, &player_first_ships);
    printf ("\033[0d\033[2J");
    printf("Создание поля для игрока 2\n");
    create_army(&player_second_board, &player_second_ships);
    printf ("\033[0d\033[2J");
    // read_from_file(&player_board, &player_ships, 0);
    // read_from_file(&enemy_board, 1);
    // print_all_boards(player_board, enemy_board, 0);
    // print_board(player_board);
    // for (int i = 0; i < 10; i++) {
    //     printf("ID: %d, ",  player_ships.info[i][0]);
    //     printf("Size: %d, ",  player_ships.info[i][1]);
    //     printf("X_S: %d, ",  player_ships.info[i][2]);
    //     printf("Y_S: %d, ",  player_ships.info[i][3]);
    //     printf("X_E: %d, ",  player_ships.info[i][4]);
    //     printf("Y_E: %d, ",  player_ships.info[i][5]);
    //     printf("Status: %d", player_ships.info[i][6]);
    //     printf("Ships: %d\n", player_ships.count);
    // }
    draw_game_frame(&player_first_board, &player_second_board, &player_first_ships, &player_second_ships);
    return 0;
}

    // for (int i = 0; i < 12; i++) {
    //     for (int j = 0; j < 24; j++) {
    //         printf("%d", game_board.board[i][j]);
    //     }
    //     printf("\n");
    // }

    // 65-74