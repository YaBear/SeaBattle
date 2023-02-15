#include "seabattle.h"

int main () {
    board game_board = {0};
    printf ("\033[0d\033[2J");
    // create_army(game_board);
    read_from_file(&game_board);
    print_board(game_board);
    return 0;
}

    // for (int i = 0; i < 12; i++) {
    //     for (int j = 0; j < 24; j++) {
    //         printf("%d", game_board.board[i][j]);
    //     }
    //     printf("\n");
    // }

    // 65-74