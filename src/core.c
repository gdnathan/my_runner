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
    player_t player;
    background_t bg;
    int status = 0;

    init_info(&info);
    init_background(&bg);
    init_player(&player);
    status = game(&info, &player, &bg);
    free_all(&info);
    return (status);
}

int game(csfml_t *info, player_t *player, background_t *bg)
{
    int status = 0;

    while (sfRenderWindow_isOpen(info->window) && status == 0) {
        sfRenderWindow_pollEvent(info->window, &info->my_event);
        if (info->my_event.type == sfEvtClosed)
            sfRenderWindow_destroy(info->window);
        status = run_game(info, player, bg);
    }
    return (status);
}

int run_game(csfml_t *info, player_t *player, background_t *bg)
{
    disp_bg(info, bg);
    gest_player(info, player);
    sfRenderWindow_display(info->window);
    return (0);
}

void free_all(csfml_t *info)
{
    return;
}