#include "seabattle.h"

void read_from_file(board *game_board, ships *player_ships, int player) {
    FILE *fp = NULL;
    int stage = 1;
    char name[30] = "";
    while (stage == 1) {
        if (player == 0)
            printf("Введите название файла для поля Игрока 1: ");
        else if (player == 1)
            printf("Введите название файла для поля Игрока 2: ");
        else
            printf("Введите название файла: ");
        scanf("%s", name);
        if ((fp = fopen(name, "r")) == NULL) {
            printf("Такого файла не существует.\n");
            fseek(stdin,0,SEEK_END);
        } else {
            stage = 0;
        }
    }
    int line_count = 0;
    char *number = NULL;
    int x = 1;
    char *line = NULL;
    size_t len = 40;
    while(getline(&line, &len, fp) != EOF) {
        if (line_count < 12) {
            number = strtok(line, " ");
            game_board->info[line_count][0] = atoi(number);
        } else if (line_count > 12) {
            number = strtok(line, " ");
            player_ships->info[line_count - 13][0] = atoi(number);
        }
        while (number != NULL) {
            number = strtok(NULL, " ");
            if (line_count < 12 && number != NULL) {
                game_board->info[line_count][x] = atoi(number);
                x++;
            }
            if (line_count > 12 && number != NULL) {
                player_ships->info[line_count - 13][x] = atoi(number);
                x++;
            }
        }
        line_count++;
        x = 1;
    }
    fclose(fp);
    clearBuffer();
}