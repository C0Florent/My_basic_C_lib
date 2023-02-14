/*
** EPITECH PROJECT, 2022
** Width tests
** File description:
** Tests the width parameter of printf
** Also tests it in combination with flags
*/

#include <criterion/criterion.h>
#include <criterion/redirect.h>
#include <stdio.h>
#include "include_test.h"
#include "my_printf.h"

Test(my_printf, basic_width_string, .init = redirect_all_std) {
    my_printf("%10s", "hello");
    cr_assert_stdout_eq_str("     hello");
}

Test(my_printf, basic_width_decimal, .init = redirect_all_std) {
    my_printf("%7d", 53);
    cr_assert_stdout_eq_str("     53");
}

Test(my_printf, smaller_width, .init = redirect_all_std) {
    my_printf("%2s", "Hello World");
    cr_assert_stdout_eq_str("Hello World");
}

Test(my_printf, dash_flag, .init = redirect_all_std) {
    my_printf("%-5d", 42);
    cr_assert_stdout_eq_str("42   ");
}

Test(my_printf, 2_strings, .init = redirect_all_std) {
    my_printf("%10s%-10s", "Hello", "World");
    cr_assert_stdout_eq_str("     HelloWorld     ");
}

Test(my_printf, zero_flag_with_s, .init = redirect_all_std) {
    my_printf("%07s", "Hi");
    cr_assert_stdout_eq_str("     Hi");
}

Test(my_printf, zero_flag_with_u, .init = redirect_all_std) {
    my_printf("%05u", 42);
    cr_assert_stdout_eq_str("00042");
}

Test(my_printf, zero_flag_with_negative, .init = redirect_all_std) {
    my_printf("%04i", -84);
    cr_assert_stdout_eq_str("-084");
}

Test(my_printf, zero_plus_dash_flag, .init = redirect_all_std) {
    my_printf("%0-5i", 51);
    cr_assert_stdout_eq_str("51   ");
}

Test(my_printf, dash_plus_zero_flag, .init = redirect_all_std) {
    my_printf("%-016d", -12);
    cr_assert_stdout_eq_str("-12             ");
}

Test(my_printf, dash_flag_smaller_width, .init = redirect_all_std) {
    my_printf("%-1s", "Hello World");
    cr_assert_stdout_eq_str("Hello World");
}

Test(my_printf, dash_flag_hex, .init = redirect_all_std) {
    my_printf("%-9x", 0xB41C);
    cr_assert_stdout_eq_str("b41c     ");
}

Test(my_printf, dash_flag_oct, .init = redirect_all_std) {
    my_printf("%-4o", 10);
    cr_assert_stdout_eq_str("12  ");
}

Test(my_printf, zero_flag_hex, .init = redirect_all_std) {
    my_printf("%09X", 0xE31A);
    cr_assert_stdout_eq_str("00000E31A");
}

Test(my_printf, zero_flag_oct, .init = redirect_all_std) {
    my_printf("%04o", 15);
    cr_assert_stdout_eq_str("0017");
}

Test(my_printf, zero_flag_f_conv, .init = redirect_all_std) {
    my_printf("%012f", 75.42);
    cr_assert_stdout_eq_str("00075.420000");
}
