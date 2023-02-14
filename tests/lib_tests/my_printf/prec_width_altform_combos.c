/*
** EPITECH PROJECT, 2022
** Combo tests
** File description:
** Tests for combinations of various printf parameters
*/

#include <criterion/criterion.h>
#include <criterion/redirect.h>
#include <stdio.h>
#include "include_test.h"
#include "my_printf.h"

Test(my_printf, prec_and_width, .init = redirect_all_std) {
    my_printf("%10.5u", 42);
    cr_assert_stdout_eq_str("     00042");
}

Test(my_printf, prec_width_neg_nbr, .init = redirect_all_std) {
    my_printf("%7.4i", -8);
    cr_assert_stdout_eq_str("  -0008");
}

Test(my_printf, zero_flag_with_neg_nbr, .init = redirect_all_std) {
    my_printf("%05d", -3);
    cr_assert_stdout_eq_str("-0003");
}

Test(my_printf, prec_with_neg_nbr, .init = redirect_all_std) {
    my_printf("%.5d", -3);
    cr_assert_stdout_eq_str("-00003");
}

Test(my_printf, octal_altform, .init = redirect_all_std) {
    my_printf("%#o", 13);
    cr_assert_stdout_eq_str("015");
}

Test(my_printf, oct_alt_width, .init = redirect_all_std) {
    my_printf("%#5o", 13);
    cr_assert_stdout_eq_str("  015");
}

Test(my_printf, oct_altform_zero_flag, .init = redirect_all_std) {
    my_printf("%#06o", 7);
    cr_assert_stdout_eq_str("000007");
}

Test(my_printf, no_altform_is_same_as_above, .init = redirect_all_std) {
    my_printf("%06o", 7);
    cr_assert_stdout_eq_str("000007");
}

Test(my_printf, oct_altform_prec, .init = redirect_all_std) {
    my_printf("%#.3o", 5);
    cr_assert_stdout_eq_str("005");
}

Test(my_printf, no_altform_same_as_above, .init = redirect_all_std) {
    my_printf("%.3o", 5);
    cr_assert_stdout_eq_str("005");
}


Test(my_printf, hexadecimal_altform, .init = redirect_all_std) {
    my_printf("%#x", 0x4b);
    cr_assert_stdout_eq_str("0x4b");
}

Test(my_printf, hex_alt_width, .init = redirect_all_std) {
    my_printf("%#5X", 0xc);
    cr_assert_stdout_eq_str("  0XC");
}

Test(my_printf, hex_altform_zero_flag, .init = redirect_all_std) {
    my_printf("%#08x", 0x56);
    cr_assert_stdout_eq_str("0x000056");
}

Test(my_printf, prec_instead_of_zero_flag_is_similar,
.init = redirect_all_std) {
    my_printf("%#.8x", 0x56);
    cr_assert_stdout_eq_str("0x00000056");
}

Test(my_printf, no_altform_differs_from_above, .init = redirect_all_std) {
    my_printf("%08x", 0x56);
    cr_assert_stdout_eq_str("00000056");
}


Test(my_printf, plus_priority_over_space, .init = redirect_all_std) {
    my_printf("% +d", 45);
    cr_assert_stdout_eq_str("+45");
}

Test(my_printf, space_unpriority_over_plus, .init = redirect_all_std) {
    my_printf("%+ d", 45);
    cr_assert_stdout_eq_str("+45");
}

Test(my_printf, multiple_plus_and_spaces, .init = redirect_all_std) {
    my_printf("%  +++ ++ +  + + d", 45);
    cr_assert_stdout_eq_str("+45");
}

Test(my_printf, space_with_higher_prec_and_dash_field,
.init = redirect_all_std) {
    my_printf("% -8.5d", 45);
    cr_assert_stdout_eq_str(" 00045  ");
}

Test(my_printf, higher_prec_with_zero_flag_and_space,
.init = redirect_all_std) {
    my_printf("% 07.4i", 42);
    cr_assert_stdout_eq_str("   0042");
}


Test(my_printf, space_with_zero_flag, .init = redirect_all_std) {
    my_printf("% 05i", 42);
    cr_assert_stdout_eq_str(" 0042");
}

Test(my_printf, higher_prec_with_space_flag, .init = redirect_all_std) {
    my_printf("% .4i", 42);
    cr_assert_stdout_eq_str(" 0042");
}

Test(my_printf, prec_and_width_e, .init = redirect_all_std) {
    my_printf("%15.5e", 42.512);
    cr_assert_stdout_eq_str("    4.25120e+01");
}

Test(my_printf, E_0_with_neg_input, .init = redirect_all_std) {
    my_printf("%012.2E", -0.00000342);
    cr_assert_stdout_eq_str("-0003.42E-06");
}

Test(my_printf, E_exponent_11_roundup, .init = redirect_all_std) {
    my_printf("%-15.8E", 124589730515.12346);
    cr_assert_stdout_eq_str("1.24589731E+11 ");
}

Test(my_printf, e_plus_flag, .init = redirect_all_std) {
    my_printf("%+e", 3.0);
    cr_assert_stdout_eq_str("+3.000000e+00");
}

Test(my_printf, e_alt_form_do_roundup_space_and_dash_flag,
.init = redirect_all_std) {
    my_printf("%#- 10.e", 162.0);
    cr_assert_stdout_eq_str(" 2.e+02   ");
}
