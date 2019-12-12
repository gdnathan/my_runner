/*
** EPITECH PROJECT, 2019
** my_strncmp
** File description:
** task06
*/

#include "my.h"

int sizen(char const *s);

int my_strncmp(char const *s1, char const *s2, int n)
{
    int i = n;

    while (s1[i] == s2[i] && (s1[i] != '\0' || s2[i] != '\0')) {
            i += 1;
        }
    if (s1[i] == s2[i]) {
        return (0);
    }
    if (s1[i] > s2[i]){
        return (1);
    } else {
        return (-1);
    }
}
