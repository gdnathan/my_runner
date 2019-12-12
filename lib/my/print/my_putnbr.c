/*
** EPITECH PROJECT, 2019
** my_put_number.c
** File description:
** task07
*/

#include <unistd.h>
#include "../include/my.h"

int my_putnbr(int nb)
{
    int mod;

    if (nb < 0) {
        my_putchar('-');
        nb = nb * -1;
    }
    if (nb > 0) {
        mod = nb % 10;
        my_putnbr(nb/10);
        my_putchar(mod + 48);
    }
}

int my_putlongnbr(long int nb)
{
    long int mod;

    if (nb < 0) {
        my_putchar('-');
        nb = nb * -1;
    }
    if (nb > 0) {
        mod = nb % 10;
        my_putlongnbr(nb/10);
        my_putchar(mod + 48);
    }
}

int my_putlonglongnbr(long long int nb)
{
    long long int mod;

    if (nb < 0) {
        my_putchar('-');
        nb = nb * -1;
    }
    if (nb > 0) {
        mod = nb % 10;
        my_putlonglongnbr(nb/10);
        my_putchar(mod + 48);
    }
}
