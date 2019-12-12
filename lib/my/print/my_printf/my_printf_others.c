/*
** EPITECH PROJECT, 2019
** PSU_my_printf_2019
** File description:
** my_printf_others
*/

#include "../include/my.h"

int noarg(va_list data, char *params)
{
    my_printf("%c\n", '%');
    return (0);
}

int bin(va_list data, char *params)
{
    unsigned int u;

    u = va_arg(data, unsigned int);
    my_putnbr_base(u, "01");
    return (0);
}

int oct_str(va_list data, char *params)
{
    char *str;
    int i = 0;

    str = va_arg(data, char *);
    while (str[i]) {
        if (str[i] < 32 || str[i] >= 127) {
            my_putchar('\\');
            my_putchar('0');
            my_putnbr_base(str[i], "01234567");
        } else {
            my_printf("%c\n", str[i]);
        }
        i += 1;
    }
    return (0);
}

int error(char flag, va_list data, char *params)
{
    write(2, "[?]\n[error: incorect flag]\n", 28);
    my_putstr("     here -> %");
    my_putchar(flag);
    my_putchar('\n');
    return (84);
}