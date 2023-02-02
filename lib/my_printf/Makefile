##
## EPITECH PROJECT, 2022
## Libmy Makefile
## File description:
## Compiles the my_printf lib (replica of printf) into a libmy_printf.a
##

SRC	=	my_printf.c								\
		show_details.c							\
		read_conv/initialise_structure.c		\
		read_conv/read_conv.c					\
		read_conv/read_conv_tools.c				\
		read_conv/clean_structure.c				\
		field_fillers/fill_width_i.c			\
		field_fillers/fill_width_x.c			\
		field_fillers/precision.c				\
		field_fillers/fill_width_uo.c			\
		my_put_conv/conv_x.c					\
		my_put_conv/conv_p.c					\
		my_put_conv/conv_u.c					\
		my_put_conv/conv_b.c					\
		my_put_conv/percent.c					\
		my_put_conv/conv_i.c					\
		my_put_conv/conv_s.c					\
		my_put_conv/conv_o.c					\
		my_put_conv/conv_f.c					\
		my_put_conv/conv_e.c					\
		my_put_conv/conv_c.c					\
		redirectors/next_arg_hh.c				\
		redirectors/len_modifier_redirect.c		\
		redirectors/next_arg_l.c				\
		redirectors/next_arg_default.c			\
		redirectors/next_arg_ll.c				\
		redirectors/redirect_to_right_conv.c	\
		redirectors/next_arg_h.c				\
		number_writers/my_save_float_digits.c	\
		my_get_size/u_conv.c					\
		my_get_size/o_conv.c					\
		my_get_size/my_float_size.c				\
		my_get_size/x_conv.c					\
		my_get_size/get_nbrsize.c				\
		my_get_size/id_conv.c					\
		my_get_size/f_conv.c					\
		my_get_size/e_conv.c

OBJ	=	$(SRC:.c=.o)

NAME	=	libmy_printf.a

CFLAGS	=	-Wall -Wextra -Wshadow -Werror -I../../include -L.. -lmy -g

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
