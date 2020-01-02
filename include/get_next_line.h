/*
** EPITECH PROJECT, 2019
** CPE_getnextline_2019
** File description:
** gnl
*/

#ifndef GNL_H_
#define GNL_H_

void create(int fd, char **stack);
char *get_next_line(int fd);
char *re_alloc(char *str, int content, int k);
char *fill_new_line(int size, int *i, char *stack, char *line);

#define READ_SIZE (5)

#endif /* !GNL_H_ */
