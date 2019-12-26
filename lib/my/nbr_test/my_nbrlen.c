/*
** EPITECH PROJECT, 2019
** PSU_my_printf_2019
** File description:
** my_nbrlen
*/

int my_nbrlen(int nb)
{
    int i = 0;

    while (nb > 0) {
        nb /= 10;
        i += 1;
    }
    return (i);
}

int my_longnbrlen(long int nb)
{
    int i = 0;

    while (nb > 0) {
        nb /= 10;
        i += 1;
    }
    return (i);
}