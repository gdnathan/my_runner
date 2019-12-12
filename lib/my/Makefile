##
## EPITECH PROJECT, 2019
## makefile
## File description:
## makefile for stdout
##

SRC		=   \
print/my_putchar.c          \
print/my_putnbr_base.c      \
print/my_putnbr.c           \
print/my_putstr.c           \
print/my_putunbr.c          \
base_string_manipulation/my_revstr.c        \
base_string_manipulation/my_strcat.c        \
base_string_manipulation/my_strcmp.c        \
base_string_manipulation/my_strcpy.c        \
base_string_manipulation/my_strdup.c        \
base_string_manipulation/my_strlen.c        \
base_string_manipulation/my_strncat.c         \
base_string_manipulation/my_strncmp.c         \
base_string_manipulation/my_strncpy.c         \


##here are all function of the lib.
##move them under SRC to start to use them
## \
nbr_test/my_getnbr.c        \
nbr_test/my_is_prime.c      \
nbr_test/my_isalphanum.c    \
nbr_test/my_isneg.c         \
nbr_test/my_nbrlen.c        \
nbr_test/my_swap.c          \
calc/my_compute_power_rec.c         \
calc/my_compute_square_root.c       \
"others_string_manipulation"/concat_params.c            \
"others_string_manipulation"/my_show_word_array.c       \
"others_string_manipulation"/my_sort_int_array.c        \
"others_string_manipulation"/my_str_to_word_array.c     \
"others_string_manipulation"/my_strcapitalize.c         \
"others_string_manipulation"/my_strlowcase.c            \
"others_string_manipulation"/my_strstr.c                \
"others_string_manipulation"/my_strupcase.c             \
print/my_printf/buffs.c                 \
print/my_printf/len_modifier.c          \
print/my_printf/my_parameters.c         \
print/my_printf/my_printf_char.c        \
print/my_printf/my_printf_int.c         \
print/my_printf/my_printf_others.c      \
print/my_printf/my_printf.c             \
"string test"/my_str_isalpha.c          \
"string test"/my_str_isislower.c        \
"string test"/my_str_isnum.c            \
"string test"/my_str_isprintable.c      \
"string test"/my_str_isupper.c          \

OBJ 	= 	$(SRC:.c=.o)

NAME 	=	libmy.a

CFLAGS	=	-Iinclude

all:	$(NAME) clean

$(NAME):	$(OBJ)
	ar rc $(NAME) $(OBJ)

debug:	fclean	$(OBJ)
	gcc -o $(NAME) $(OBJ) -W -Wall -Wextra -g

clean:
		rm -f $(OBJ)

fclean: clean
		rm -f $(NAME)

%.o:    %.c
		@echo -n "Compiling... : $<"
		@$(CC) $(CFLAGS) -c $< -o $@ && echo " [\033[32mOK\033[0m]" || echo " [\033[31mKO\033[0m]"

re:	fclean all
