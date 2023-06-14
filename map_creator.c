#include "seabattle.h"

void create_army(board *game_board, ships *player_ships) {
    char player_turn[3] = {0};
    int game_on = 1;
    int pos_x = 0, pos_y = 0, stage = 1, error = 0;
    build_the_wall(game_board);
    print_board(*game_board);
    while (game_on == 1) {
        if (stage == 1) printf("Для начала выберите положение для корабля из 4ех клеток: ");
        if (stage == 2 || stage == 3) printf("Выберите положение для кораблей из 3ех клеток: ");
        if (stage > 3 && stage < 7) printf("Выберите положение для кораблей из 2ух клеток: ");
        if (stage > 6 && stage < 11) printf("Выберите положение для кораблей из одной клетки: ");
        for (int i = 0; i < 2; i++) {
            scanf("%c", &player_turn[i]);
        }
        player_turn[2] = '\0';
        if (player_turn[0] > 96 && player_turn[0] < 107)
            player_turn[0] -= 32;
        pos_x = abs(player_turn[0] - 64);
        pos_y = abs(player_turn[1] - 47);
        if (pos_x > 10 || pos_y > 10)
            printf("Wrong coord\n");
        else {
            error = 0;
        if (!check_coord(*game_board, pos_x, pos_y)) {
        game_board->info[pos_y][pos_x] = 9;
        printf("%dx %dy\n", pos_x, pos_y);
        if (stage == 1) create_four_ship(game_board, player_ships, pos_x, pos_y);
        if (stage == 2 || stage == 3) create_three_ship(game_board, player_ships, pos_x, pos_y);
        if (stage > 3 && stage < 7) create_two_ship(game_board, player_ships, pos_x, pos_y);
        if (stage > 6 && stage < 11) create_one_ship(game_board, player_ships, pos_x, pos_y);
        stage++;
        } else {
            error = 1;
        }
        }
        clearBuffer();
        player_turn[0] = '\0';
        player_turn[1] = '\0';
        fseek(stdin,0,SEEK_END);
        printf ("\033[0d\033[2J");
        print_board(*game_board);
        if (error)
            printf("Расстояние между кораблями должна быть минимум одна клетка.\n");
        if (stage >= 11)
            game_on = 0;
    }
    for (int i = 0; i < 10; i++) {
        printf("ID: %d, ",  player_ships->info[i][0]);
        printf("Size: %d, ",  player_ships->info[i][1]);
        printf("X_S: %d, ",  player_ships->info[i][2]);
        printf("Y_S: %d, ",  player_ships->info[i][3]);
        printf("ROTATION: %d, ",  player_ships->info[i][4]);
        printf("STATUS: %d, ",  player_ships->info[i][5]);
        printf("Ships: %d\n", player_ships->count);
    }
    // save_to_file(*game_board, *player_ships);
}

void create_four_ship(board *game_board, ships *player_ships, int pos_x, int pos_y) {
    int i = 0, stage = 1, left = 0, right = 0, up = 0, down = 0;
    int rotation = 0; // 0 left 1 right 2 up 3 down
    printf ("\033[0d\033[2J");
    print_board(*game_board);
    while (stage == 1) {
    printf("Выберите, куда будет направлен корабль:\n");
        if (pos_x - 4 >= 0) {
            printf("1) Влево\n");
            left = 1;
        }
        if (pos_x + 4 < 12) {
            printf("2) Вправо\n");
            right = 1;
        }
        if (pos_y - 4 > 0) {
            printf("3) Вверх\n");
            up = 1;
        }
        if (pos_y + 4 < 12) {
            printf("4) Вниз\n");
            down = 1;
        }
    scanf("%d", &i);
        if (i == 1 && left) {
            for (int i = 0; i < 4; i++)
                game_board->info[pos_y][pos_x-i] = 1;
            stage = 0;
            rotation = 0;
        } else if (i == 2 && right) {
            for (int i = 0; i < 4; i++)
                game_board->info[pos_y][pos_x+i] = 1;
            stage = 0;
            rotation = 1;
        } else if (i == 3 && up) {
            for (int i = 0; i < 4; i++)
                game_board->info[pos_y-i][pos_x] = 1;
            stage = 0;
            rotation = 2;
        } else if (i == 4 && down) {
            for (int i = 0; i < 4; i++)
                game_board->info[pos_y+i][pos_x] = 1;
            stage = 0;
            rotation = 3;
        } else {
            printf("Корабль нельзя так расположить.\n");
        }
    // clearBuffer();
    fseek(stdin,0,SEEK_END);
    }
    save_ship_information(player_ships, 3, pos_x, pos_y, rotation);
}

