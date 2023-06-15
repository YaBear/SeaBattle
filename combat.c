#include "seabattle.h"

// old player turn
void draw_game_frame(board *first_player, board *second_player, ships *f_ships, ships *s_ships) {
    char player_turn[3] = {0};
    int game_on = 1, result = 0;
    int pos_x = 0, pos_y = 0;
    int turn = 0;
    printf ("\033[0d\033[2J");
    print_all_boards(*first_player, *second_player, 2);
    while (game_on == 1) {
        if (result == 1)
            printf("Промах...\n");
        else if (result == 2)
            printf("Попадание!\n");
        else if (result == 3)
            printf("Уничтожен!\n");
        else if (result == 4)
            printf("Невозможно выстрелить сюда!\n");
        result = 0;
        printf("Ход игрока: %d\n", turn + 1);
        for (int i = 0; i < 2; i++) {
            scanf("%c", &player_turn[i]);
        }
        player_turn[2] = '\0';
        if (player_turn[0] > 96 && player_turn[0] < 107)
            player_turn[0] -= 32;
        pos_y = abs(player_turn[0] - 64);
        pos_x = abs(player_turn[1] - 47);
        if (pos_x > 10 || pos_y > 10)
            result = 4;
        else {
        if (turn == 0) {
            if (second_player->info[pos_x][pos_y] == 1) {
                second_player->info[pos_x][pos_y] = 2;
                first_player->score += 1;
                if (check_damage(second_player, s_ships, pos_y, pos_x)) {
                    result = 3;
                } else
                    result = 2;
            } else if (second_player->info[pos_x][pos_y] == 2 || second_player->info[pos_x][pos_y] == 3) {
                result = 4;
            } else if (second_player->info[pos_x][pos_y] == 0 || second_player->info[pos_x][pos_y] == 9) {
                second_player->info[pos_x][pos_y] = 9;
                result = 1;
                turn = 1;
            }
        } else {
            if (first_player->info[pos_x][pos_y] == 1) {
                first_player->info[pos_x][pos_y] = 2;
                second_player->score += 1;
                if (check_damage(first_player, f_ships, pos_y, pos_x)) {
                    result = 3;
                } else
                    result = 2;
            } else {
                first_player->info[pos_x][pos_y] = 9;
                result = 1;
                turn = 0;
            }
        }
        }
        clearBuffer();
        fseek(stdin,0,SEEK_END);
        printf ("\033[0d\033[2J");
        print_all_boards(*first_player, *second_player, 2);
        game_on = check_end(*f_ships, *s_ships);
    }
    if (game_on == 0)
        printf("Победил Игрок 2!!!\n");
    else
        printf("Победил Игрок 1!!!\n");
}

int check_damage(board *p_board, ships *p_ships, int pos_x, int pos_y) {
    int status = 0; // 0 damaged, 1 destroyed
    // find ship id
    int id = -1;
    int check = 0;
    for (int i = 0; i < 10 && check == 0; i++) {
        for (int k = 0; k < p_ships->info[i][SIZE]; k++) {
            if (p_ships->info[i][ROTATION] == LEFT) {
                if (p_ships->info[i][X] - k == pos_x) {
                    if (p_ships->info[i][Y] == pos_y)
                        check = 1;
                }
            } else if (p_ships->info[i][ROTATION] == RIGHT) {
                if (p_ships->info[i][X] + k == pos_x) {
                    if (p_ships->info[i][Y] == pos_y)
                        check = 1;
                }
            } else if (p_ships->info[i][ROTATION] == UP) {
                if (p_ships->info[i][X] == pos_x) {
                    if (p_ships->info[i][Y] - k == pos_y)
                        check = 1;
                }
            } else if (p_ships->info[i][ROTATION] == DOWN) {
                if (p_ships->info[i][X] == pos_x) {
                    if (p_ships->info[i][Y] + k == pos_y)
                        check = 1;
                }
            }
        }
        if (check)
            id = i;
    }
    // count damage
    p_ships->info[id][STATUS] += 1;
    if (p_ships->info[id][STATUS] == p_ships->info[id][SIZE] + 1) {
        status = 1;
        full_destroy(p_board, p_ships, id);
    }
    return status;
}

void full_destroy(board *p_board, ships *p_ships, int id) {
    int x = p_ships->info[id][X];
    int y = p_ships->info[id][Y];
    for (int i = 0; i < p_ships->info[id][SIZE]; i++) {
        eight_destroy(p_board, x, y);
        if (p_ships->info[id][ROTATION] == LEFT)
            x -= 1;
        else if (p_ships->info[id][ROTATION] == RIGHT)
            x += 1;
        else if (p_ships->info[id][ROTATION] == UP)
            y -= 1;
        else if (p_ships->info[id][ROTATION] == DOWN)
            y += 1;
    }
    // p_board->score = p_board->score + 100;
}

int check_end(ships first, ships second) {
    int counter = 0;
    for (int i = 0; i < 10; i++) {
        if (first.info[i][STATUS] == first.info[i][SIZE] + 1)
            counter++;
    }
    if (counter == 10)
        return 0;
    else {
        counter = 0;
        for (int i = 0; i < 10; i++) {
            if (second.info[i][STATUS] == second.info[i][SIZE] + 1)
                counter++;
        }
        if (counter == 10)
            return 2;
    }
    return 1;
}

void eight_destroy(board *p_board, int x, int y) {
    if (p_board->info[y - 1][x] == 0)
        p_board->info[y - 1][x] = 9;
    if (p_board->info[y - 1][x + 1] == 0)
        p_board->info[y - 1][x + 1] = 9;
    if (p_board->info[y][x + 1] == 0)
        p_board->info[y][x + 1] = 9;
    if (p_board->info[y + 1][x + 1] == 0)
        p_board->info[y + 1][x + 1] = 9;
    if (p_board->info[y + 1][x] == 0)
        p_board->info[y + 1][x] = 9;
    if (p_board->info[y + 1][x - 1] == 0)
        p_board->info[y + 1][x - 1] = 9;
    if (p_board->info[y][x - 1] == 0)
        p_board->info[y][x - 1] = 9;
    if (p_board->info[y - 1][x - 1] == 0)
        p_board->info[y - 1][x - 1] = 9;
}