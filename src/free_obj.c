/*
** EPITECH PROJECT, 2019
** MUL_my_runner_2019
** File description:
** free_obj
*/

#include "my_runner.h"

void free_enemy(enemy_t *enemy)
{
    enemy_t *del = enemy;

    while (enemy->next != NULL) {
        enemy = enemy->next;
        sfSprite_destroy(del->sprite);
        sfTexture_destroy(del->texture);
        free (del);
        del = enemy;
    }
    sfSprite_destroy(enemy->sprite);
    sfTexture_destroy(enemy->texture);
    free (enemy);
}

void free_player(player_t *player)
{
    fireball_t *del = NULL;

    sfSprite_destroy(player->sprite);
    sfTexture_destroy(player->texture);
    if (player->fireball != NULL) {
        del = player->fireball;
        while (player->fireball->next != NULL) {
            player->fireball = player->fireball->next;
            sfSprite_destroy(del->sprite);
            sfTexture_destroy(del->texture);
            free (del);
            del = player->fireball;
        }
        sfSprite_destroy(player->fireball->sprite);
        sfTexture_destroy(player->fireball->texture);
    }
    free (player->fireball);
    free (player);
}

void free_xp(xp_t *xp)
{
    if (xp == NULL)
        return;
    sfSprite_destroy(xp->sprite);
    sfTexture_destroy(xp->texture);
    free(xp);
}