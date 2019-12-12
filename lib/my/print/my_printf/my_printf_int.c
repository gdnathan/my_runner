/*
** EPITECH PROJECT, 2019
** PSU_my_printf_2019
** File description:
** my_printf_int
*/

#include "../include/my.h"

int dec_int(va_list data, char *params)
{
    int d;
    int nb = my_getnbr(params);
    int i = my_nbrlen(nb);

    if (longint(params, data, i, nb) == 1)
        return (1);
    if (shortint(params, data, i, nb) == 1)
        return (1);
    d = va_arg(data, int);
    int_buff(d, nb);
    my_putnbr(d);
    return (1);
}

int oct_int(va_list data, char *params)
{
    int d;

    d = va_arg(data, int);
    int_buff(d, my_getnbr(params));
    my_putnbr_base(d, "01234567");
    return (0);
}

int hex_int(va_list data, char *params)
{
    unsigned int d;

    d = va_arg(data, unsigned int);
    int_buff(d, my_getnbr(params));
    my_putnbr_base(d, "0123456789ABCDEF");
    return (0);
}

int uns_int(va_list data, char *params)
{
    unsigned int u;

    u = va_arg(data, unsigned int);
    int_buff(u, my_getnbr(params));
    my_putunbr(u);
    return (0);
}