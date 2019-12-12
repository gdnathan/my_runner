/*
** EPITECH PROJECT, 2019
** PSU_my_printf_2019
** File description:
** buffs
*/

#include "../include/my.h"

int int_buff(int nb, int buff_len)
{
    int nb_len = my_nbrlen(nb);

    while (buff_len > nb_len) {
        my_putchar(32);
        buff_len -= 1;
    }
    return (my_nbrlen(buff_len));
}

int long_buff(long int nb, int buff_len)
{
    int nb_len = my_longnbrlen(nb);

    while (buff_len > nb_len) {
        my_putchar(32);
        buff_len -= 1;
    }
    return (my_nbrlen(buff_len));
}

int char_buff(int nb, int buff_len)
{
    while (buff_len > nb) {
        my_putchar(32);
        buff_len -= 1;
    }
    return (my_nbrlen(buff_len));
}