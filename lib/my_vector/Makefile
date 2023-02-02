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

CFLAGS	=	-I../../include -Wall -Wextra -Wshadow -Werror

OBJ	=	$(SRC:.c=.o)

LIBNAME	=	libmy_vector.a

all:	$(LIBNAME)

$(LIBNAME):	$(OBJ)
	ar rc $(LIBNAME) $(OBJ)
	mv $(LIBNAME) ../

clean:
	@echo -e "\033[1;3;30m Removing object files\033[0m"
	@rm -f $(OBJ)

fclean:	clean
	rm -f ../$(LIBNAME)

re:	fclean all
