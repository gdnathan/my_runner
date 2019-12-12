/*
** EPITECH PROJECT, 2019
** my_put_u_number.c
** File description:
** put unsigned number
*/

#include <unistd.h>
#include "../include/my.h"

int my_putunbr(unsigned int nb)
{
    int mod;

    if (nb > 0) {
        mod = nb % 10;
        my_putnbr(nb/10);
        my_putchar(mod + 48);
    }
}
