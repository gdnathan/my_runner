##
## EPITECH PROJECT, 2019
## makefile
## File description:
## makefile for infadd prog
##

SRC		=	main.c				\
			core.c				\
			infinite_mode.c		\
			errors.c			\
			special_case.c

OBJ	    =	$(SRC:.c=.o)

NAME	=	my_runner

LIB     =	-Llib/my -lmy

CFLAGS	=	-Iinclude

all:	$(NAME)

DOLIB:
	$(MAKE) -C ./lib/my

$(NAME): DOLIB $(OBJ)
	$(CC) -o $(NAME) $(CFLAGS) $(OBJ) $(LIB)


clean:
	rm -f $(OBJ)
	$(MAKE) clean -C lib/my

debug:	fclean $(LIB) $(OBJ)
	$(CC) $(SRC) $(LIB) -W -Wall -Wextra -g

test: fclean $(LIB) $(OBJ)
	$(CC) -o unit_tests $(SRC) $(LIB) tests/test.c --coverage -lcriterion

fclean:	clean
	rm -f $(NAME) *.gc*
	$(MAKE) fclean -C lib/my

re:	fclean all

%.o:    %.c
		@echo -n "Compiling... : $<"
		@$(CC) $(CFLAGS) -c $< -o $@ && echo " [\033[32mOK\033[0m]" || echo " [\033[31mKO\033[0m]"

.PHONY: all clean fclean re debug test
