/*
** EPITECH PROJECT, 2022
** Precision tests
** File description:
** Tests for precision parameter of printf
*/

#include <criterion/criterion.h>
#include <criterion/redirect.h>
#include "include_test.h"
#include "my_printf.h"

/////////////////
// BASIC TESTS //
/////////////////

Test(my_printf, ret_test_no_fmt, .init = redirect_all_std) {
    int ret = my_printf("Hello");

    cr_assert_eq(ret, 5);
}

Test(my_printf, ret_basic_c, .init = redirect_all_std) {
    int ret = my_printf("%c", '@');

    cr_assert_eq(ret, 1);
}

Test(my_printf, ret_basic_s, .init = redirect_all_std) {
    int ret = my_printf("%s", "Hello World");

    cr_assert_eq(ret, 11);
}

Test(my_printf, ret_test_basic_i, .init = redirect_all_std) {
    int ret = my_printf("%i", 42);

    cr_assert_eq(ret, 2);
}

Test(my_printf, ret_test_basic_neg_i, .init = redirect_all_std) {
    int ret = my_printf("%i", -84);

    cr_assert_eq(ret, 3);
}

Test(my_printf, ret_test_basic_u, .init = redirect_all_std) {
    int ret = my_printf("%u", 59243);

    cr_assert_eq(ret, 5);
}

Test(my_printf, ret_test_basic_o, .init = redirect_all_std) {
    int ret = my_printf("%o", 01427);

    cr_assert_eq(ret, 4);
}

Test(my_printf, ret_test_basic_x, .init = redirect_all_std) {
    int ret = my_printf("%x", 0x4562);

    cr_assert_eq(ret, 4);
}

Test(my_printf, ret_test_basic_f, .init = redirect_all_std) {
    int ret = my_printf("%f", 123.6);

    cr_assert_eq(ret, 10);
}

Test(my_printf, ret_test_basic_e, .init = redirect_all_std) {
    int ret = my_printf("%e", -145.23);

    cr_assert_eq(ret, 13);
}



//////////////////
// FORMAT TESTS //
//////////////////

Test(my_printf, ret_format_c, .init = redirect_all_std) {
    int ret = my_printf("%4c", 'a');

    cr_assert_eq(ret, 4);
}

Test(my_printf, ret_format_dash_c, .init = redirect_all_std) {
    int ret = my_printf("%-13c", '$');

    cr_assert_eq(ret, 13);
}

Test(my_printf, ret_truncated_s, .init = redirect_all_std) {
    int ret = my_printf("%.3s", "Hello World!!!");

    cr_assert_eq(ret, 3);
}

Test(my_printf, ret_underwidth_s, .init = redirect_all_std) {
    int ret = my_printf("%6s", "Lorem Ipsum");

    cr_assert_eq(ret, 11);
}

Test(my_printf, ret_overwidth_s, .init = redirect_all_std) {
    int ret = my_printf("%7s", "foo");

    cr_assert_eq(ret, 7);
}

Test(my_printf, ret_overwidth_truncated_s, .init = redirect_all_std) {
    int ret = my_printf("%5.3s", "foo bar foo");

    cr_assert_eq(ret, 5);
}

Test(my_printf, ret_overwidth_dash_truncated_s_with_fmt_string,
.init = redirect_all_std) {
    int ret = my_printf("Hello, %-14.7s<-- hidden\n", "this is a great day!");

    cr_assert_eq(ret, 32);
    cr_assert_stdout_eq_str("Hello, this is       <-- hidden\n");
}

Test(my_printf, ret_lowered_prec_f, .init = redirect_all_std) {
    int ret = my_printf("%.3f", 42.69);

    cr_assert_eq(ret, 6);
}

Test(my_printf, ret_roundup_adds_digit_f, .init = redirect_all_std) {
    int ret = my_printf("%.1f", 9.96);

    cr_assert_eq(ret, 4);
}

Test(my_printf, ret_high_prec_neg_f, .init = redirect_all_std) {
    int ret = my_printf("%.13f", -45676.1243456);

    cr_assert_eq(ret, 20);
}

Test(my_printf, ret_space_f, .init = redirect_all_std) {
    int ret = my_printf("% f", 1.0);

    cr_assert_eq(ret, 9);
    cr_assert_stdout_eq_str(" 1.000000");
}

Test(my_printf, ret_space_neg_f, .init = redirect_all_std) {
    int ret = my_printf("% f", 12.0);

    cr_assert_eq(ret, 10);
}

Test(my_printf, ret_ult_f, .init = redirect_all_std) {
    int ret = my_printf("%0+15.*f", 5, 4257.538);

    cr_assert_eq(ret, 15);
    cr_assert_stdout_eq_str("+00004257.53800");
}

Test(my_printf, ret_ult_x, .init = redirect_all_std) {
    int ret = my_printf("%#8.7x", 45);

    cr_assert_eq(ret, 9);
}
