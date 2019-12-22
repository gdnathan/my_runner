/*
** EPITECH PROJECT, 2019
** MUL_my_runner_2019
** File description:
** init_player
*/

#include "csfml.h"
#include "my_runner.h"

void init_player(player_t *player)
{
    int i = 0;

    player->pos = malloc(sizeof(sfVector2f));
    player->rect = malloc(sizeof(sfIntRect));
    player->texture = sfTexture_createFromFile("data/fire_mage_move.png", NULL);
    player->sprite = sfSprite_create();
    player->pos->x = 200;
    player->pos->y = 350;
    player->rect->height = 75;
    player->rect->width = 75;
    player->rect->left = 0;
    player->rect->top = 0;
    player->gravity = 0;
    player->fireball = NULL;
    player->score = my_strdup("00000", 5);
    sfSprite_setTexture(player->sprite, player->texture, sfTrue);
    //init_health(player);
}

void init_health(player_t *player)
{
    player->health->hp = 3;
}