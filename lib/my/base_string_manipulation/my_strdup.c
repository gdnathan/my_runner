/*
** EPITECH PROJECT, 2019
** my_strdup
** File description:
** duplicate a string
*/

#include <stdlib.h>
#include "my.h"

char *my_strdup(char const *src, int len)
{
    char *str;
    int i = 0;

    str = malloc((sizeof(char)) * (len + 1));
    while (src[i] != '\0') {
        str[i] = src[i];
        i += 1;
    }
    str[i] = '\0';
    return (str);
}
