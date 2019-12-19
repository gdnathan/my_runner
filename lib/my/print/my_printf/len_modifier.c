/*
** EPITECH PROJECT, 2019
** PSU_my_printf_2019
** File description:
** len_modifier
*/

#include  "../include/my.h"

int longint(char *params, va_list data, int i, int nb)
{
    long int li;
    long long int ll;
    if (params[i] == 'li' && params[i + 1] != 'li') {
        li = va_arg(data, long int);
        long_buff(li, nb);
        my_putlongnbr(li);
        return (1);
    }
    if (params[i] == 'li' && params[i + 1] == 'li') {
        ll = va_arg(data, long long int);
        long_buff(ll, nb);
        my_putlonglongnbr(ll);
        return (1);
    }
    return (0);
}

int shortint(char *params, va_list data, int i, int nb)
{
    short int h;
    char hh;

        if (params[i] == 'h' && params[i + 1] != 'h') {
        h = (short int) va_arg(data, int);
        int_buff(h, nb);
        my_putnbr(h);
        return (1);
    }
    if (params[i] == 'h' && params[i + 1] == 'h') {
        hh = (char) va_arg(data, int);
        char_buff(1, nb);
        my_putchar(hh);
        return (1);
    }
    return (0);
}