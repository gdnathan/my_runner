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

    while (status != CLOSE && status != 0) {
        if (status == 3)
            status = display_command_menu(status, window);
        else
            status = display_main_menu(status, window, params);
    }
    sfRenderWindow_destroy(window);
    return (status);
}

int display_main_menu(int status, sfRenderWindow *window, params_t *params)
{
    sfTexture *texture0;
    sfTexture *texture1;
    sfTexture *texture2;
    sfSprite *sprite0;
    sfSprite *sprite1;
    sfSprite *sprite2;
    sfVector2i mouse_pos = sfMouse_getPositionRenderWindow(window);
    sfEvent event;

    sfRenderWindow_pollEvent(window, &event);
    texture0 = sfTexture_createFromFile("data/home_screen_easy.png", NULL);
    texture1 = sfTexture_createFromFile("data/home_screen_medium.png", NULL);
    texture2 = sfTexture_createFromFile("data/home_screen_hard.png", NULL);
    sprite0 = sfSprite_create();
    sprite1 = sfSprite_create();
    sprite2 = sfSprite_create();
    sfSprite_setTexture(sprite0, texture0, sfTrue);
    sfSprite_setTexture(sprite1, texture1, sfTrue);
    sfSprite_setTexture(sprite2, texture2, sfTrue);
    //set_difficulty(window, params);
    if (mouse_pos.y < 240 && mouse_pos.y > 400 && event.type ==
    sfEvtMouseButtonPressed && event.mouseButton.button == sfMouseLeft) {
        status = 3;
    }
    sfRenderWindow_drawSprite(window, sprite0, NULL);
    return (status);
}

int display_command_menu(int status, sfRenderWindow *window)
{
    sfTexture *texture = sfTexture_createFromFile("commands_screen.png", NULL);
    sfSprite *sprite = sfSprite_create();

    sfSprite_setTexture(sprite, texture, sfTrue);
    return (3);
}