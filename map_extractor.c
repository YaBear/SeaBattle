#include "seabattle.h"

void save_to_file(board game_board) {
    FILE *fp = NULL;
    char name[30] = "";
    printf("Выберите название для файла: ");
    scanf("%s", name);
    fp = fopen(name, "w");
    for (int i = 0; i < 12; i++) {
        for (int j = 0; j < 12; j++) {
            fprintf(fp, "%d", game_board.board[i][j]);
        }
    }
    fclose(fp);
}