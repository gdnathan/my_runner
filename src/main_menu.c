/*
** EPITECH PROJECT, 2019
** MUL_my_runner_2019
** File description:
** main_menu
*/

#include "my_runner.h"
#include "csfml.h"

int main_menu(params_t *params, bool infinite)
{
    int status = 1;
    sfRenderWindow *window = create_window(640, 481);
    menu_t menu;

    init_menu(&menu);
    while (status != CLOSE && status != 0) {
        if (status == 3)
            status = display_command_menu(status, window, &menu);
        else {
            status = display_main_menu(status, window, params, &menu);
            print_best_score(window, infinite, params);
        }
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
    if (sfRenderWindow_pollEvent(window, &event) != sfFalse) {
        set_difficulty(params, mouse_pos, event);
        if (mouse_pos.y > 240 && mouse_pos.y < 400 && event.type ==
        sfEvtMouseButtonPressed && event.mouseButton.button == sfMouseLeft) {
            status = 3;
        }
        if (mouse_pos.y > 0 && mouse_pos.y < 240 && event.type ==
        sfEvtMouseButtonPressed && event.mouseButton.button == sfMouseLeft) {
            status = 0;
        }
    }
    if (params->difficulty == 0)
        sfRenderWindow_drawSprite(window, menu->sprite0, NULL);
    if (params->difficulty == 1)
        sfRenderWindow_drawSprite(window, menu->sprite1, NULL);
    if (params->difficulty == 2)
        sfRenderWindow_drawSprite(window, menu->sprite2, NULL);
    return (status);
}

void print_best_score(sfRenderWindow *window, bool infinite, params_t *params)
{
    sfText *txt = sfText_create();
    sfFont *font = sfFont_createFromFile("data/Amatic-Bold.ttf");
    sfVector2f pos;

    pos.x = 200;
    pos.y = 220;
    sfText_setFont(txt, font);
    sfText_setColor(txt, sfWhite);
    sfText_setPosition(txt, pos);
    sfText_setCharacterSize(txt, 50);
    sfText_setString(txt, "BEST SCORE:");
    sfRenderWindow_drawText(window, txt, NULL);
    pos.x += 150;
    sfText_setPosition(txt, pos);
    if (infinite == false) {
        sfText_setString(txt, params->best_scores[params->difficulty]);
    } else {
        sfText_setString(txt, params->best_scores[params->difficulty + 3]);
    }
    sfRenderWindow_drawText(window, txt, NULL);
}