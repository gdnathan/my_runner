/*
** EPITECH PROJECT, 2019
** MUL_my_runner_2019
** File description:
** core
*/

#include "my_runner.h"
#include "csfml.h"

int core(void)
{
    csfml_t info;
    obj_t obj;
    background_t bg;
    int status = 0;

    init_info(&info);
    init_background(&bg);
    init_obj(&obj);
    status = game(&info, &obj, &bg);
    free_all(&info, &obj, &bg);
    return (status);
}

int game(csfml_t *info, obj_t *obj, background_t *bg)
{
    int status = 0;

    while (sfRenderWindow_isOpen(info->window) && status == 0) {
        sfRenderWindow_pollEvent(info->window, &info->my_event);
        status = run_game(info, obj, bg);
        if (info->my_event.type == sfEvtClosed)
            status = -1;
    }
    return (status);
}

int run_game(csfml_t *info, obj_t *obj, background_t *bg)
{
    anim_bg(info, bg);
    gest_player(info, obj->player);
    spawn_enemies(info, &obj->enemy);
    collision(info, obj);
    scale_score(info, obj->player);
    sfRenderWindow_display(info->window);
    if (obj->player->health->hp == 0)
        return (1);
    return (0);
}