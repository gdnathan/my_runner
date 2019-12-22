/*
** EPITECH PROJECT, 2019
** MUL_my_runner_2019
** File description:
** init_enemy
*/

#include "csfml.h"
#include "my_runner.h"
#include "game_parameters.h"

void init_enemy(enemy_t **enemy)
{
    (*enemy) = malloc(sizeof(enemy_t));
    (*enemy)->pos = malloc(sizeof(sfVector2f));
    (*enemy)->rect = malloc(sizeof(sfIntRect));
    (*enemy)->texture = sfTexture_createFromFile("data/enemy.png", NULL);
    (*enemy)->sprite = sfSprite_create();
    (*enemy)->pos->x = 2534;
    (*enemy)->pos->y = rand() % (440 - 40) + 40;
    (*enemy)->rect->height = 100;
    (*enemy)->rect->width = 135;
    (*enemy)->rect->left = 0;
    (*enemy)->rect->top = 0;
    sfSprite_setTexture((*enemy)->sprite, (*enemy)->texture, sfTrue);
}