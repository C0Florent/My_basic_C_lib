##
## EPITECH PROJECT, 2022
## My_matrix Makefile
## File description:
## Compiles properly all files from my_matrix lib
## into a binary `libmy_matrix.a`
##

SRC	=	alloc_vector_t.c	\
		free_vector_t.c		\
		show_vector.c

## By default, there are no additional CFLAGS, this
## variable is there to allow other Makefiles calling
## this one to add CFLAGS such as -g or --coverage
ADDITIONAL_CFLAGS	=

CFLAGS	=	-I../../include -Wall -Wextra -Wshadow -Werror $(ADDITIONAL_CFLAGS)

OBJ	=	$(SRC:.c=.o)

LIBNAME	=	libmy_vector.a



.PHONY:	all clean fclean re

all:	$(LIBNAME)

$(LIBNAME):	$(OBJ)
	ar rc $(LIBNAME) $(OBJ)
	cp $(LIBNAME) ../

clean:
	@echo -e "\033[1;3;30m Removing object files\033[0m"
	@rm -f $(OBJ)

fclean:	clean
	rm -f ../$(LIBNAME)
	rm -f $(NAME)

re:	fclean all
