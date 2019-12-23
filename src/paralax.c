/*
** EPITECH PROJECT, 2019
** MUL_my_runner_2019
** File description:
** paralax
*/

#include "my_runner.h"
#include "csfml.h"

void anim_bg(csfml_t *info, background_t *bg)
{
    sfTime time = sfClock_getElapsedTime(info->clock->bg_anim);

    if (time.microseconds < 10000)
        return;
    bg->pos_back->x -= 2;
    bg->next->pos_back->x -= 2;
    if (bg->pos_back->x < -2534)
        bg->pos_back->x = 2534;
    if (bg->next->pos_back->x < -2534)
        bg->next->pos_back->x = 2534;
    bg->pos_fore->x -= 5;
    bg->next->pos_fore->x -= 5;
    if (bg->pos_fore->x < -2534)
        bg->pos_fore->x = bg->next->pos_fore->x + 2534;
    if (bg->next->pos_fore->x < -2534)
        bg->next->pos_fore->x =  bg->pos_fore->x + 2534;
    disp_bg(info, bg);
    sfClock_restart(info->clock->bg_anim);
}

void disp_bg(csfml_t *info, background_t *bg)
{
    sfSprite_setPosition(bg->sprite_back, *bg->pos_back);
    sfSprite_setPosition(bg->next->sprite_back, *bg->next->pos_back);
    sfRenderWindow_drawSprite(info->window, bg->sprite_back, NULL);
    sfRenderWindow_drawSprite(info->window, bg->next->sprite_back, NULL);
    sfSprite_setPosition(bg->sprite_fore, *bg->pos_fore);
    sfSprite_setPosition(bg->next->sprite_fore, *bg->next->pos_fore);
    sfRenderWindow_drawSprite(info->window, bg->sprite_fore, NULL);
    sfRenderWindow_drawSprite(info->window, bg->next->sprite_fore, NULL);
}
