##
## EPITECH PROJECT, 2023
## Test Makefile
## File description:
## Makefile to compile tests for my_printf
##


#########################
# Variables             #
#########################
TESTSRC	=	redirect_all_std.c		\
			str_tools_tests.c


MY_LIBS	=	my

LIBPATH	=	../../../lib/

## Just write 'NONE' if no libs are needed
OTHER_LIBS	=	criterion



INCLUDEPATH	=	../../../include


TEST_NAME	=	libmy_tests

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

all:	tests_run

tests_run: $(TEST_NAME) run_test

$(TEST_NAME):
	@echo "gcc -o $(TEST_NAME) $(TESTSRC) $(TESTED_SRC) $(CFLAGS) $(LDFLAGS)"
	@eval "gcc -o $(TEST_NAME) $(TESTSRC) $(TESTED_SRC) $(CFLAGS) $(LDFLAGS)"

run_test:
	./$(TEST_NAME)

tests_clean:
	rm -f *gcno *gcda $(TEST_NAME)

re:	tests_clean all