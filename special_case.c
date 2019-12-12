/*
** EPITECH PROJECT, 2019
** MUL_my_runner_2019
** File description:
** special_case
*/

#include "my_runner.h"

int special_case(char *arg)
{
    char *msg = "Arguments possible:"
    "\n\t-i           -> infinite mode\n\t-h / --help  -> display this help"
    "\n\nCommands:\n\n\tspace: fly\n\tenter: attack\n\nHave a good time!";
    if (my_strcmp(arg, "-h") == 1 || my_strcmp(arg, "--help") == 1) {
        my_putstr("Welcome to the Dark Forest Rush!\n\n");
        my_putstr(msg);
    } else if (my_strcmp(arg, "-i") == 1)
        return (infinite_mode);
    else {
        my_putstr("Wrong token\n");
        my_putstr(msg);
    }
}