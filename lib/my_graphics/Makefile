##
## EPITECH PROJECT, 2022
## My_graphics Makefile
## File description:
## Compiles the my_graphics library
##

SRC	=	vctr.c								\
		my_create_window.c					\
		my_create_sprite_from_file.c		\
		destroy_disp_sprt.c					\
		ui/is_mouse_event.c					\
		ui/get_mouse_pos.c					\
		ui/slidebar/create_slidebar.c		\
		ui/slidebar/display_slidebar.c		\
		ui/slidebar/move_cursor.c			\
		ui/slidebar/set_min_max.c			\
		ui/slidebar/set_cursor_pos_val.c	\
		ui/slidebar/destroy_slidebar.c		\
		ui/button/button_create.c			\
		ui/button/button_destroy.c			\
		ui/button/button_display.c			\
		ui/button/frame_reset.c				\
		ui/button/update_button_state.c		\
		ui/menu/create_menu.c				\
		ui/menu/destroy_menu.c				\
		ui/menu/display_menu.c				\
		ui/menu/display_menu_button.c		\
		ui/menu/display_option_button.c		\
		ui/menu/update_menu.c				\
		ui/menu/add_menu_option.c

OBJ	=	$(SRC:.c=.o)

NAME	=	libmy_graphics.a

## By default, there are no additional CFLAGS, this
## variable is there to allow other Makefiles calling
## this one to add CFLAGS such as -g or --coverage
ADDITIONAL_CFLAGS	=

CFLAGS	=	-Wall -Wextra -Wshadow -Werror -I../../include $(ADDITIONAL_CFLAGS)


.PHONY:	all clean fclean re

all:	$(NAME)

$(NAME): $(OBJ)
	ar rc $(NAME) $(OBJ)
	cp $(NAME) ../

clean:
	@echo -e "\033[1;3;30m Removing object files\033[0m"
	@rm -f $(OBJ)

fclean: clean
	rm -f ../$(NAME)
	rm -f $(NAME)

re: fclean all
