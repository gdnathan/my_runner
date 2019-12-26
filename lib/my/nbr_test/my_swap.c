/*
** EPITECH PROJECT, 2019
** my_swap.c
** File description:
** Task01
*/

#include "my.h"

void my_swap(int *a, int *b)
{
    int c;

    c = *a;
    *a = *b;
    *b = c;
}
