##
## EPITECH PROJECT, 2023
## Tests Makefile
## File description:
## Main Makefile for running unit tests
##


#########################
# Variables             #
#########################

TEST_DIRS	=	lib_tests/my_printf/	\
				lib_tests/libmy_tests/	\
				example_tests/




#########################
# Shortcuts             #
#########################

TESTS_RUN_CMD	=	`echo "S$(TEST_DIRS)" |	\
		sed "s/ / ; make tests_run -C /g" | \
		sed "s/S/make tests_run -C /"`

TESTS_CLEAN_CMD	=	`echo "S$(TEST_DIRS)" |	\
		sed "s/ / ; make tests_clean -C /g" | \
		sed "s/S/make tests_clean -C /"`



#########################
# Rules                 #
#########################

tests_clean:
	@echo $(TESTS_CLEAN_CMD)
	@eval $(TESTS_CLEAN_CMD)

tests_run:
	@echo $(TESTS_RUN_CMD)
	@eval $(TESTS_RUN_CMD)