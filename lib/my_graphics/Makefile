##
## EPITECH PROJECT, 2022
## My_graphics Makefile
## File description:
## Compiles the my_graphics library
##

SRC	=	vctr.c							\
		my_create_window.c				\
		my_create_sprite_from_file.c	\
		destroy_disp_sprt.c				\
		slidebar/create_slidebar.c		\
		slidebar/display_slidebar.c		\
		slidebar/move_cursor.c			\
		slidebar/destroy_slidebar.c

OBJ	=	$(SRC:.c=.o)

NAME	=	libmy_graphics.a

CFLAGS	=	-Wall -Wextra -Wshadow -Werror -I../../include

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
