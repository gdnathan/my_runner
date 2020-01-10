/*
** EPITECH PROJECT, 2019
** MUL_my_runner_2019
** File description:
** init_player
*/

#include "csfml.h"
#include "my_runner.h"

void init_player(player_t **player)
{
    (*player) = malloc(sizeof(player_t));
    (*player)->pos = malloc(sizeof(sfVector2f));
    (*player)->rect = malloc(sizeof(sfIntRect));
    (*player)->health = malloc(sizeof(health_t));
    (*player)->texture = sfTexture_createFromFile("data/fire_mage_move.png",
                                                    NULL);
    (*player)->sprite = sfSprite_create();
    (*player)->pos->x = PLAYER_SPAWN_X;
    (*player)->pos->y = PLAYER_SPAWN_Y;
    (*player)->rect->height = PLAYER_HEIGHT;
    (*player)->rect->width = PLAYER_WIDTH;
    (*player)->rect->left = 0;
    (*player)->rect->top = 0;
    (*player)->gravity = 0;
    (*player)->fireball = NULL;
    (*player)->score = my_strdup("00000", 5);
    init_hp((*player)->health);
    sfSprite_setTexture((*player)->sprite, (*player)->texture, sfTrue);
    (*player)->hited = NULL;
}

void init_hp(health_t *health)
{
    health->hp = MAX_HP;
    health->texture = sfTexture_createFromFile("data/hp.png", NULL);
    health->sprite = sfSprite_create();
    sfSprite_setTexture(health->sprite, health->texture, sfTrue);
}