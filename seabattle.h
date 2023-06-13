#ifndef SEABATTLE_H_
#define SEABATTLE_H_

#include <stdio.h>
#include <stdlib.h>
#include <math.h>

typedef struct ships_struct {
    int info[10][5];            // rows 10 - уникальные корабли columns: 1 - ID, 2 - Размер корабля, 3&4 - Координаты, 5 - Статус;
} ships;

typedef struct board_struct {
    int info[12][24];          // 0 - empty, 1 - ship, 2 - damage, 3 - wall;
    int score;
} board;

void draw_game_frame(board *first_player, board *second_player);
void print_board(board game_board);
void print_all_boards(board first_player, board second_player, int mode);
void create_army(board game_board);
void create_four_ship(board *game_board, int pos_x, int pos_y);
void create_three_ship(board *game_board, int pos_x, int pos_y);
void create_two_ship(board *game_board, int pos_x, int pos_y);
void create_one_ship(board *game_board, int pos_x, int pos_y);
int check_coord(board game_board, int pos_x, int pos_y);
int check_line(board game_board, int pos_x, int pos_y, int len, int dir);
void build_the_wall(board *game_board);
void save_to_file(board game_board);
void read_from_file(board *game_board, int player);

#endif  // SEABATTLE_H_