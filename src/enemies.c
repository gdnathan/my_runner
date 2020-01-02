/*
** EPITECH PROJECT, 2019
** MUL_my_runner_2019
** File description:
** enemies
*/

#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include "my_runner.h"
#include "csfml.h"
#include "game_parameters.h"

void spawn_enemies(csfml_t *info, enemy_t **enemy)
{
    sfTime time = sfClock_getElapsedTime(info->clock->enemies_spawn);

    if (time.microseconds >=
    (T_ENEMY_SPAWN - (T_DIFF_SCALE * info->params->difficulty))) {
        new_enemy(enemy);
        sfClock_restart(info->clock->enemies_spawn);
    }
    if (*enemy == NULL)
        return;
    anim_enemy(enemy, info);
}

int spawn_enemies_finite(csfml_t *info, enemy_t **enemy, char *patern)
{
    sfTime time = sfClock_getElapsedTime(info->clock->enemies_spawn);
    static int i = 0;
    static char c = 0;

    if (time.microseconds >= 300000) {
        sfClock_restart(info->clock->enemies_spawn);
        c = open_patern(patern);
        if (c == 'O')
            new_enemy(enemy);
    }
    if (c == 'W')
        return (1);
    if (*enemy == NULL)
        return (0);
    anim_enemy(enemy, info);
}

char open_patern(char *patern)
{
    static int i = 0;
    static int fd = 0;
    char *buffer = malloc(sizeof(char *));
    if (fd == 0)
        fd = open("data/spawn_pattern", O_RDONLY);
    read(fd, buffer, 1);
    i += 1;
    if (i > 565)
        return ('W');
    return (buffer[0]);
}

void anim_enemy(enemy_t **enemy,  csfml_t *info)
{
    enemy_t *tmp = *enemy;
    enemy_t *del = *enemy;
    sfTime time = sfClock_getElapsedTime(info->clock->enemy_anim);

    while (tmp != NULL && time.microseconds > T_ANIMATION) {
        tmp->pos->x -= (10 * (info->params->difficulty + 1));
        tmp->rect->left += ENEMY_WIDTH;
        if (tmp->rect->left >= (ENEMY_SPRITE_LEN))
            tmp->rect->left = 0;
        tmp = tmp->next;
    }
    if ((*enemy) != NULL && (*enemy)->pos->x < -ENEMY_WIDTH) {
        *enemy = (*enemy)->next;
        free (del);
    }
    display_enemy(info, *enemy);
    if (time.microseconds > T_ANIMATION)
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
    if (tmp != NULL)
        free (tmp);
}