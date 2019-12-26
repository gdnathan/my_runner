/*
** EPITECH PROJECT, 2019
** is alpha
** File description:
** test is a character is alpha-numeric
*/

#include "my.h"

int my_isalphanum(char const i)
{
    if (i >= '0' && i <= '9') {
        return (1);
    }
    if (i >= 'a' && i <= 'z') {
        return (1);
    }
    if (i >= 'A' && i <= 'Z') {
    return (1);
    }
    return (0);
}
