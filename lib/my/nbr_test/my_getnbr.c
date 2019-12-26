/*
** EPITECH PROJECT, 2019
** my_getnbr
** File description:
** Task05
*/

#include "my.h"

int my_getnbr(char const *str)
{
    int i = 0;
    int x = 0;
    int s = 1;

    while (48 <= str[i] && 57 >= str[i] || str[i] == '-' || str[i] == '+'){
        if (48 <= str[i] && 57 >= str[i]){
            x = x * 10 + (str[i] - '0');
        } else if ( str[i] == '-'){
            s = s * (-1);
        }
        i = i + 1;
    }
    return (x * s);
}
