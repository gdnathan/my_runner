/*
** EPITECH PROJECT, 2019
** MUL_my_runner_2019
** File description:
** my_nbr_to_str
*/

#include "my.h"

char *my_nbr_to_str(int nb)
{
    int size = my_nbrlen(nb);
    char *str = malloc(sizeof(char) * (size + 3));
    int i = 0;

    while (i < size) {
        str[i] = (nb % 10) + 48;
        nb = nb / 10;
        i += 1;
    }
    str[i] = 'x';
    str[i + 1] = ' ';
    str[i + 2] = '\0';
    return (my_revstr(str));
}