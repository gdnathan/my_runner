/*
** EPITECH PROJECT, 2019
** y_strlen.c
** File description:
** Task03
*/

#include "../include/my.h"

int my_strlen(char const *str)
{
    int i = 0;

    while (str[i] != '\0') {
        i++;
    }
    return (i);
}
