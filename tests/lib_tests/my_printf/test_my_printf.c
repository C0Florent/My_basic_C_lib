/*
** EPITECH PROJECT, 2022
** test_my_printf.c
** File description:
** hello
*/

#include <criterion/criterion.h>
#include <criterion/redirect.h>
#include "include_test.h"
#include "my_printf.h"

Test(my_printf, flag_s, .init = redirect_all_std) {
    my_printf("%s", "hello world");
    cr_assert_stdout_eq_str("hello world");
}

Test(my_printf, flag_i, .init = redirect_all_std) {
    my_printf("%i", 1547896350);
    cr_assert_stdout_eq_str("1547896350");
}

Test(my_printf, flag_d, .init = redirect_all_std) {
    my_printf("%d", 1547896350);
    cr_assert_stdout_eq_str("1547896350");
}

Test(my_printf, flag_o, .init = redirect_all_std) {
    my_printf("%o", 154);
    cr_assert_stdout_eq_str("232");
}

Test(my_printf, flag_x, .init = redirect_all_std) {
    my_printf("%x", 154);
    cr_assert_stdout_eq_str("9a");
}

Test(my_printf, flag_X, .init = redirect_all_std) {
    my_printf("%X", 154);
    cr_assert_stdout_eq_str("9A");
}

Test(my_printf, test_unsigned_int, .init = redirect_all_std) {
    my_printf("%u", 154);
    cr_assert_stdout_eq_str("154");
}

Test(my_printf, flag_e, .init = redirect_all_std) {
    my_printf("%e", -145.23);
    cr_assert_stdout_eq_str("-1.452300e+02");
}

Test(my_printf, flag_E, .init = redirect_all_std) {
    my_printf("%E", -145.23);
    cr_assert_stdout_eq_str("-1.452300E+02");
}

Test(my_printf, flag_f, .init = redirect_all_std) {
    my_printf("%f", -5.3);
    cr_assert_stdout_eq_str("-5.300000");
}

Test(my_printf, flag_c, .init = redirect_all_std) {
    my_printf("%c", 'f');
    cr_assert_stdout_eq_str("f");
}

Test(my_printf, flag_g, .init = redirect_all_std) {
    my_printf("%g", 12.1425587544);
    cr_assert_stdout_eq_str("12.1426");
}

Test(my_printf, other_flag_g, .init = redirect_all_std) {
    my_printf("%g", 12455.1425587544);
    cr_assert_stdout_eq_str("12455.1");
}

Test(my_printf, flag_p, .init = redirect_all_std) {
    char test = 'F';
    char buf[50] = {'\0'};
    sprintf(buf, "%p", &test);
    my_printf("%p", &test);
    cr_assert_stdout_eq_str(buf);
}
/*
Test(my_printf, flag_n_alone, .init = redirect_all_std) {
    int len_so_far;
    int total_len = printf("hello%n world", &len_so_far);
    fflush(stdout);
    cr_assert_stdout_eq_str("hello world");
    cr_assert_eq(total_len, 11);
    cr_assert_eq(len_so_far, 5);
}

Test(my_printf, flag_a, .init = redirect_all_std) {
    printf("%a", 12.25);
    fflush(stdout);
    cr_assert_stdout_eq_str("0x1.88p+3");
}
*/
