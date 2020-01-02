/*
** EPITECH PROJECT, 2019
** MUL_my_runner_2019
** File description:
** main
*/

#include "my_runner.h"

int main(int argc, char **argv, char **env)
{
    if (errors(argc, env) == ERROR)
        return ERROR;
    if (argv[1])
        return (special_case(argv[1]));
    return (core_infinite());
}