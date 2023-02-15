##
## EPITECH PROJECT, 2022
## Libmy Makefile
## File description:
## Compiles the libmy (the most basic functions) into a libmy.a
##

SRC	=	get_file_size.c

OBJ	=	$(SRC:.c=.o)

NAME	=	libmysys.a

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
