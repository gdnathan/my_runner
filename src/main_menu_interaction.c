/*
** EPITECH PROJECT, 2020
** MUL_my_runner_2019
** File description:
** main_menu_interaction
*/

#include "csfml.h"
#include "my_runner.h"

int display_command_menu(int status, sfRenderWindow *window, menu_t *menu)
{
    sfEvent event;
    sfVector2i mouse_pos = sfMouse_getPositionRenderWindow(window);

    sfRenderWindow_pollEvent(window, &event);
    sfRenderWindow_drawSprite(window, menu->sCommand, NULL);
    if (mouse_pos.y > 0 && mouse_pos.y < 50 && mouse_pos.x > 0 &&
        mouse_pos.x < 100 && event.type == sfEvtMouseButtonPressed &&
        event.mouseButton.button == sfMouseLeft) {
            return (1);
    }
    return (3);
}

void set_difficulty(params_t *params, sfVector2i mouse_pos, sfEvent event)
{

    if (mouse_pos.y > 440 && mouse_pos.y < 470 && mouse_pos.x > 256 &&
        mouse_pos.x < 325 && event.type == sfEvtMouseButtonPressed &&
        event.mouseButton.button == sfMouseLeft) {
            params->difficulty = 0;
    }
    if (mouse_pos.y > 440 && mouse_pos.y < 470 && mouse_pos.x > 335 &&
        mouse_pos.x < 472 && event.type == sfEvtMouseButtonPressed &&
        event.mouseButton.button == sfMouseLeft) {
            params->difficulty = 1;
    }
    if (mouse_pos.y > 440 && mouse_pos.y < 470 && mouse_pos.x > 500 &&
        mouse_pos.x < 575 && event.type == sfEvtMouseButtonPressed &&
        event.mouseButton.button == sfMouseLeft) {
            params->difficulty = 2;
    }
}

int close_menu(sfRenderWindow *window, int status)
{
    sfEvent event;
    sfVector2i mouse_pos = sfMouse_getPositionRenderWindow(window);

    sfRenderWindow_pollEvent(window, &event);
    mouse_pos = sfMouse_getPositionRenderWindow(window);
    if (event.type == sfEvtClosed || (mouse_pos.y > 435 && mouse_pos.y < 475 &&
        mouse_pos.x > 7 && mouse_pos.x < 91 && event.type ==
        sfEvtMouseButtonPressed && event.mouseButton.button == sfMouseLeft))
            return (CLOSE);
    return (status);
}