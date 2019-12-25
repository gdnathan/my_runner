/*
** EPITECH PROJECT, 2019
** MUL_my_runner_2019
** File description:
** collision
*/

#include "my_runner.h"
#include "csfml.h"
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void collision(csfml_t *info, obj_t *obj)
{
    enemy_t *tmp = NULL;

    if (obj->enemy == NULL || obj->player == NULL)
        return;
    tmp = obj->enemy;
    while (tmp != NULL){
        if (dist(tmp->pos->x + 50, tmp->pos->y + 50, obj->player->pos->x + 37.5,
        obj->player->pos->y + 37.5) <= 87.5 && tmp->hited_by_player == false) {
            obj->player->health->hp -= 1;
            tmp->hited_by_player = true;
            obj->player->rect->left = 1200;
            sfSprite_setTextureRect(obj->player->sprite, *obj->player->rect);
            sfRenderWindow_drawSprite(info->window, obj->player->sprite, NULL);
        }
        tmp = tmp->next;
    }
}
