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
    FILE *fd = fopen("data/game_info", "r+");
    char *buffer = NULL;
    size_t nb = 0;
    int i = 0;
    int status = 0;
    info->params = malloc(sizeof(params_t));
    info->params->best_scores = malloc(sizeof(char *) * 6);
    status = getline(&buffer, &nb, fd);
    while (i < 6) {
        info->params->best_scores[i] = my_strdup(buffer, 5);
        status = getline(&buffer, &nb, fd);
        i += 1;
    }

    info->params->difficulty = my_getnbr(buffer);

    fclose(fd);
}