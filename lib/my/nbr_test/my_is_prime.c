/*
** EPITECH PROJECT, 2019
** prime
** File description:
** task06
*/

#include "my.h"

int my_is_prime(int nb)
{
    int test = 2;
    int res;

    if (nb <= 0)
        return (0);
    if (nb == 1)
        return (0);
    while (test < nb)
    {
        res = nb % test;
        if (res == 0)
        {
            return (0);
        }
        test = test + 1;
    }
    return (1);
}
