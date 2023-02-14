/*
** EPITECH PROJECT, 2022
** Test Mega put number
** File description:
** Contains several tests for the mega_put_nbr function
*/

#include <criterion/criterion.h>
#include <criterion/redirect.h>
#include <stdio.h>
#include "include_test.h"
#include "my_printf.h"
#include "my_macros.h"
#include "newmy.h"

Test(mega_put_nbr, put_decimal_int_nbr, .init = redirect_all_std) {
    mega_put_nbr(16534321, 10);
    cr_assert_stdout_eq_str("16534321");
}

Test(mega_put_nbr, put_Hex_long_long, .init = redirect_all_std) {
    mega_put_nbr(0x46a2cf5b54bdfc, 16);
    cr_assert_stdout_eq_str("46a2cf5b54bdfc");
}

Test(mega_put_nbr, zero, .init = redirect_all_std) {
    mega_put_nbr(0, 10);
    cr_assert_stdout_eq_str("0");
}

Test(mega_put_nbr, return_value, .init = redirect_all_std) {
    int len = mega_put_nbr(0x46a2cf5b54bdfc, 16);
    int len2 = mega_put_nbr(-12345641313665212, 7);
    cr_assert_eq(len, 14);
    cr_assert_eq(len2, 21);
}

Test(mega_put_nbr, put_mega_mega_neg_nbr, .init = redirect_all_std) {
    mega_put_nbr(-9223372036854775807 - 1, 10);
    cr_assert_stdout_eq_str("-9223372036854775808");
}

Test(macro_abs, simple_tests) {
    int nb1 = ABS(-3);
    int nb2 = ABS(0);
    int nb3 = ABS(2);
    cr_assert_eq(nb1, 3);
    cr_assert_eq(nb2, 0);
    cr_assert_eq(nb3, 2);
}
