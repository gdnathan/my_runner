/*
** EPITECH PROJECT, 2020
** MUL_my_runner_2019
** File description:
** init_menu
*/

#include "csfml.h"
#include "my_runner.h"

void init_menu(menu_t *menu)
{
    menu->texture0 = sfTexture_createFromFile("data/home_screen_easy.png",
                                                NULL);
    menu->texture1 = sfTexture_createFromFile("data/home_screen_medium.png",
                                                NULL);
    menu->texture2 = sfTexture_createFromFile("data/home_screen_hard.png",
                                                NULL);
    menu->sprite0 = sfSprite_create();
    menu->sprite1 = sfSprite_create();
    menu->sprite2 = sfSprite_create();
    menu->tCommand = sfTexture_createFromFile("data/commands_screen.png", NULL);
    menu->sCommand = sfSprite_create();
    sfSprite_setTexture(menu->sprite0, menu->texture0, sfTrue);
    sfSprite_setTexture(menu->sprite1, menu->texture1, sfTrue);
    sfSprite_setTexture(menu->sprite2, menu->texture2, sfTrue);
    sfSprite_setTexture(menu->sCommand, menu->tCommand, sfTrue);
}