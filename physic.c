/*
** EPITECH PROJECT, 2019
** MUL_my_runner_2019
** File description:
** create
*/

#include "my_runner.h"
#include "csfml.h"

void disp_bg(csfml_t *info, background_t *bg)
{
    bg->pos_back->x -= 2;
    bg->next->pos_back->x -= 2;
    if (bg->pos_back->x < -1920)
        bg->pos_back->x = 1920;
    if (bg->next->pos_back->x < -1980)
        bg->next->pos_back->x = 1920;
    bg->pos_fore->x -= 5;
    bg->next->pos_fore->x -= 5;
    if (bg->pos_fore->x < -1920)
        bg->pos_fore->x = 1920;
    if (bg->next->pos_fore->x < -1980)
        bg->next->pos_fore->x = 1920;
    sfSprite_setPosition(bg->sprite_back, *bg->pos_back);
    sfSprite_setPosition(bg->sprite_fore, *bg->pos_fore);
    sfRenderWindow_drawSprite(info->window, bg->sprite_back, NULL);
    sfRenderWindow_drawSprite(info->window, bg->sprite_fore, NULL);
}

void move_player(csfml_t *info, player_t *player)
{
    sfRenderWindow_pollEvent(info->window, &info->my_event);
    if (info->my_event.type == sfEvtKeyPressed && info->my_event.key.code
    == sfKeySpace && player->gravity < 10)
        player->gravity += 1;
    else if (player->gravity > -10) {
        player->gravity -= 1;
    }
    if (player->pos->y > 880 || player->pos->y < 200)
        player->gravity = 0;
    player->pos->y += player->gravity;
    animate_player(info, player);
    display_player(info, player);
}

void display_player(csfml_t *info, player_t *player)
{
    sfSprite_setTextureRect(player->sprite, *player->rect);
    sfSprite_setPosition(player->sprite, *player->pos);
    sfRenderWindow_drawSprite(info->window, player->sprite, NULL);
}

void animate_player(csfml_t *info, player_t *player)
{
    sfTime time = sfClock_getElapsedTime(info->clock->player_anim);

    if (time.microseconds > 50000 && player->rect->left != 5600) {
        player->rect->left += 350;
        sfClock_restart(info->clock->player_anim);
    } else if (time.microseconds > 50000 && player->rect->left >= 5600) {
        player->rect->left = 0;
        sfClock_restart(info->clock->player_anim);
    }
}