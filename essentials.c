#include "seabattle.h"

void print_board(board game_board) {
    printf("         Ваше поле              Поле противника  \n");
    printf("    A B C D E F G H I J       A B C D E F G H I J\n");
    for (int i = 0; i < 12; i++) {
        for (int j = 0; j < 24; j++) {
            if ((i == 0 || i == 11) && (j == 0 || j == 12))
                printf("  ");
            if (i > 0 && i < 10 && (j == 0 || j == 12))
                printf("%d ", i-1);
            if (i == 10 && (j == 0 || j == 12))
                printf("9 ");
            if (game_board.board[i][j] == 3)
                printf("= ");
            else if (game_board.board[i][j] == 1)
                printf("▲ ");
            else if (game_board.board[i][j] == 2)
                printf("# ");
            else if (game_board.board[i][j] == 0)
                printf(". ");
            else if (game_board.board[i][j] == 9)
                printf("o ");
        }
        printf("\n");
    }
}

void build_the_wall(board *game_board) {
    for (int i = 0; i < 24; i++) {
        game_board->board[0][i] = 3;
        game_board->board[i][0] = 3;
        game_board->board[11][i] = 3;
        game_board->board[i][11] = 3;
        game_board->board[i][12] = 3;
        game_board->board[i][23] = 3;
    }
}
