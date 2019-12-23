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
    player_t player;
    background_t bg;
    int status = 0;

    init_info(&info);
    init_background(&bg);
    init_obj(&obj);
    status = game(&info, &obj, &bg);
    free_all(&info);
    return (status);
}

int game(csfml_t *info, obj_t *obj, background_t *bg)
{
    int status = 0;

    while (sfRenderWindow_isOpen(info->window) && status == 0) {
        sfRenderWindow_pollEvent(info->window, &info->my_event);
        if (info->my_event.type == sfEvtClosed)
            sfRenderWindow_destroy(info->window);
        status = run_game(info, obj, bg);
    }
    return (status);
}

int run_game(csfml_t *info, obj_t *obj, background_t *bg)
{
    anim_bg(info, bg);
    gest_player(info, obj->player);
    spawn_enemies(info, &obj->enemy);
    scale_score(info, obj->player);
    sfRenderWindow_display(info->window);
    return (0);
}

void free_all(csfml_t *info)
{
    return;
}