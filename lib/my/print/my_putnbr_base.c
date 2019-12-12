/*
** EPITECH PROJECT, 2019
** my_put nbr base
** File description:
** convert without time fckn out
*/

#include "../include/my.h"

int my_putnbr_base(unsigned int nb, char *base)
{
    int mod;

    if (nb > 0) {
        mod = nb % my_strlen(base);
        my_putnbr_base(nb / my_strlen(base), base);
        my_putchar(base[mod]);
    }
}
