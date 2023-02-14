/*
** EPITECH PROJECT, 2022
** length_tests.c
** File description:
** test the lengths modifier
*/

#include <criterion/criterion.h>
#include <criterion/redirect.h>
#include <stdio.h>
#include "include_test.h"
#include "my_printf.h"

Test(my_printf, test_with_hh, .init = redirect_all_std) {
    int nbr = 120;
    my_printf("%hhd", nbr);
    cr_assert_stdout_eq_str("120");
}

Test(my_printf, test_again_with_hh, .init = redirect_all_std) {
    int nbr = -110;
    my_printf("%hhx", nbr);
    cr_assert_stdout_eq_str("92");
}

Test(my_printf, test_with_h, .init = redirect_all_std) {
    int nbr = 865152;
    my_printf("%hd", nbr);
    cr_assert_stdout_eq_str("13184");
}

Test(my_printf, test_with_l, .init = redirect_all_std) {
    long nbr = 952564555447;
    my_printf("%ld", nbr);
    cr_assert_stdout_eq_str("952564555447");
}

Test(my_printf, downcast_with_l, .init = redirect_all_std) {
    long long nbr = 952564555447457;
    char buf[20] = {'\0'};
    sprintf(buf, "%ld", (long)nbr);
    my_printf("%ld", (long)nbr);
    cr_assert_stdout_eq_str("952564555447457");
}
