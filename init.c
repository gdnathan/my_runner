/*
** EPITECH PROJECT, 2019
** MUL_my_runner_2019
** File description:
** init
*/

#include "my_runner.h"
#include "csfml.h"

void init_info(csfml_t *info)
{
    info->clock = malloc(sizeof(my_clock_t));
    info->window = create_window(1920, 1080);
    sfRenderWindow_setFramerateLimit(info->window, 30);
    info->clock->time_elapsed = sfClock_create();
    info->clock->bg_anim = sfClock_create();
    info->clock->player_anim = sfClock_create();

}

sfRenderWindow *create_window(int width, int height)
{
    sfVideoMode video_mode;
    video_mode.width = width;
    video_mode.height = height;
    video_mode.bitsPerPixel = 32;

    return (sfRenderWindow_create(video_mode, "my_runner",
                                    sfDefaultStyle, NULL));
}

void init_player(player_t *player)
{
    player->pos = malloc(sizeof(sfVector2f));
    player->rect = malloc(sizeof(sfIntRect));
    player->texture = sfTexture_createFromFile("data/fire_mage_move.png", NULL);
    player->sprite = sfSprite_create();
    player->hp = 3;
    player->pos->x = 200;
    player->pos->y = 880;
    player->gravity = 0;
    sfSprite_setTexture(player->sprite, player->texture, sfTrue);

}

void init_background(background_t *bg)
{
    bg->next = malloc(sizeof(background_t));
    bg->next->prev = bg;
    bg->pos_back = malloc(sizeof(sfVector2f));
    bg->texture_back = sfTexture_createFromFile("data/background.png", NULL);
    bg->sprite_back = sfSprite_create();
    bg->pos_back->x = 0;
    bg->pos_back->y = 0;
    bg->next->pos_back = malloc(sizeof(sfVector2f));
    bg->next->texture_back = sfTexture_createFromFile("data/background.png",
                                                        NULL);
    bg->next->sprite_back = sfSprite_create();
    sfSprite_setTexture(bg->sprite_back, bg->texture_back, sfTrue);
    init_foreground(bg);
}

void init_foreground(background_t *bg)
{
    bg->pos_fore = malloc(sizeof(sfVector2f));
    bg->texture_fore = sfTexture_createFromFile("data/foreground.png", NULL);
    bg->sprite_fore = sfSprite_create();
    bg->pos_fore->x = 1920;
    bg->pos_fore->y = 0;
    bg->next->pos_fore = malloc(sizeof(sfVector2f));
    bg->next->texture_fore = sfTexture_createFromFile("data/foreground.png",
                                                        NULL);
    bg->next->sprite_fore = sfSprite_create();
    sfSprite_setTexture(bg->sprite_fore, bg->texture_fore, sfTrue);
}