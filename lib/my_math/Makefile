##
## EPITECH PROJECT, 2022
## My_graphics Makefile
## File description:
## Compiles the my_math library
##

SRC	=	put_float_right.c	\
		my_str_is_float.c	\
		approx_eq.c			\
		eval_poly.c

OBJ	=	$(SRC:.c=.o)

NAME	=	libmy_math.a

## By default, there are no additional CFLAGS, this
## variable is there to allow other Makefiles calling
## this one to add CFLAGS such as -g or --coverage
ADDITIONAL_CFLAGS	=

CFLAGS	=	-Wall -Wextra -Wshadow -Werror -I../../include  $(ADDITIONAL_CFLAGS)

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
