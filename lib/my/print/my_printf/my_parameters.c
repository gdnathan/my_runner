/*
** EPITECH PROJECT, 2019
** PSU_my_printf_2019
** File description:
** my_parameters
*/

#include "../include/my.h"

int parameters(char *str, int i, char *params)
{
    char *buffer;
    int j = 0;
    buffer = my_strncpy(my_strdup(str, my_strlen(str)), buffer, i + 1);
    int nb = my_getnbr(buffer);

    while (nb > 0) {
        params[j] = buffer[j];
        nb /= 10;
        j += 1;
    }
    params[j] = '\0';
    j = int_params(params, str, i, j);
    return (i + j);
}

int int_params(char *params, char *str, int i, int j)
{
    while (str[i + j + 1] == 'l') {
        params[j] = 'l';
        j += 1;
    }
    while (str[i + j + 1] == 'h') {
        params[j] = 'h';
        j += 1;
    }
    return (j);
}