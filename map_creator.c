#include "seabattle.h"

void create_army(board game_board) {
    char player_turn[3] = {0};
    int game_on = 1;
    int pos_x = 0, pos_y = 0, stage = 1, error = 0;
    build_the_wall(&game_board);
    print_board(game_board);
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
        if (!check_coord(game_board, pos_x, pos_y)) {
        game_board.info[pos_y][pos_x] = 9;
        printf("%dx %dy\n", pos_x, pos_y);
        if (stage == 1) create_four_ship(&game_board, pos_x, pos_y);
        if (stage == 2 || stage == 3) create_three_ship(&game_board, pos_x, pos_y);
        if (stage > 3 && stage < 7) create_two_ship(&game_board, pos_x, pos_y);
        if (stage > 6 && stage < 11) create_one_ship(&game_board, pos_x, pos_y);
        stage++;
        } else {
            error = 1;
        }
        }
        fseek(stdin,0,SEEK_END);
        printf ("\033[0d\033[2J");
        print_board(game_board);
        if (error)
            printf("Расстояние между кораблями должна быть минимум одна клетка.\n");
        if (stage >= 11)
            game_on = 0;
    }
    save_to_file(game_board);
}

void create_four_ship(board *game_board, int pos_x, int pos_y) {
    int i = 0, left = 0, right = 0, up = 0, down = 0, stage = 1;
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
        } else if (i == 2 && right) {
            for (int i = 0; i < 4; i++)
                game_board->info[pos_y][pos_x+i] = 1;
            stage = 0;
        } else if (i == 3 && up) {
            for (int i = 0; i < 4; i++)
                game_board->info[pos_y-i][pos_x] = 1;
            stage = 0;
        } else if (i == 4 && down) {
            for (int i = 0; i < 4; i++)
                game_board->info[pos_y+i][pos_x] = 1;
            stage = 0;
        } else {
            printf("Корабль нельзя так расположить.\n");
        }
    fseek(stdin,0,SEEK_END);
    }
}

void create_three_ship(board *game_board, int pos_x, int pos_y) {
    int i = 0, left = 0, right = 0, up = 0, down = 0, stage = 1;
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
        } else if (i == 2 && right) {
            for (int i = 0; i < 3; i++)
                game_board->info[pos_y][pos_x+i] = 1;
            stage = 0;
        } else if (i == 3 && up) {
            for (int i = 0; i < 3; i++)
                game_board->info[pos_y-i][pos_x] = 1;
            stage = 0;
        } else if (i == 4 && down) {
            for (int i = 0; i < 3; i++)
                game_board->info[pos_y+i][pos_x] = 1;
            stage = 0;
        } else {
            printf("Корабль нельзя так расположить.\n");
        }
    }
}

void create_two_ship(board *game_board, int pos_x, int pos_y) {
    int i = 0, left = 0, right = 0, up = 0, down = 0, stage = 1;
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
        } else if (i == 2 && right) {
            for (int i = 0; i < 2; i++)
                game_board->info[pos_y][pos_x+i] = 1;
            stage = 0;
        } else if (i == 3 && up) {
            for (int i = 0; i < 2; i++)
                game_board->info[pos_y-i][pos_x] = 1;
            stage = 0;
        } else if (i == 4 && down) {
            for (int i = 0; i < 2; i++)
                game_board->info[pos_y+i][pos_x] = 1;
            stage = 0;
        } else {
            printf("Корабль нельзя так расположить.\n");
        }
    }
}

void create_one_ship(board *game_board, int pos_x, int pos_y) {
    printf ("\033[0d\033[2J");
    print_board(*game_board);
    game_board->info[pos_y][pos_x] = 1;
}
