/*
** EPITECH PROJECT, 2019
** MUL_my_runner_2019
** File description:
** errors
*/

#include "my_runner.h"
#include "game_parameters.h"

int errors(int arg_nb, char **env)
{
    if (arg_nb > 2)
        return (ERROR);
    if (env[0] == NULL)
        return (ERROR);
    return (game_parameters());
}

int game_parameters(void)
{
    if (MAX_FIREBALL <= 0){
        my_putstr("/!\\ PARAMETER ERROR!\n");
        my_putstr("here -> MAX_FIREBALL = ");
        my_putnbr(MAX_FIREBALL);
        my_putchar('\n');
        return (84);
    }
    return (0);
}