#include "seabattle.h"

// old player turn
void draw_game_frame(board game_board) {
    char player_turn[3] = {0};
    int game_on = 1;
    int pos_x = 0, pos_y = 0;
    for (int i = 0; i < 24; i++) {
        game_board.board[0][i] = 3;
        game_board.board[i][0] = 3;
        game_board.board[11][i] = 3;
        game_board.board[i][11] = 3;
        game_board.board[i][12] = 3;
        game_board.board[i][23] = 3;
    }
    print_board(game_board);
    while (game_on == 1) {
        printf("Ваш ход: ");
        for (int i = 0; i < 2; i++) {
            scanf("%c", &player_turn[i]);
        }
        player_turn[2] = '\0';
        if (player_turn[0] > 96 && player_turn[0] < 107)
            player_turn[0] -= 32;
        pos_y = abs(player_turn[0] - 64);
        pos_x = abs(player_turn[1] - 47);
        if (pos_x > 10 || pos_y > 10)
            printf("Wrong coord\n");
        else {
        printf("%dx %dy\n", pos_x, pos_y);
        game_board.board[pos_x][pos_y] = 1;
        }
        fseek(stdin,0,SEEK_END);
        printf ("\033[0d\033[2J");
        print_board(game_board);
    }
}