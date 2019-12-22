/*
** EPITECH PROJECT, 2019
** MUL_my_runner_2019
** File description:
** create
*/

#include "my_runner.h"
#include "csfml.h"

void gest_player(csfml_t *info, player_t *player)
{
    move_player(info, player);
    animate_player(info, player);
    //current_life(info, player);
    launch_fireball(info, player);
}

void move_player(csfml_t *info, player_t *player)
{
    if (sfKeyboard_isKeyPressed(sfKeySpace) && player->gravity > -10
    && player->pos->y > 50) {
        player->gravity -= 1.2;
    }
    else if (player->gravity < 8.5 && player->pos->y < 355) {
        player->gravity += 1;
    }
    if (player->pos->y > 356 && !sfKeyboard_isKeyPressed(sfKeySpace))
        player->gravity = 0;
    if (player->pos->y < 49 && sfKeyboard_isKeyPressed(sfKeySpace))
        player->gravity = 0;
    player->pos->y += player->gravity;
}

void animate_player(csfml_t *info, player_t *player)
{
    sfTime time = sfClock_getElapsedTime(info->clock->player_anim);

    if (time.microseconds > 50000 && player->rect->left != 1125) {
        player->rect->left += 75;
        sfClock_restart(info->clock->player_anim);
    } else if (time.microseconds > 50000 && player->rect->left >= 1125) {
        player->rect->left = 0;
        sfClock_restart(info->clock->player_anim);
    }
    sfSprite_setTextureRect(player->sprite, *player->rect);
    sfSprite_setPosition(player->sprite, *player->pos);
    sfRenderWindow_drawSprite(info->window, player->sprite, NULL);
}
