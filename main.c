#include "seabattle.h"

int main () {
    board player_board = {0};
    board enemy_board = {0};
    printf ("\033[0d\033[2J");
    // create_army(game_board);
    read_from_file(&player_board, 0);
    read_from_file(&enemy_board, 1);
    // print_all_boards(player_board, enemy_board, 0);
    // print_board(player_board);
    draw_game_frame(&player_board, &enemy_board);
    return 0;
}

    // for (int i = 0; i < 12; i++) {
    //     for (int j = 0; j < 24; j++) {
    //         printf("%d", game_board.board[i][j]);
    //     }
    //     printf("\n");
    // }

    // 65-74