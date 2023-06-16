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
            if (j != 11)
                fprintf(fp, " ");
        }
        fprintf(fp, "\n");
    }
    fprintf(fp, "\n");
    for (int i = 0; i < 10; i++) {
        printf("ID: %d, SIZE: %d, X: %d, Y: %d, ROTATION: %d, STATUS: %d\n", player_ships.info[i][ID], player_ships.info[i][SIZE], player_ships.info[i][X], player_ships.info[i][Y], player_ships.info[i][ROTATION], player_ships.info[i][STATUS]);
    }
    for (int i = 0; i < 10; i++) {
        for (int k = 0; k < 6; k++) {
            fprintf(fp, "%d", player_ships.info[i][k]);
            if (k != 5)
                fprintf(fp, " ");
        }
        if (i != 9)
            fprintf(fp, "\n");
    }
    fclose(fp);
}