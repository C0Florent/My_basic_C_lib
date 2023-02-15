##
## EPITECH PROJECT, 2022
## Libmy Makefile
## File description:
## Compiles the libmy (the most basic functions) into a libmy.a
##

SRC	=	my_putchar.c			\
		my_putstr.c				\
		my_swap.c				\
		my_compute_power_rec.c	\
		my_compute_square_root.c\
		my_is_prime.c			\
		my_find_prime_sup.c		\
		my_strlen.c				\
		my_charcat.c			\
		my_strcat.c				\
		my_strncat.c			\
		my_strcpy.c				\
		my_strncpy.c			\
		my_strdup.c				\
		my_strcmp.c				\
		my_strncmp.c			\
		my_strstr.c				\
		my_strlowcase.c			\
		my_strupcase.c			\
		my_strcapitalize.c		\
		my_revstr.c				\
		my_str_isalpha.c		\
		my_str_isnum.c			\
		my_str_isupper.c		\
		my_str_islower.c		\
		my_str_isprintable.c	\
		my_show_word_array.c	\
		my_str_to_word_array.c 	\
		my_getnbr.c				\
		my_sort_int_array.c		\
		my_shift_str.c			\
		my_str_initialise.c		\
		my_compute_float_power.c\
		my_char_is_in_list.c

OBJ	=	$(SRC:.c=.o)

NAME	=	libmy.a

## By default, there are no additional CFLAGS, this
## variable is there to allow other Makefiles calling
## this one to add CFLAGS such as -g or --coverage
ADDITIONAL_CFLAGS	=

CFLAGS	=	-Wall -Wextra -Wshadow -Werror -I../../include $(ADDITIONAL_CFLAGS)

all:	$(NAME)

$(NAME): $(OBJ)
	ar rc $(NAME) $(OBJ)
	mv $(NAME) ../

clean:
	@echo -e "\033[1;3;30m Removing object files\033[0m"
	@rm -f $(OBJ)

fclean: clean
	rm -f ../$(NAME)

re: fclean all
