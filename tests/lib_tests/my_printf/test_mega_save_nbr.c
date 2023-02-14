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
#include "my_printf_internal.h"
#include "newmy.h"

Test(mega_save_nbr, save_decimal_int_nbr, .init = redirect_all_std) {
    char *buf = malloc(sizeof(char) * my_get_nbrsize(16534321, 10) + 1);
    mega_save_nbr(buf, 16534327, 10);
    cr_assert_str_eq(buf, "16534327");
    free(buf);
}

Test(mega_save_nbr, save_Hex_long_long, .init = redirect_all_std) {
    char *buf = malloc(sizeof(char)
    * my_get_nbrsize(0x46a2cf5b54bdfc, 16) + 1);
    mega_save_nbr(buf, 0x46a2cf5b54bdfc, 16);
    cr_assert_str_eq(buf, "46a2cf5b54bdfc");
    free(buf);
}

Test(mega_save_nbr, save_zero, .init = redirect_all_std) {
    char *buf = malloc(sizeof(char) * my_get_nbrsize(0, 10) + 1);
    mega_save_nbr(buf, 0, 10);
    cr_assert_str_eq(buf, "");
    free(buf);
}

Test(mega_save_nbr, save_return_value, .init = redirect_all_std) {
    char *buf1 = malloc(sizeof(char)
    * my_get_nbrsize(0x46a2cf5b54bdfc, 16) + 1);
    int len1 = mega_save_nbr(buf1, 0x46a2cf5b54bdfc, 16);
    cr_assert_eq(len1, 14);
    free(buf1);
}
