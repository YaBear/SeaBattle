#ifndef SEABATTLE_H_
#define SEABATTLE_H_

#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>

// Ship type = 0 - 1block, 1 - 2block, 2 - 3, 3 - 4
typedef struct ships_struct {
    int info[10][6];            // rows 10 - уникальные корабли: 1 - ID, 2 - Размер корабля, 3-4 координаты носа, 5 направление, 6 статус
    int count;
} ships;

typedef struct board_struct {
    int info[12][24];          // 0 - empty, 1 - ship, 2 - damage, 3 - wall;
    int score;
} board;

enum direction {
    LEFT,
    RIGHT,
    UP,
    DOWN
};

enum ship_data {
    ID,
    SIZE,
    X,
    Y,
    ROTATION,
    STATUS
};

void draw_game_frame(board *first_player, board *second_player, ships *f_ships, ships *s_ships);
void print_board(board game_board);
void print_all_boards(board first_player, board second_player, int mode);
void create_army(board *game_board, ships *player_ships, int mode);
void create_four_ship(board *game_board, ships *player_ships, int pos_x, int pos_y);
void create_three_ship(board *game_board, ships *player_ships, int pos_x, int pos_y);
void create_two_ship(board *game_board, ships *player_ships, int pos_x, int pos_y);
void create_one_ship(board *game_board, ships *player_ships, int pos_x, int pos_y);
int check_coord(board game_board, int pos_x, int pos_y);
int check_line(board game_board, int pos_x, int pos_y, int len, int dir);
void build_the_wall(board *game_board);
void save_to_file(board game_board, ships player_ships);
void read_from_file(board *game_board, ships *player_ships, int player);
void save_ship_information(ships *player_ships, int type, int pos_x, int pos_y, int rotation);
void clearBuffer();
int check_damage(board *p_board, ships *p_ships, int pos_x, int pos_y);
int check_end(ships first, ships second);
void full_destroy(board *p_board, ships *p_ships, int id);
void eight_destroy(board *p_board, int x, int y);
int main_menu();
int hotseat_choise();
void planer_start();
#endif  // SEABATTLE_H_