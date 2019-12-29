/*
** EPITECH PROJECT, 2019
** MUL_my_runner_2019
** File description:
** init_background
*/

#include "my_runner.h"
#include "csfml.h"

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
    bg->next->pos_back->x = BACKGROUND_IMG_LEN;
    bg->next->pos_back->y = 0;
    init_foreground(bg);
    sfSprite_setTexture(bg->sprite_back, bg->texture_back, sfTrue);
    sfSprite_setTexture(bg->next->sprite_back, bg->next->texture_back, sfTrue);
}

void init_foreground(background_t *bg)
{
    bg->pos_fore = malloc(sizeof(sfVector2f));
    bg->texture_fore = sfTexture_createFromFile("data/foreground.png", NULL);
    bg->sprite_fore = sfSprite_create();
    bg->pos_fore->x = 0;
    bg->pos_fore->y = 0;
    bg->next->pos_fore = malloc(sizeof(sfVector2f));
    bg->next->texture_fore = sfTexture_createFromFile("data/foreground.png",
                                                        NULL);
    bg->next->sprite_fore = sfSprite_create();
    bg->next->pos_fore->x = BACKGROUND_IMG_LEN;
    bg->next->pos_fore->y = 0;
    sfSprite_setTexture(bg->sprite_fore, bg->texture_fore, sfTrue);
    sfSprite_setTexture(bg->next->sprite_fore, bg->next->texture_fore, sfTrue);
}
