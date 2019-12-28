/*
** EPITECH PROJECT, 2019
** MUL_my_runner_2019
** File description:
** init_obj
*/

#include "my_runner.h"
#include "csfml.h"

void init_obj(obj_t *obj)
{
    init_player(&obj->player);
    obj->enemy = NULL;
    obj->xp = NULL;
}