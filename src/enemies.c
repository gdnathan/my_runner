/*
** EPITECH PROJECT, 2019
** MUL_my_runner_2019
** File description:
** enemies
*/

#include "my_runner.h"
#include "csfml.h"
#include "game_parameters.h"

void spawn_enemies(csfml_t *info, enemy_t **enemy)
{
    sfTime time = sfClock_getElapsedTime(info->clock->enemies_spawn);

    if (time.microseconds >= (700000 - (100000 * DIFFICULTY))) {
        new_enemy(enemy);
        sfClock_restart(info->clock->enemies_spawn);
    }
    if (*enemy == NULL)
        return;
    anim_enemy(enemy, info);
}

void anim_enemy(enemy_t **enemy,  csfml_t *info)
{
    enemy_t *tmp = *enemy;
    enemy_t *del = *enemy;
    sfTime time = sfClock_getElapsedTime(info->clock->enemy_anim);

    while (tmp != NULL && time.microseconds > 10000) {
        tmp->pos->x -= (10 * (DIFFICULTY + 1));
        tmp->rect->left += 135;
        if (tmp->rect->left >= (135 * 3))
            tmp->rect->left = 0;
        tmp = tmp->next;
    }
    if ((*enemy)->pos->x < -135) {
        *enemy = (*enemy)->next;
        free (del);
    }
    display_enemy(info, *enemy);
    free (tmp);
    if (time.microseconds > 10000)
        sfClock_restart(info->clock->enemy_anim);
}

void display_enemy(csfml_t *info, enemy_t *enemy)
{
    enemy_t *tmp = enemy;

    while (tmp != NULL) {
        sfSprite_setTextureRect(tmp->sprite, *tmp->rect);
        sfSprite_setPosition(tmp->sprite, *tmp->pos);
        sfRenderWindow_drawSprite(info->window, tmp->sprite, NULL);
        tmp = tmp->next;
    }
    free (tmp);
}