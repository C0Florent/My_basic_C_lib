/*
** EPITECH PROJECT, 2022
** Test get nbrsize
** File description:
** A test file for the get_nbrsize function
*/

#include <criterion/criterion.h>
#include <criterion/redirect.h>
#include <stdio.h>
#include "include_test.h"
#include "my_printf_internal.h"

Test(get_nbrsize, basic_nbr_base10) {
    cr_assert_eq(my_get_nbrsize(12345678, 10), 8);
}
/*  Negative number are not handled anymore
Test(my_get_nbrsize, neg_base10) {
    cr_assert_eq(my_get_nbrsize(-543, 10), 4);
}
*/
Test(my_get_nbrsize, zero) {
    cr_assert_eq(my_get_nbrsize(0, 10), 0);
}

Test(my_get_nbrsize, neg_zero) {
    cr_assert_eq(my_get_nbrsize(-0, 10), 0);
}

Test(my_get_nbrsize, binary) {
    cr_assert_eq(my_get_nbrsize(342, 2), 9);
}

Test(my_get_nbrsize, huge_nbr_octal) {
    cr_assert_eq(my_get_nbrsize(1237894654531357456, 8), 21);
}

Test(my_get_nbrsize, hexadecimal) {
    cr_assert_eq(my_get_nbrsize(0xa45df486e456c, 16), 13);
}

Test(my_get_nbrsize, invalid_base) {
    cr_assert_eq(my_get_nbrsize(0xa45df486e456c, 1), -84);
}

Test(my_float_int_part_size, invalid_base) {
    cr_assert_eq(my_float_int_part_size(0xa45df486e456c, 1), -84);
}