void create_three_ship(board *game_board, ships *player_ships, int pos_x, int pos_y) {
    int i = 0, stage = 1, left = 0, right = 0, up = 0, down = 0;
    int rotation = 0; // 0 left 1 right 2 up 3 down
    printf ("\033[0d\033[2J");
    print_board(*game_board);
    while (stage == 1) {
        printf("Выберите, куда будет направлен корабль:\n");
        if (pos_x - 3 >= 0 && !check_line(*game_board, pos_x, pos_y, 2, 1)) {
            printf("1) Влево\n");
            left = 1;
        }
        if (pos_x + 3 < 12 && !check_line(*game_board, pos_x, pos_y, 2, 2)) {
            printf("2) Вправо\n");
            right = 1;
        }
        if (pos_y - 3 > 0 && !check_line(*game_board, pos_x, pos_y, 2, 3)) {
            printf("3) Вверх\n");
            up = 1;
        }
        if (pos_y + 3 < 12 && !check_line(*game_board, pos_x, pos_y, 2, 4)) {
            printf("4) Вниз\n");
            down = 1;
        }
    scanf("%d", &i);
        if (i == 1 && left) {
            for (int i = 0; i < 3; i++)
                game_board->info[pos_y][pos_x-i] = 1;
            stage = 0;
            rotation = 0;
        } else if (i == 2 && right) {
            for (int i = 0; i < 3; i++)
                game_board->info[pos_y][pos_x+i] = 1;
            stage = 0;
            rotation = 1;
        } else if (i == 3 && up) {
            for (int i = 0; i < 3; i++)
                game_board->info[pos_y-i][pos_x] = 1;
            stage = 0;
            rotation = 2;
        } else if (i == 4 && down) {
            for (int i = 0; i < 3; i++)
                game_board->info[pos_y+i][pos_x] = 1;
            stage = 0;
            rotation = 3;
        } else {
            printf("Корабль нельзя так расположить.\n");
        }
    // clearBuffer();
    fseek(stdin,0,SEEK_END);
    }
    save_ship_information(player_ships, 2, pos_x, pos_y, rotation);
}

void create_two_ship(board *game_board, ships *player_ships, int pos_x, int pos_y) {
    int i = 0, stage = 1, left = 0, right = 0, up = 0, down = 0;
    int rotation = 0; // 0 left 1 right 2 up 3 down
    printf ("\033[0d\033[2J");
    print_board(*game_board);
    while (stage == 1) {
        printf("Выберите, куда будет направлен корабль:\n");
        if (pos_x - 2 >= 0 && !check_line(*game_board, pos_x, pos_y, 1, 1)) {
            printf("1) Влево\n");
            left = 1;
        }
        if (pos_x + 2 < 12 && !check_line(*game_board, pos_x, pos_y, 1, 2)) {
            printf("2) Вправо\n");
            right = 1;
        }
        if (pos_y - 2 > 0 && !check_line(*game_board, pos_x, pos_y, 1, 3)) {
            printf("3) Вверх\n");
            up = 1;
        }
        if (pos_y + 2 < 12 && !check_line(*game_board, pos_x, pos_y, 1, 4)) {
            printf("4) Вниз\n");
            down = 1;
        }
    scanf("%d", &i);
        if (i == 1 && left) {
            for (int i = 0; i < 2; i++)
                game_board->info[pos_y][pos_x-i] = 1;
            stage = 0;
            rotation = 0;
        } else if (i == 2 && right) {
            for (int i = 0; i < 2; i++)
                game_board->info[pos_y][pos_x+i] = 1;
            stage = 0;
            rotation = 1;
        } else if (i == 3 && up) {
            for (int i = 0; i < 2; i++)
                game_board->info[pos_y-i][pos_x] = 1;
            stage = 0;
            rotation = 2;
        } else if (i == 4 && down) {
            for (int i = 0; i < 2; i++)
                game_board->info[pos_y+i][pos_x] = 1;
            stage = 0;
            rotation = 3;
        } else {
            printf("Корабль нельзя так расположить.\n");
        }
    // clearBuffer();
    fseek(stdin,0,SEEK_END);
    }
    save_ship_information(player_ships, 1, pos_x, pos_y, rotation);
}

void create_one_ship(board *game_board, ships *player_ships, int pos_x, int pos_y) {
    printf ("\033[0d\033[2J");
    print_board(*game_board);
    game_board->info[pos_y][pos_x] = 1;
    save_ship_information(player_ships, 0, pos_x, pos_y, 0);
}

void save_ship_information(ships *player_ships, int type, int pos_x, int pos_y, int rotation) {
    player_ships->info[player_ships->count][ID] = player_ships->count;
    player_ships->info[player_ships->count][SIZE] = type + 1;
    player_ships->info[player_ships->count][X] = pos_x;
    player_ships->info[player_ships->count][Y] = pos_y;
    player_ships->info[player_ships->count][ROTATION] = rotation;
    player_ships->info[player_ships->count][STATUS] = 1;
    player_ships->count += 1;
}
