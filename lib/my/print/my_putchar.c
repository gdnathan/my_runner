/*
** EPITECH PROJECT, 2019
** myputchar
** File description:
** le incroyable MYPUTCHAR
*/

#include <unistd.h>

void my_putchar(char c)
{
    write (1, &c, 1);
}
