/*
** EPITECH PROJECT, 2019
** MUL_my_runner_2019
** File description:
** init_xp
*/

#include "csfml.h"
#include "my_runner.h"
#include "game_parameters.h"

void new_xp(xp_t **xp)
{
    xp_t *new = NULL;

    if (*xp == NULL) {
        *xp = init_xp();
    } else {
        new = *xp;
        while (new->next != NULL){
            new = new->next;
        }
        new->next = init_xp();
    }
}

xp_t *init_xp(void)
{
    xp_t *new = malloc(sizeof(xp_t));

    new->pos = malloc(sizeof(sfVector2f));
    new->texture = sfTexture_createFromFile("data/xp.png", NULL);
    new->sprite = sfSprite_create();
    new->pos->x = WINDOW_LEN;
    new->pos->y = rand() % (355 - 50) + 50;
    new->next = NULL;
    sfSprite_setTexture(new->sprite, new->texture, sfTrue);
    new->destroyed = NULL;
    return (new);
}