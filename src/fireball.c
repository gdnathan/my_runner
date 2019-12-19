/*
** EPITECH PROJECT, 2019
** MUL_my_runner_2019
** File description:
** fireball
*/

#include "game_parameters.h"
#include "my_runner.h"
#include "csfml.h"

void launch_fireball(csfml_t *info, player_t *player)
{
    fireball_t *tmp;
    sfEvent event;
    sfTime time = sfClock_getElapsedTime(info->clock->fireball_as);

    sfRenderWindow_pollEvent(info->window, &event);
    if (sfKeyboard_isKeyPressed(sfKeyE) && time.microseconds >= 100000){
        new_fireball(&player->fireball, player->pos);
        sfClock_restart(info->clock->fireball_as);
    }
    if (player->fireball == NULL)
        return;
    tmp = player->fireball;
}

void anim_fireball(fireball_t *tmp,  csfml_t *info)
{
    while (tmp->next != NULL) {
        tmp->pos->y += 3;
        tmp->rect->left += 75;
        if (tmp->rect->left >= 300)
            tmp->rect->left = 0;
        sfSprite_setTextureRect(tmp->sprite, *tmp->rect);
        sfSprite_setPosition(tmp->sprite, *tmp->pos);
        sfRenderWindow_drawSprite(info->window, tmp->sprite, NULL);
        tmp = tmp->next;
        tmp->next = NULL;
    }
}