##
## EPITECH PROJECT, 2022
## Libmy Makefile
## File description:
## Compiles the libnewmy (more advanced functions) into a libnewmy.a
##

SRC	=	multi_free.c				\
		my_str_array_size.c			\
		my_str_array_cat.c			\
		my_sort_str_array.c			\
		my_str_array_copy.c			\
		my_str_array_dup.c			\
		my_putsterr.c				\
		my_fdputs.c					\
		my_strstr_pos.c				\
		my_strndup.c				\
		my_str_is_made_of.c			\
		my_get_nbrsize.c			\
		show_dump.c					\
		my_eq.c						\
		count_char_occurencies.c	\
		get_str_to_imp_str.c		\
		ult_str_to_str_array.c		\
		count_arr_occurencies.c		\
		eq_2d_coords.c				\
		mega_put_nbr.c				\
		mega_save_nbr.c				\
		linked_list/alloc_new_node.c\
		linked_list/free_l_list_t.c	\
		my_getline.c

OBJ	=	$(SRC:.c=.o)

NAME	=	libnewmy.a

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
