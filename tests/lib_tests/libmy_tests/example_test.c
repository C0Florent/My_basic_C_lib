/*
** EPITECH PROJECT, 2023
** Example test
** File description:
** example_test
*/

#include <criterion/criterion.h>
#include <criterion/redirect.h>
#include "include_test.h"
#include "test.h"

Test(test_text, test, .init = redirect_all_std) {
    display_text();
    cr_assert_stdout_eq_str("This file is just there to allow compilation\n");
}
