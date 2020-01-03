/*
** EPITECH PROJECT, 2019
** MUL_my_runner_2019
** File description:
** core
*/

#include "my_runner.h"
#include "csfml.h"

int core(char *patern)
{
    csfml_t info;
    obj_t obj;
    background_t bg;
    int status = 0;

    load_parameters(&info);
    if (main_menu(info.params) == CLOSE)
        return (CLOSE);
    init_info(&info);
    init_background(&bg);
    init_obj(&obj);
    status = game(&info, &obj, &bg, patern);
    free_all(&info, &obj, &bg);
    return (status);
}

int game(csfml_t *info, obj_t *obj, background_t *bg, char *patern)
{
    int status = 0;

    while (sfRenderWindow_isOpen(info->window) && status == 0) {
        sfRenderWindow_pollEvent(info->window, &info->my_event);
        status = run_game(info, obj, bg, patern);
        if (info->my_event.type == sfEvtClosed)
            status = CLOSE;
        }
    if (status == 2)
        my_putstr("YOU WIN!\n");
    if (status == 1)
        my_putstr("YOU LOSE!\n");
    return (status);
}

int run_game(csfml_t *info, obj_t *obj, background_t *bg, char *patern)
{
    anim_bg(info, bg);
    gest_player(info, obj->player);
    if (spawn_enemies_finite(info, &obj->enemy, patern) == 1)
        return (2);
    spawn_xp(info, &obj->xp);
    collision(info, obj);
    scale_score(info, obj->player);
    sfRenderWindow_display(info->window);
    if (obj->player->health->hp == 0)
        return (LOSE);
    return (0);
}