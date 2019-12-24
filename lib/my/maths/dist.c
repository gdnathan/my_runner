/*
** EPITECH PROJECT, 2019
** MUL_my_runner_2019
** File description:
** dist
*/

#include "my.h"
#include "math.h"

int dist(int xA, int yA, int xB, int yB)
{
    return (sqrt(pow((xB - xA), 2) + pow((yB - yA), 2)));
}