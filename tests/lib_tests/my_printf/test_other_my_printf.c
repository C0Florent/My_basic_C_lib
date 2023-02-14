/*
** EPITECH PROJECT, 2022
** test_other_my_printf.c
** File description:
** an other tests
*/

#include <criterion/criterion.h>
#include <criterion/redirect.h>
#include "include_test.h"
#include "my_printf.h"

Test(my_printf, flag_with_o, .init = redirect_all_std) {
    my_printf("%#o", 7845);
    cr_assert_stdout_eq_str("017245");
}

Test(my_printf, flag_with_f, .init = redirect_all_std) {
    my_printf("%#.0f", 784.0);
    cr_assert_stdout_eq_str("784.");
}

Test(my_printf, flag_with_x, .init = redirect_all_std) {
    my_printf("%#x", 784);
    cr_assert_stdout_eq_str("0x310");
}

Test(my_printf, flag_with_e, .init = redirect_all_std) {
    my_printf("%#.0e", 784.44578);
    cr_assert_stdout_eq_str("8.e+02");
}

Test(my_printf, flag_with_g, .init = redirect_all_std) {
    my_printf("%#g", 8000.00000);
    cr_assert_stdout_eq_str("8000.00");
}

Test(my_printf, flag_g_with_the_plus, .init = redirect_all_std) {
    my_printf("%+g", 8000.00000);
    cr_assert_stdout_eq_str("+8000");
}

Test(my_printf, flag_g_with_the_minus, .init = redirect_all_std) {
    my_printf("%-8g", 8000.00000);
    cr_assert_stdout_eq_str("8000    ");
}

Test(my_printf, flag_g_with_the_space, .init = redirect_all_std) {
    my_printf("% g", 8000.00000);
    cr_assert_stdout_eq_str(" 8000");
}
