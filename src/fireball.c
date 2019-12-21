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
    sfEvent event;
    sfTime time = sfClock_getElapsedTime(info->clock->fireball_as);

    sfRenderWindow_pollEvent(info->window, &event);
    if (sfKeyboard_isKeyPressed(sfKeyE) && time.microseconds >= 500000){
        new_fireball(&player->fireball, player->pos);
        sfClock_restart(info->clock->fireball_as);
    }
    if (player->fireball == NULL)
        return;
    anim_fireball(&player->fireball, info);
}

void anim_fireball(fireball_t **fireball,  csfml_t *info)
{
    fireball_t *tmp = *fireball;
    fireball_t *del = *fireball;

    while (tmp != NULL) {
        tmp->pos->x += 20;
        tmp->rect->left += 75;
        if (tmp->rect->left >= 300)
            tmp->rect->left = 0;
        sfSprite_setTextureRect(tmp->sprite, *tmp->rect);
        sfSprite_setPosition(tmp->sprite, *tmp->pos);
        sfRenderWindow_drawSprite(info->window, tmp->sprite, NULL);
        tmp = tmp->next;
    }
    if ((*fireball)->pos->x > 1267) {
        *fireball = (*fireball)->next;
        free (del);
    }
    free (tmp);
}