/*
** EPITECH PROJECT, 2019
** revstr
** File description:
** task03
*/

#include "my.h"

char *my_revstr(char *str)
{
    int m;
    int a = 0;
    int b = 0;
    int n;

    while (str[b] != '\0'){
        b++;
    }
    b -= 1;
    m = b/2;
    while (a <= m ){
        n = str[a];
        str[a] = str[b];
        str[b] = n;
        a++;
        b = b - 1;
    }
    return (str);
}
