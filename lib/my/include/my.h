/*
** EPITECH PROJECT, 2019
** my.h
** File description:
** protos
*/

#include <stdarg.h>
#include <stdio.h>
#include <stdlib.h>

void my_putchar(char c);
int my_putnbr(int nb);
int my_putstr(char const *str);
char *my_strncpy(char *dest, char const *src, int n);
void my_dec_to_hex(int nb);
void my_putchar(char c);
char *my_strdup(char const *src, int len);
int my_putnbr_base(unsigned int nb, char *base);
int my_strlen(char const *str);
int my_putunbr(unsigned int nb);
int my_nbrlen(int nb);
char *my_revstr(char *str);
int error(char flag, va_list data, char *);
int my_putunbr(unsigned int nb);
int my_printf(char *str, ...);
int my_putlongnbr(long int nb);
int my_putlonglongnbr(long long int nb);
int my_strncmp(char const *s1, char const *s2, int n);
double dist(double xA, double yA, double xB, double yB);
int my_strcmp(char const *s1, char const *s2);
int my_getnbr(char const *str);


//
// my_printf function's prototypes
//
int my_printf(char *str, ...);
void my_array(int (*fptr[14])(va_list, char *));
int dec_int(va_list, char *);
int oct_int(va_list, char *);
int hex_int(va_list, char *);
int uns_int(va_list, char *);
int character(va_list, char *);
int string(va_list, char *);
int pointer(va_list data, char *);
int number(va_list data, char *);
int noarg(va_list data, char *);
int error(char flag, va_list data, char *);
int bin(va_list data, char *);
int longint(char *params, va_list data, int i, int nb);
int shortint(char *params, va_list data, int i, int nb);
int flag_gest(va_list ap, char *str, int i);
int parameters(char *str, int i, char *params);
int int_params(char *params, char *str, int i, int j);
int int_buff(int nb, int buff_len);
int long_buff(long int nb, int buff_len);
int char_buff(int nb, int buff_len);
int flag_gest(va_list ap, char *str, int i);
int oct_str(va_list data, char *);
char *my_nbr_to_str(int nb);