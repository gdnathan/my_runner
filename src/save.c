/*
** EPITECH PROJECT, 2020
** MUL_my_runner_2019
** File description:
** save
*/

#include "csfml.h"
#include "my_runner.h"

void save_game(params_t *params)
{
    if (MAX_HP > 3)
        return;
    FILE *fd = fopen("data/game_info", "w");
    int i = 0;
    char *diff = NULL;

    while (i < 6) {
        fwrite(params->best_scores[i], sizeof(char) * 5, 1, fd);
        fwrite("\n", sizeof(char), 1, fd);
        i += 1;
    }
    diff = my_nbr_to_str(params->difficulty);
    diff += 2;
    fwrite(diff, sizeof(char), 1, fd);
    fclose(fd);
}