/*
** EPITECH PROJECT, 2019
** MUL_my_runner_2019
** File description:
** free
*/

#include "my_runner.h"

void free_all(csfml_t *info, obj_t *obj, background_t *bg)
{
    free_enemy(obj->enemy);
    free_bg(bg);
    free_player(obj->player);
    free_info(info);
    free_xp(obj->xp);
}

void free_info(csfml_t *info)
{
    sfText_destroy(info->txt);
    sfRenderWindow_destroy(info->window);
    sfClock_destroy(info->clock->bg_anim);
    sfClock_destroy(info->clock->compute_score);
    sfClock_destroy(info->clock->enemies_spawn);
    sfClock_destroy(info->clock->enemy_anim);
    sfClock_destroy(info->clock->fireball_anim);
    sfClock_destroy(info->clock->fireball_as);
    sfClock_destroy(info->clock->player_anim);
    sfClock_destroy(info->clock->time_elapsed);
    sfClock_destroy(info->clock->xp_anim);
    sfClock_destroy(info->clock->xp_spawn);
}

void free_bg(background_t *bg)
{
    sfTexture_destroy(bg->texture_back);
    sfTexture_destroy(bg->texture_fore);
    sfTexture_destroy(bg->next->texture_back);
    sfTexture_destroy(bg->next->texture_fore);
    sfSprite_destroy(bg->sprite_back);
    sfSprite_destroy(bg->sprite_fore);
    sfSprite_destroy(bg->next->sprite_back);
    sfSprite_destroy(bg->next->sprite_fore);
    free (bg->next);
}