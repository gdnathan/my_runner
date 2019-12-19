/*
** EPITECH PROJECT, 2019
** my_strcmp
** File description:
** task06
*/

#include "../include/my.h"

int my_strcmp(char const *s1, char const *s2)
{
    int i = 0;

    while (s1[i] != '\0' && s2[i] != '\0') {
        if (s1[i] != s2[i])
            return (0);
        i += 1;
    }
    if (s1[i] != '\0' || s2[i] != '\0')
        return (0);
    return (1);
}
