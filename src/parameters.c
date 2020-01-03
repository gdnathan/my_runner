/*
** EPITECH PROJECT, 2019
** MUL_my_runner_2019
** File description:
** parameters
*/

#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <stdio.h>
#include <unistd.h>
#include "my_runner.h"

void load_parameters(csfml_t *info)
{
    FILE *fd = fopen("data/game_info.txt", "r+");
    char *buffer = NULL;
    size_t nb = 0;
    int status = 0;
    status = getline(&buffer, &nb, fd);
    info->params = malloc(sizeof(params_t));

    while (status != -1) {
        if (my_strcmp(buffer, "BEST_SCORE_INF\n") == 1) {
            status = getline(&buffer, &nb, fd);
            info->params->best_score = my_strdup(buffer, 6);
        }
        if (my_strcmp(buffer, "DIFFICULTY\n") == 1) {
            status = getline(&buffer, &nb, fd);
            info->params->difficulty = my_getnbr(buffer);
        }
        status = getline(&buffer, &nb, fd);
    }
    fclose(fd);
}