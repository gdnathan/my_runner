/*
** EPITECH PROJECT, 2019
** PSU_my_printf_2019
** File description:
** my_printf_int
*/

#include "../include/my.h"

int character(va_list data, char *params)
{
    char c;

    c = (char) va_arg(data, int);
    char_buff(1, my_getnbr(params));
    my_putchar (c);
    return (0);
}

int string(va_list data, char *params)
{
    char *str;

    str = va_arg(data, char *);
    char_buff(my_strlen(str), my_getnbr(params));
    my_putstr(str);
    return (0);
}

int pointer(va_list data, char *params)
{
    int a;

    a = va_arg(data, int);
    my_putstr("0x");
    my_putnbr_base(a, "0123456789ABCDEF");
    return (0);
}

int number(va_list data, char *params)
{
    int len;
    char *str;

    str = va_arg(data, char *);
    len = my_strlen(str);
    char_buff(len, my_getnbr(params));
    my_putnbr(len);
    return (0);
}