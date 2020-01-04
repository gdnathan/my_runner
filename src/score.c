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

    if (time.microseconds > T_SCORE_SCALE) {
        player->score = infin_add(player->score, 1);
        sfClock_restart(info->clock->compute_score);
    }
    sfText_setString(info->txt, player->score);
    sfRenderWindow_drawText(info->window, info->txt, NULL);
    if (comparator(player->score,
        info->params->best_scores [info->params->difficulty]) == 1) {
            info->params->best_scores[info->params->difficulty] = player->score;
    }
}

void scale_score_toTheInfiniteAndBeyond(csfml_t *info, player_t *player)
{
    sfTime time = sfClock_getElapsedTime(info->clock->compute_score);

    if (time.microseconds > T_SCORE_SCALE) {
        player->score = infin_add(player->score, 1);
        sfClock_restart(info->clock->compute_score);
    }
    sfText_setString(info->txt, player->score);
    sfRenderWindow_drawText(info->window, info->txt, NULL);
    if (comparator(player->score,
        info->params->best_scores [info->params->difficulty + 3]) == 1) {
        info->params->best_scores[info->params->difficulty + 3] = player->score;
    }
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

int comparator(char *nb1, char *nb2)
{
    int i = 0;

    while (nb1[i] == nb2[i] && i < 5)
        i += 1;
    if (nb1[i] > nb2[i])
        return (1);
    return (0);
}
