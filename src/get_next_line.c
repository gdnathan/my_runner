/*
** EPITECH PROJECT, 2019
** CPE_getnextline_2019
** File description:
** gnl
*/

#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include "get_next_line.h"

char *get_next_line(int fd)
{
    static int i = 0;
    static char *stack;
    static int status = 0;
    int size = i + 1;
    char *line = NULL;

    if (fd == -1 || status == 2)
        return NULL;
    if (status == 0) {
        stack = malloc(sizeof(char) * READ_SIZE + 1);
        create(fd, &stack);
        status = 1;
    }
    while (stack[size] != '\n' && stack[size] != '\0') {
        size += 1;
    }
    if (stack[size] == '\0' || stack[size] == '\n' && stack[size + 1] == '\0')
        status = 2;
    line = fill_new_line(size, &i, stack, line);
    return line;
}

char *fill_new_line(int size, int *i, char *stack, char *line)
{
    int j = 0;

    line = malloc(sizeof(char) * (size - *i) + 1);
    while (*i < size) {
        line[j] = stack[*i];
        j += 1;
        *i += 1;
    }
    line[j] = '\0';
    *i += 1;
    return (line);
}

void create(int fd, char **stack)
{
    char buffer[READ_SIZE + 1];
    int content = READ_SIZE;
    int size = 0;
    int k = 0;
    int b = 0;

    while (content == READ_SIZE) {
        content = read(fd, buffer, READ_SIZE);
        *stack = re_alloc(*stack, content, size);
        size += content;
        while (b < READ_SIZE && buffer[b]) {
            (*stack)[k] = buffer[b];
            k += 1;
            b += 1;
        }
        while (b > 0) {
            buffer[b] = '\0';
            b -= 1;
        }
    }
}

char *re_alloc(char *str, int content, int size)
{
    int i = 0;
    char *new;

    if (str == NULL)
        return NULL;
    while (str == NULL && str[i] != '\0') {
        i += 1;
    }
    new = malloc(sizeof(char) * (i + content + 1 + size));
    i = 0;
    while (str[i] != '\0') {
        new[i] = str[i];
        i += 1;
    }
    free (str);
    return (new);
}