#include "seabattle.h"

void save_to_file(board game_board, ships player_ships) {
    FILE *fp = NULL;
    char name[30] = "";
    printf("Выберите название для файла: ");
    scanf("%s", name);
    fp = fopen(name, "w");
    for (int i = 0; i < 12; i++) {
        for (int j = 0; j < 12; j++) {
            fprintf(fp, "%d", game_board.info[i][j]);
        }
    }
    fprintf(fp, "\n");
    for (int i = 0; i < 10; i++) {
        for (int k = 0; k < 7; k++) {
            fprintf(fp, "%d", player_ships.info[i][k]);
        }
    }
    fclose(fp);
}