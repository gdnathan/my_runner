/*
** EPITECH PROJECT, 2019
** MUL_my_runner_2019
** File description:
** init_enemy
*/

#include "csfml.h"
#include "my_runner.h"
#include "game_parameters.h"

void new_enemy(enemy_t **enemy)
{
    enemy_t *new = NULL;

    if (*enemy == NULL || enemy == NULL) {
        *enemy = init_enemy();
    } else if (*enemy != NULL){
        new = *enemy;
        while (new->next != NULL){
            new = new->next;
        }
        new->next = init_enemy();
    }
}

enemy_t *init_enemy(void)
{
    enemy_t *new = malloc(sizeof(enemy_t));

    new->pos = malloc(sizeof(sfVector2f));
    new->rect = malloc(sizeof(sfIntRect));
    new->texture = sfTexture_createFromFile("data/enemy.png", NULL);
    new->sprite = sfSprite_create();
    new->pos->x = WINDOW_LEN;
    new->pos->y = rand() % (355 - 50) + 50;
    new->rect->height = ENEMY_HEIGHT;
    new->rect->width = ENEMY_WIDTH;
    new->rect->left = 0;
    new->rect->top = 0;
    new->next = NULL;
    new->hited_by_player = false;
    sfSprite_setTexture(new->sprite, new->texture, sfTrue);
    return (new);
}