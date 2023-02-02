##
## EPITECH PROJECT, 2022
## MYLIB Makefile
## File description:
## Compiles all my lib into several .a (compiled libraries)
##

ARGS	=	$(MY_NAME) $(NEWMY_NAME) $(PRINTF_NAME) $(LIBSYS_NAME) \
			$(MATRIX_NAME) $(GRAPHX_NAME) $(MATH_NAME) $(VECTOR_NAME)


MY_DIR	=	my
MY_NAME	=	libmy.a

NEWMY_DIR	=	newmy
NEWMY_NAME	=	libnewmy.a

PRINTF_DIR	=	my_printf
PRINTF_NAME	=	libmy_printf.a

LIBSYS_DIR	=	mysys
LIBSYS_NAME	=	libmysys.a

MATRIX_DIR	=	my_matrix
MATRIX_NAME	=	libmy_matrix.a

GRAPHX_DIR	=	my_graphics
GRAPHX_NAME	=	libmy_graphics.a

MATH_DIR	=	my_math
MATH_NAME	=	libmy_math.a

VECTOR_DIR	=	my_vector
VECTOR_NAME	=	libmy_vector.a



all:	$(ARGS)


$(MY_NAME):
	make $(MY_NAME) -C $(MY_DIR)

$(NEWMY_NAME):
	make $(NEWMY_NAME) -C $(NEWMY_DIR)

$(PRINTF_NAME):
	make $(PRINTF_NAME) -C $(PRINTF_DIR)

$(LIBSYS_NAME):
	make $(LIBSYS_NAME) -C $(LIBSYS_DIR)

$(MATRIX_NAME):
	make $(MATRIX_NAME) -C $(MATRIX_DIR)

$(GRAPHX_NAME):
	make $(GRAPHX_NAME) -C $(GRAPHX_DIR)

$(MATH_NAME):
	make $(MATH_NAME) -C $(MATH_DIR)

$(VECTOR_NAME):
	make $(VECTOR_NAME) -C $(VECTOR_DIR)


clean:
	@echo `echo "S$(ARGS)" | sed "s/lib//g" | sed "s/\.a//g" |	\
		sed "s/ / \&\& make clean -C /g" | sed "s/S/make clean -C /"`
	@eval `echo "S$(ARGS)" | sed "s/lib//g" | sed "s/\.a//g" |	\
		sed "s/ / \&\& make clean -C /g" | sed "s/S/make clean -C /"`

fclean:
	@echo `echo "S$(ARGS)" | sed "s/lib//g" | sed "s/\.a//g" |	\
		sed "s/ / \&\& make fclean -C /g" | sed "s/S/make fclean -C /"`
	@eval `echo "S$(ARGS)" | sed "s/lib//g" | sed "s/\.a//g" |	\
		sed "s/ / \&\& make fclean -C /g" | sed "s/S/make fclean -C /"`

re: fclean all
