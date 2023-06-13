#include "seabattle.h"

void read_from_file(board *game_board, int player) {
    FILE *fp = NULL;
    int stage = 1;
    char name[30] = "";
    while (stage == 1) {
        if (player == 0)
            printf("Введите название файла для вашего поля: ");
        else
            printf("Введите название файла для поля противника: ");
        scanf("%s", name);
        if ((fp = fopen(name, "r")) == NULL) {
            printf("Такого файла не существует.\n");
            fseek(stdin,0,SEEK_END);
        } else {
            for (int i = 0; i < 12; i++) {
                for (int j = 0; j < 12; j++) {
                    game_board->info[i][j] = fgetc(fp) - 48;
                }
            }
            fclose(fp);
            stage = 0;
        }
    }
}