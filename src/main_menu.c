/*
** EPITECH PROJECT, 2019
** MUL_my_runner_2019
** File description:
** main_menu
*/

#include "my_runner.h"
#include "csfml.h"

int main_menu(params_t *params)
{
    int status = 1;
    sfRenderWindow *window = create_window(640, 481);
    menu_t menu;

    init_menu(&menu);
    while (status != CLOSE && status != 0) {
        if (status == 3)
            status = display_command_menu(status, window, &menu);
        else
            status = display_main_menu(status, window, params, &menu);
    status = close_menu(window, status);
    sfRenderWindow_display(window);
    }
    sfRenderWindow_destroy(window);
    return (status);
}

int display_main_menu(int status, sfRenderWindow *window,
                    params_t *params, menu_t *menu)
{
    sfVector2i mouse_pos = sfMouse_getPositionRenderWindow(window);
    sfEvent event;

    sfRenderWindow_pollEvent(window, &event);
    set_difficulty(params, mouse_pos, event);
    if (mouse_pos.y > 240 && mouse_pos.y < 400 && event.type ==
    sfEvtMouseButtonPressed && event.mouseButton.button == sfMouseLeft) {
        status = 3;
    }
    if (mouse_pos.y > 0 && mouse_pos.y < 240 && event.type ==
    sfEvtMouseButtonPressed && event.mouseButton.button == sfMouseLeft) {
        status = 0;
    }
    if (params->difficulty == 0)
        sfRenderWindow_drawSprite(window, menu->sprite0, NULL);
    if (params->difficulty == 1)
        sfRenderWindow_drawSprite(window, menu->sprite1, NULL);
    if (params->difficulty == 2)
        sfRenderWindow_drawSprite(window, menu->sprite2, NULL);
    return (status);
}