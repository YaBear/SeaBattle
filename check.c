#include "seabattle.h"

int check_coord(board game_board, int pos_x, int pos_y) {
    int flag = 0;
    if (game_board.board[pos_y-1][pos_x-1] == 1)
        flag = 1;
    if (game_board.board[pos_y-1][pos_x] == 1)
        flag = 1;
    if (game_board.board[pos_y-1][pos_x+1] == 1)
        flag = 1;
    if (game_board.board[pos_y][pos_x-1] == 1)
        flag = 1;
    if (game_board.board[pos_y][pos_x+1] == 1)
        flag = 1;
    if (game_board.board[pos_y+1][pos_x-1] == 1)
        flag = 1;
    if (game_board.board[pos_y+1][pos_x] == 1)
        flag = 1;
    if (game_board.board[pos_y+1][pos_x+1] == 1)
        flag = 1;
    return flag;
}

int check_line(board game_board, int pos_x, int pos_y, int len, int dir) {
    int flag = 0;
    if (dir == 1) {
        for (int i = 1; i < len+1; i++) {
            if (game_board.board[pos_y][pos_x-i] == 1 || check_coord(game_board, pos_x-i, pos_y))
                flag = 1;
        }
    } else if (dir == 2) {
        for (int i = 1; i < len+1; i++) {
            if (game_board.board[pos_y][pos_x+i] == 1 || check_coord(game_board, pos_x+i, pos_y))
                flag = 1;
        }
    } else if (dir == 3) {
        for (int i = 1; i < len+1; i++) {
            if (game_board.board[pos_y-i][pos_x] == 1 || check_coord(game_board, pos_x, pos_y-i))
                flag = 1;
        }
    } else if (dir == 4) {
        for (int i = 1; i < len+1; i++) {
            if (game_board.board[pos_y+i][pos_x] == 1 || check_coord(game_board, pos_x, pos_y+i))
                flag = 1;
        }
    }
    return flag;
}
