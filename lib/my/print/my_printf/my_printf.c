/*
** EPITECH PROJECT, 2019
** my_printf
** File description:
** print what i want
*/

#include "../include/my.h"

int comparator(char flag, char flags_pan[15], va_list ap, char *params)
{
    int (*fptr[14])(va_list, char *);
    int j = 0;

    my_array(fptr);
    while (flags_pan[j] != '\0') {
        if (flag == flags_pan[j]) {
            fptr[j](ap, params);
            return (0);
        }
        j += 1;
    }
    return (error(flag, ap, params));
}

int my_printf(char *str, ...)
{
    char *flag;
    int i = 0;
    va_list ap;

    va_start(ap, str);
    while (str[i] != '\0') {
        i = flag_gest(ap, str, i);
        if (i == -84)
            return (84);
        i += 1;
    }
    va_end(ap);
    return (0);
}

int flag_gest(va_list ap, char *str, int i)
{
    char params[] = "0";
    char flags_pan[14] = "dioxXucspn% bS";

    while (str[i] != '%'){
        if (str[i] == '\0')
            return (i);
        my_putchar(str[i]);
        i += 1;
    }
    i = parameters(str, i, params);
    i += 1;
    if (comparator(str[i], flags_pan, ap, params) == 84)
        return (-84);
    if (str[i + 1] == '\n') {
        my_putchar('\n');
        i += 1;
    }
    return (i);
}

//const func_t tab[] = {&dec_int};

void my_array(int (*fptr[14])(va_list, char *))
{
    fptr[0] = &dec_int;
    fptr[1] = &dec_int;
    fptr[2] = &oct_int;
    fptr[3] = &hex_int;
    fptr[4] = &hex_int;
    fptr[5] = &uns_int;
    fptr[6] = &character;
    fptr[7] = &string;
    fptr[8] = &pointer;
    fptr[9] = &number;
    fptr[10] = &noarg;
    fptr[11] = &noarg;
    fptr[12] = &bin;
    fptr[13] = &oct_str;
}