##
## EPITECH PROJECT, 2022
## My all-purpose project Makefile
## File description:
## Makefile made to compile one single binary that comes from several
## C source files, listed in the SRC variable. All header (.h) files
## are to be located in a single folder, specified in the INCLUDEPATH
## variable. The project may be compiled linked to user-made libraries,
## which should all be located in the LIBPATH folder and whose names
## must be listed in the MY_LIBS variable.
##
## Important note: The LIBPATH folder must contain a Makefile that is
## able to compile all libs individually with a rule named after each lib,
## and should also be able to clean all the libs specified in its ARGS
## variable, when called with the clean or the fclean rule
##

#########################
# Variables             #
#########################

SRC	=	test.c

LIBPATH	=	./lib

MY_LIBS	=	my			\
			my_graphics

## Just write 'OTHER_LIBS	=	NONE' if the
## source files do not need any external libs
OTHER_LIBS	=	csfml-graphics

INCLUDEPATH	=	./include

BIN_NAME	=	example


## Command-line argument
ARG	=

## By default, there are no additional CFLAGS, this
## variable is there to allow other Makefiles calling
## this one to add CFLAGS such as -g or --coverage
ADDITIONAL_CFLAGS	=

#########################
# Shortcuts             #
#########################

OBJ	=	$(SRC:.c=.o)

LIBNAMES	=	`echo "S$(MY_LIBS)E" | sed "s/ / lib/g" | sed "s/S/lib/g" | \
					sed "s/ /\.a /g" | sed "s/E/\.a/"`

LIBFLAGS	=	`echo " $(MY_LIBS) $(OTHER_LIBS)"	\
					| sed "s/ NONE//" | sed "s/ /-l/" | sed "s/ / -l/g"`

CFLAGS	=	-I$(INCLUDEPATH) -Wall -Wextra -Wshadow $(ADDITIONAL_CFLAGS)

LDFLAGS	=	-L$(LIBPATH) $(LIBFLAGS)



#########################
# Rules                 #
#########################

## Global rules
all:	lib_ $(BIN_NAME)

clean: main_clean	lib_clean

fclean:	main_fclean	lib_fclean

re: fclean all



## Lib rules
lib_:
	@echo "make $(LIBNAMES) -C $(LIBPATH)"
	@eval "make $(LIBNAMES) -C $(LIBPATH)"

lib_clean:
	make clean -C $(LIBPATH) ARGS="$(LIBNAMES)"

lib_fclean:
	make fclean -C $(LIBPATH) ARGS="$(LIBNAMES)"

lib_re:
	make re -C $(LIBPATH) ARGS="$(LIBNAMES)"



## Main rules
$(BIN_NAME):	$(OBJ)
	@echo "gcc $(OBJ) $(CFLAGS) $(LDFLAGS) -o $(BIN_NAME)"
	@eval "gcc $(OBJ) $(CFLAGS) $(LDFLAGS) -o $(BIN_NAME)"

main_clean:
	@echo -e "\033[1;3;30m Removing object files\033[0m"
	@rm -f $(OBJ)

main_fclean:	main_clean
	rm -f $(BIN_NAME)

main_re:	main_fclean $(BIN_NAME)



## Tests rules
tests_run:
	@echo "make $(LIBNAMES) -C $(LIBPATH) ADDITIONAL_CFLAGS='--coverage'"
	@eval "make $(LIBNAMES) -C $(LIBPATH) ADDITIONAL_CFLAGS='--coverage'"
	make main_re ADDITIONAL_CFLAGS="--coverage"
	make tests_run -C tests/

tests_clean:	fclean
	find -name "*.gcno" -delete -or -name "*.gcda" -delete
	make tests_clean -C tests/

tests_re: tests_clean tests_run



## Debug:
debug_:
	@echo "make $(LIBNAMES) -C $(LIBPATH) ADDITIONAL_CFLAGS='-g'"
	@eval "make $(LIBNAMES) -C $(LIBPATH) ADDITIONAL_CFLAGS='-g'"
	gcc $(SRC) $(CFLAGS) $(LDFLAGS) -g -o debug_$(BIN_NAME)

debug_rm:
	rm debug_$(BIN_NAME)



## Utilities:

## This auto-header will look for function prototypes in the specified
## source files and list them all in $(INCLUDEPATH)/$(BIN_NAME).h
.h:
	@mkdir -p $(INCLUDEPATH)
	@echo -ne "/*\n** EPITECH PROJECT, 2022\n** $(BIN_NAME).h\n**"\
		"File description:\n** Makefile-generated header file\n*/\n\n" \
		> $(INCLUDEPATH)/$(BIN_NAME).h
	@echo "#ifndef _$(BIN_NAME)_H" >> $(INCLUDEPATH)/$(BIN_NAME).h
	@echo -e "    #define _$(BIN_NAME)_H\n" >> $(INCLUDEPATH)/$(BIN_NAME).h
	@echo -e "    #include \"$(BIN_NAME)_types.h\"\n" >>	\
		$(INCLUDEPATH)/$(BIN_NAME).h
	@cat `echo $(SRC) | sed s/" "/"\n"/g | grep -v "^main.c"` \
		| grep -v "^ " | grep -v "^*" | grep -v "^static"	\
		| grep -v "^#" | grep -v "^{" | grep -v "^}" | grep -v "^$$"	\
		| sed s/"\/\*"/""/ | sed s/")$$"/");"/ >> $(INCLUDEPATH)/$(BIN_NAME).h
	@echo -e "\n#endif /* _$(BIN_NAME)_H */" >> $(INCLUDEPATH)/$(BIN_NAME).h
	@touch $(INCLUDEPATH)/$(BIN_NAME)_types.h

.hrm:
	rm $(INCLUDEPATH)/$(BIN_NAME).h

## Specific rule used to send modifications done in copies of this
## Makefile and lib system to the original copy, which you are seeing
## right now (no one scrolls so far down and reads that on copies)
update:
	cp -ri $(ARG) ../MY/$(ARG)
