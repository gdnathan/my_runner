/*
** EPITECH PROJECT, 2019
** my_strncpy
** File description:
** task02
*/

#include "my.h"

char *my_strncpy(char *dest, char const *src, int n)
{
    int i = 0;

    while (src[n] != '\0'){
        dest[i] = src[n];
        i += 1;
        n += 1;
    }
    dest[i] = '\0';
    return (dest);
}

//dont forget to use my_strdup(dstr, len); on dest AND src
//when u call this function, or it will segfault!