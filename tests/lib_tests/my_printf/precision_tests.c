/*
** EPITECH PROJECT, 2022
** Precision tests
** File description:
** Tests for precision parameter of printf
*/

#include <criterion/criterion.h>
#include <criterion/redirect.h>
#include <stdio.h>
#include "include_test.h"
#include "my_printf.h"

Test(my_printf, basic_precision_u_conv, .init = redirect_all_std) {
    my_printf("%.5u", 42);
    cr_assert_stdout_eq_str("00042");
}

Test(my_printf, precision_lesser_than_nb_length, .init = redirect_all_std) {
    my_printf("%.1i", 543);
    cr_assert_stdout_eq_str("543");
}

Test(my_printf, basic_precision_x_conv, .init = redirect_all_std) {
    my_printf("%.7x", 0xa42);
    cr_assert_stdout_eq_str("0000a42");
}

Test(my_printf, precision_lesser_than_nb_length_X_conv,
.init = redirect_all_std) {
    my_printf("%.1X", 0x543);
    cr_assert_stdout_eq_str("543");
}

Test(my_printf, basic_precision_o_conv, .init = redirect_all_std) {
    my_printf("%.6o", 12);
    cr_assert_stdout_eq_str("000014");
}

Test(my_printf, precision_lesser_than_nb_length_o_conv,
.init = redirect_all_std) {
    my_printf("%.1o", 16);
    cr_assert_stdout_eq_str("20");
}

Test(my_printf, explicit_prec0_with_value_0, .init = redirect_all_std) {
    my_printf("%.0da", 0);
    cr_assert_stdout_eq_str("a");
}

Test(my_printf, dot_alone_is_prec0, .init = redirect_all_std) {
    my_printf("%.ia", 0);
    cr_assert_stdout_eq_str("a");
}

Test(my_printf, prec_with_float, .init = redirect_all_std) {
    my_printf("%.4f", 42.42);
    cr_assert_stdout_eq_str("42.4200");
}

Test(my_printf, prec_with_float_smaller_no_roundup,
.init = redirect_all_std) {
    my_printf("%.1f", 42.42424242);
    cr_assert_stdout_eq_str("42.4");
}

Test(my_printf, prec_with_float_roundup, .init = redirect_all_std) {
    my_printf("%.2f", 42.686);
    cr_assert_stdout_eq_str("42.69");
}

Test(my_printf, prec_float_5roundup, .init = redirect_all_std) {
    my_printf("%.4f", 342.25425);
    cr_assert_stdout_eq_str("342.2543");
}

Test(my_printf, prec0_with_float, .init = redirect_all_std) {
    my_printf("%.0f", 51.42424242);
    cr_assert_stdout_eq_str("51");
}
Test(my_printf, implicit_prec0_float, .init = redirect_all_std) {
    my_printf("%.F", 4.165465435);
    cr_assert_stdout_eq_str("4");
}

Test(my_printf, float_prec0_alt_form, .init = redirect_all_std) {
    my_printf("%#.0f", 69.3213);
    cr_assert_stdout_eq_str("69.");
}

Test(my_printf, float_implicit_prec0_alt_form_roundup,
.init = redirect_all_std) {
    my_printf("%#.f", 12.65156);
    cr_assert_stdout_eq_str("13.");
}

Test(my_printf, conv_e_prec_no_roundup, .init = redirect_all_std) {
    my_printf("%.7e", 42153.21423);
    cr_assert_stdout_eq_str("4.2153214e+04");
}

Test(my_printf, conv_e_prec_do_roundup, .init = redirect_all_std) {
    my_printf("%.4E", 421537.71455);
    cr_assert_stdout_eq_str("4.2154E+05");
}

Test(my_printf, conv_e_prec0_no_roundup, .init = redirect_all_std) {
    my_printf("%.0e", 42153.21423);
    cr_assert_stdout_eq_str("4e+04");
}

Test(my_printf, conv_e_prec0_do_roundup, .init = redirect_all_std) {
    my_printf("%.0e", 753.21423);
    cr_assert_stdout_eq_str("8e+02");
}

Test(my_printf, conv_e_implicit_prec0_no_roundup, .init = redirect_all_std) {
    my_printf("%.e", 42153.21423);
    cr_assert_stdout_eq_str("4e+04");
}

Test(my_printf, conv_e_implicit_prec0_do_roundup, .init = redirect_all_std) {
    my_printf("%.e", 4715342652.21423);
    cr_assert_stdout_eq_str("5e+09");
}

Test(my_printf, conv_e_alt_form_implicit_prec0_do_roundup,
.init = redirect_all_std) {
    my_printf("%#.E", 75153.21423);
    cr_assert_stdout_eq_str("8.E+04");
}
