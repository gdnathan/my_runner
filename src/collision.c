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
    coll_enemy(info, obj);
    coll_xp(info, obj);
}

void coll_enemy(csfml_t *info, obj_t *obj)
{
    enemy_t *tmp = NULL;

    if (obj->enemy == NULL)
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

void coll_xp(csfml_t *info, obj_t *obj)
{
    fireball_t *delFb = NULL;
    xp_t *del = NULL;

    if (obj->xp == NULL || obj->player->fireball == NULL)
        return;
    del = obj->xp;
    delFb = obj->player->fireball;
    if (dist(obj->player->fireball->pos->x + 37.5, obj->player->fireball->pos->y
            + 37.5, obj->xp->pos->x + 35, obj->xp->pos->y + 35) <= 72.5) {
            obj->player->score = infin_add(obj->player->score, 10);
            obj->player->fireball = obj->player->fireball->next;
            free(delFb);
            new_xp(&obj->xp);
            sfClock_restart(info->clock->xp_spawn);
            obj->xp = obj->xp->next;
            free (del);
    } else {
        coll_inlist_xp(info, obj);
    }
}

void coll_inlist_xp(csfml_t *info, obj_t *obj)
{
    fireball_t *tmp = obj->player->fireball;
    fireball_t *delFb = NULL;
    xp_t *delXp = obj->xp;

    while (tmp != NULL && tmp->next != NULL) {
        if (dist(tmp->next->pos->x + 37.5, tmp->next->pos->y + 37.5,
            obj->xp->pos->x + 35, obj->xp->pos->y + 35) <= 72.5) {
                obj->player->score = infin_add(obj->player->score, 10);
                delFb = tmp->next;
                tmp->next = tmp->next->next;
                free (delFb);
                new_xp(&obj->xp);
                sfClock_restart(info->clock->xp_spawn);
                obj->xp = obj->xp->next;
                free (delXp);
        }
    tmp = tmp->next;
    }
}