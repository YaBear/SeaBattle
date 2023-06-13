#include "seabattle.h"

// old player turn
void draw_game_frame(board *first_player, board *second_player) {
    char player_turn[3] = {0};
    int game_on = 1, result = 0;
    int pos_x = 0, pos_y = 0;
    // for (int i = 0; i < 24; i++) {
    //     first_player->info[0][i] = 3;
    //     first_player->info[i][0] = 3;
    //     first_player->info[11][i] = 3;
    //     first_player->info[i][11] = 3;
    //     first_player->info[i][12] = 3;
    //     first_player->info[i][23] = 3;
    //     second_player->info[0][i] = 3;
    //     second_player->info[i][0] = 3;
    //     second_player->info[11][i] = 3;
    //     second_player->info[i][11] = 3;
    //     second_player->info[i][12] = 3;
    //     second_player->info[i][23] = 3;
    // }
    // print_board(game_board);
    fseek(stdin,0,SEEK_END);
    printf ("\033[0d\033[2J");
    print_all_boards(*first_player, *second_player, 0);
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
            result = 4;
        else {
        // printf("%dx %dy\n", pos_x, pos_y);
        if (second_player->info[pos_x][pos_y] == 1) {
            second_player->info[pos_x][pos_y] = 2;
            first_player->score += 1;
            result = 2;
        } else {
            second_player->info[pos_x][pos_y] = 9;
            result = 1;
        }
        }
        fseek(stdin,0,SEEK_END);
        printf ("\033[0d\033[2J");
        print_all_boards(*first_player, *second_player, 0);
    }
}