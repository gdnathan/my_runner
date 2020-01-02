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
    if (WINDOW_LEN < 500 || WINDOW_LEN > 2534) {
        my_putstr("/!\\ PARAMETER ERROR!\nhere -> WINDOW_LEN = ");
        my_putnbr(WINDOW_LEN);
        my_putstr("\nplease enter a number between 500 and 2534\n");
        return (ERROR);
    }
    return (0);
}