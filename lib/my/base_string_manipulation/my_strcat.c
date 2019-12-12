/*
** EPITECH PROJECT, 2019
** lib
** File description:
** lib
*/

#include "my.h"

char *my_strcat(char *dest, char const *src)
{
    int i_dest = my_strlen(dest);
    int i_src = 0;

    while (src[i_src] != '\0') {
        dest[i_dest] = src[i_src];
        i_dest += 1;
        i_src += 1;
    }
    return (dest);
}