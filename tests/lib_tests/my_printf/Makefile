##
## EPITECH PROJECT, 2023
## Test Makefile
## File description:
## Makefile to compile tests for my_printf
##


#########################
# Variables             #
#########################
TESTSRC	=	length_tests.c				\
			precision_tests.c			\
			prec_width_altform_combos.c	\
			redirect_all_std.c			\
			test_get_nbrsize.c			\
			test_mega_put_nbr.c			\
			test_mega_save_nbr.c		\
			test_my_printf.c			\
			test_other_my_printf.c		\
			width_tests.c				\
			return_value_tests.c


LIBPATH		=	../../../lib

MY_LIBS	=	my_printf	\
			newmy		\
			my

## Just write 'NONE' if no libs are needed
OTHER_LIBS	=	criterion



INCLUDEPATH	=	../../../include


TEST_NAME	=	my_printf_test

## Command-line argument
ARG	=



#########################
# Shortcuts             #
#########################

OBJ	=	$(SRC:.c=.o)

LIBNAMES	=	`echo "S$(MY_LIBS)E" | sed "s/ / lib/g" | sed "s/S/lib/g" | \
					sed "s/ /\.a /g" | sed "s/E/\.a/"`

LIBFLAGS	=	`echo " $(MY_LIBS) $(OTHER_LIBS)"	\
					| sed "s/ NONE//" | sed "s/ /-l/" | sed "s/ / -l/g"`

CFLAGS	=	-I$(INCLUDEPATH) -Wall -Wextra -Wshadow --coverage

LDFLAGS	=	-L$(LIBPATH) $(LIBFLAGS)




#########################
# Rules                 #
#########################

all:	lib_ $(TEST_NAME) run_test

lib_:
	make $(LIBNAMES) -C $(LIBPATH)

$(TEST_NAME):
	gcc -o $(TEST_NAME) $(TESTSRC) $(CFLAGS) $(LDFLAGS)

run_test:
	./$(TEST_NAME)

clean:
	rm -f *gcno *gcda $(TEST_NAME)

re:	clean all