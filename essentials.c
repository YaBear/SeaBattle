#include "seabattle.h"

void clearBuffer() {
    int c;
    while ((c = getchar()) != '\n' && c != EOF) {
        // Consume characters until newline or EOF is encountered
    }
}

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
            if (j < 12) {
                if (game_board.info[i][j] == 3)
                    printf("= ");
                else if (game_board.info[i][j] == 1)
                    printf("▲ ");
                else if (game_board.info[i][j] == 2)
                    printf("# ");
                else if (game_board.info[i][j] == 0)
                    printf(". ");
                else if (game_board.info[i][j] == 9)
                    printf("o ");
            } else {
                if (j == 12 || j == 23)
                    printf("= ");
                else if (j > 12 && j < 23 && (i == 0 || i == 11))
                    printf("= ");
                else if (j > 12 && j < 23 && (i > 0 && i < 11))
                    printf(". ");
            }
        }
        printf("\n");
    }
}

// Debug = 1, normal = 0
void print_all_boards(board first_player, board second_player, int mode) {
    printf("         Ваше поле              Поле противника  \n");
    printf("    A B C D E F G H I J       A B C D E F G H I J\n");
    for (int i = 0; i < 12; i++) {
        for (int j = 0; j < 24; j++) {
            if (j < 12) {
                if ((i == 0 || i == 11) && (j == 0 || j == 12))
                    printf("  ");
                if (i > 0 && i < 10 && (j == 0 || j == 12))
                    printf("%d ", i-1);
                if (i == 10 && (j == 0 || j == 12))
                    printf("9 ");
                if (first_player.info[i][j] == 3)
                    printf("= ");
                else if (first_player.info[i][j] == 1) {
                    if (mode == 0 || mode == 1)
                        printf("▲ ");
                    else
                        printf(". ");
                }
                else if (first_player.info[i][j] == 2)
                    printf("# ");
                else if (first_player.info[i][j] == 0)
                    printf(". ");
                else if (first_player.info[i][j] == 9)
                    printf("o ");
            } else {
                int k = j - 12;
                if ((i == 0 || i == 11) && (k == 0 || k == 12))
                    printf("  ");
                if (i > 0 && i < 10 && (k == 0 || k == 12))
                    printf("%d ", i-1);
                if (i == 10 && (k == 0 || k == 12))
                    printf("9 ");
                if (second_player.info[i][k] == 3)
                    printf("= ");
                else if (second_player.info[i][k] == 1) {
                    if (mode == 1)
                        printf("▲ ");
                    else
                        printf(". ");
                }
                else if (second_player.info[i][k] == 2)
                    printf("# ");
                else if (second_player.info[i][k] == 0)
                    printf(". ");
                else if (second_player.info[i][k] == 9)
                    printf("o ");
            }
        }
        printf("\n");
    }
    // if (turn == 0)
    //     printf("Ход первого игрока\n");
    // else
    //     printf("Ход второго игрока\n");
    printf("\nИгрок 1: %d\nИгрок 2: %d\n", first_player.score, second_player.score);
}

void build_the_wall(board *game_board) {
    for (int i = 0; i < 12; i++) {
        for (int k = 0; k < 24; k++) {
            if (i == 0 || i == 11)
                game_board->info[i][k] = 3;
            if (i > 0 && i < 11 && (k == 0 || k == 11))
                game_board->info[i][k] = 3;
        }
        // game_board->info[0][i] = 3;
        // game_board->info[i][0] = 3;
        // game_board->info[11][i] = 3;
        // game_board->info[i][11] = 3;
        // game_board->info[i][12] = 3;
        // game_board->info[i][23] = 3;
    }
}

int main_menu() {
    int choise = 0;
    int end = 0;
    while (end != 1) {
    printf ("\033[0d\033[2J");
    printf("=== Sea Battle ===\n");
    printf("= 1. Начать HotSeat сессию\n");
    printf("= 2. Планировщик флота\n");
    printf("= 3. Выход\n");
    scanf("%d", &choise);
    if (choise == 1 || choise == 2 || choise == 3)
        end = 1;
    clearBuffer();
    }
    return choise;
}

int hotseat_choise() {
    int status = 0;
    int end = 0;
    while (end != 1) {
        printf ("\033[0d\033[2J");
        printf("=== Выберите режим создания флота ===\n");
        printf("= 1. Вручную\n");
        printf("= 2. Загрузить файл\n");
        scanf("%d", &status);
        if (status == 1 || status == 2)
            end = 1;
    }
    return status;
}

void planer_start() {
    int choise = 0;
    int end = 0;
    board b_temp = {0};
    b_temp.score = 0;
    ships s_temp = {0};
    s_temp.count = 0;
    while (end != 1) {
        printf("=== Планировщик флота ===\n");
        printf("= 1. Создать и сохранить флот в файл\n");
        printf("= 2. Загрузить файл и просмотреть флот\n");
        scanf("%d", &choise);
        if (choise == 1) {
            create_army(&b_temp, &s_temp, 1);
            end = 1;
        }
        else if (choise == 2) {
            read_from_file(&b_temp, &s_temp, 2);
            print_board(b_temp);
            end = 1;
        }
    }
}
