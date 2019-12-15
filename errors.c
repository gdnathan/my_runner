/*
** EPITECH PROJECT, 2019
** MUL_my_runner_2019
** File description:
** errors
*/

#include "my_runner.h"

int errors(int arg_nb, char **env)
{
    if (arg_nb > 2)
        return (ERROR);
    if (env[0] == NULL)
        return (ERROR);
    return (0);
}