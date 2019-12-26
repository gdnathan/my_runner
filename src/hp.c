/*
** EPITECH PROJECT, 2019
** MUL_my_runner_2019
** File description:
** hp
*/

#include "my_runner.h"
#include "csfml.h"

void get_hp(csfml_t *info, player_t *player)
{
    if (player->health->hp <= 3)
        disp_3max_hp(info, player->health);
    else if (player->health->hp > 3)
        disp_inf_hp(info, player->health);
}

void disp_3max_hp(csfml_t *info, health_t *health)
{
    int i = 0;
    sfVector2f pos;

    pos.x = 30;
    pos.y = 450;
    while (i < health->hp) {
        sfSprite_setPosition(health->sprite, pos);
        sfRenderWindow_drawSprite(info->window, health->sprite, NULL);
        pos.x += 50;
        i += 1;
    }
}

void disp_inf_hp(csfml_t *info, health_t *health)
{
    sfVector2f pos;
    sfFont *font = sfFont_createFromFile("data/Amatic-Bold.ttf");
    sfText *current_hp = sfText_create();

    pos.x = 30;
    pos.y = 450;
    sfSprite_setPosition(health->sprite, pos);
    sfRenderWindow_drawSprite(info->window, health->sprite, NULL);
    pos.x += 70;
    sfText_setFont(current_hp, font);
    sfText_setColor(current_hp, sfWhite);
    sfText_setPosition(current_hp, pos);
    sfText_setCharacterSize(current_hp, 30);
    sfText_setString(current_hp, my_nbr_to_str(health->hp));
    sfRenderWindow_drawText(info->window, current_hp, NULL);
}