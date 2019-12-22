/*
** EPITECH PROJECT, 2019
** MUL_my_runner_2019
** File description:
** score
*/

#include "csfml.h"
#include "my_runner.h"

void scale_score(csfml_t *info, player_t *player)
{
    sfTime time = sfClock_getElapsedTime(info->clock->compute_score);

    if (time.microseconds > 1000000) {
        player->score = infin_add(player->score, 1);
        sfClock_restart(info->clock->compute_score);
    }
    sfText_setString(info->txt, player->score);
    sfRenderWindow_drawText(info->window, info->txt, NULL);
}

char *infin_add(char *score, int new_value)
{
    int i = 0;

    my_revstr(score);
    score[i] += new_value;
    while (score[i] > '9') {
        score[i + 1] += 1;
        score[i] -= 10;
        i += 1;
    }
    my_revstr(score);
    return (score);
}