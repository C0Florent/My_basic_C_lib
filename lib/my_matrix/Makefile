##
## EPITECH PROJECT, 2022
## My_matrix Makefile
## File description:
## Compiles properly all files from my_matrix lib
## into a binary `libmy_matrix.a`
##

SRC	=	alloc_matrix_t.c		\
			set_to_zero.c			\
			set_to_id.c				\
			scalar.c				\
			matrix_copy.c			\
			matrix_product.c		\
			matrix_t_free.c			\
			show_matrix.c			\
			transpose.c				\
			submatrix.c				\
			determinant.c			\
			comatrix.c				\
			inverse.c

## By default, there are no additional CFLAGS, this
## variable is there to allow other Makefiles calling
## this one to add CFLAGS such as -g or --coverage
ADDITIONAL_CFLAGS	=

CFLAGS	=	-I../../include -Wall -Wextra -Wshadow -Werror $(ADDITIONAL_CFLAGS)

OBJ	=	$(SRC:.c=.o)

LIBNAME	=	libmy_matrix.a

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
