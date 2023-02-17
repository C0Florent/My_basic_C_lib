/*
** EPITECH PROJECT, 2023
** Str tools tests
** File description:
** Unit tests for string-manipulation-related functions
*/

#include <criterion/criterion.h>
#include <criterion/redirect.h>
#include <unistd.h>
#include <stdio.h>
#include "include_test.h"
#include "my.h"

Test(my_putchar, basic_test, .init = redirect_all_std) {
    my_putchar('d');
    cr_assert_stdout_eq_str("d");
}

Test(my_putchar, nonprintable, .init = redirect_all_std) {
    my_putchar('\xFF');
    cr_assert_stdout_eq_str("\xFF");
}

Test(my_putstr, basic_test, .init = redirect_all_std) {
    my_putstr("Hello world");
    cr_assert_stdout_eq_str("Hello world");
}

// cr_assert_std*_eq_str("") will always fail, and there is no known workaround
Test(my_putstr, no_crash_on_empty_string, .timeout = 1.0,
.disabled = true) {
    int feof_ret;

    my_putstr("");
    feof_ret = feof_unlocked(stdout);
    dprintf(2, "%i\n", feof_ret);
    perror("read");
    cr_assert_neq(feof_ret, 0);
}

Test(my_putstr, multi_line_string, .init = redirect_all_std) {
    my_putstr("123"
        "456");
    cr_assert_stdout_eq_str("123456");
}

Test(macro_abs, negative) {
    int nb = ABS(-3);

    cr_assert_eq(nb, 3);
}

Test(macro_abs, positive) {
    int nb = ABS(7);

    cr_assert_eq(nb, 7);
}

Test(my_strlen, basic_test) {
    int len = my_strlen("Hello world");

    cr_assert_eq(len, 11);
}

Test(my_strlen, empty_string) {
    int len = my_strlen("");

    cr_assert_eq(len, 0);
}

Test(my_strlen, null) {
    int len = my_strlen(NULL);

    cr_assert_eq(len, -84);
}

Test(my_strcpy, basic) {
    char buffer[10] = {'\0'};

    my_strcpy(buffer, "Hello !");
    cr_assert_str_eq(buffer, "Hello !");
}

Test(my_strcpy, overwrite_nonempty_string) {
    char buffer[10] = {'a', 'b', 'c'};

    my_strcpy(buffer, "Hi there!");
    cr_assert_str_eq(buffer, "Hi there!");
}

Test(my_strcpy, reset_nonempty_string) {
    char buffer[10] = {'Z', 'z', 'Z'};

    my_strcpy(buffer, "");
    cr_assert_str_eq(buffer, "");
}

Test(my_strncpy, basic) {
    char buffer[10] = {'\0'};

    my_strncpy(buffer, "abc", 3);
    cr_assert_str_eq(buffer, "abc");
}

Test(my_strncpy, n_cuts_copy) {
    char buffer[10] = {'\0'};

    my_strncpy(buffer, "abcdefgh", 2);
    cr_assert_str_eq(buffer, "ab");
}

Test(my_strncpy, n_larger_than_str_size) {
    char buffer[10] = {'\0'};

    my_strncpy(buffer, "abcd", 8);
    cr_assert_str_eq(buffer, "abcd");
}

Test(my_strncpy, n_equals_zero) {
    char buffer[10] = {'H', 'i'};

    my_strncpy(buffer, "abcd", 0);
    cr_assert_str_eq(buffer, "");
}

Test(my_strncpy, neg_n) {
    char buffer[10] = {'H', 'i'};

    my_strncpy(buffer, "FEUR", -42);
    cr_assert_str_eq(buffer, "Hi");
}

Test(my_strcat, basic) {
    char buffer[10] = {'H', 'i'};

    my_strcat(buffer, " there");
    cr_assert_str_eq(buffer, "Hi there");
}

Test(my_strcat, cat_empty_leaves_unchanged) {
    char buffer[10] = {'H', 'i'};

    my_strcat(buffer, "");
    cr_assert_str_eq(buffer, "Hi");
}

Test(my_strcat, cat_on_empty_buffer) {
    char buffer[10] = {'\0'};

    my_strcat(buffer, "foobar");
    cr_assert_str_eq(buffer, "foobar");
}

Test(my_strncat, basic) {
    char buffer[10] = {'H', 'i'};

    my_strncat(buffer, " you!", 5);
    cr_assert_str_eq(buffer, "Hi you!");
}

Test(my_strncat, n_shorter_than_size) {
    char buffer[10] = {'f', 'o', 'o'};

    my_strncat(buffer, "barfoo", 3);
    cr_assert_str_eq(buffer, "foobar");
}

Test(my_strncat, n_greater_than_size) {
    char buffer[10] = {'1', '2', '3', '4'};

    my_strncat(buffer, "56", 15);
    cr_assert_str_eq(buffer, "123456");
}

Test(my_strncat, cat_null_string) {
    char buffer[10] = {'1', '2', '3', '4'};

    my_strncat(buffer, NULL, 15);
    cr_assert_str_eq(buffer, "1234");
}

Test(my_strcmp, basic_success)
{
    cr_assert(my_strcmp("abc", "abc") == 0);
}

Test(my_strcmp, basic_fail)
{
    cr_assert(my_strcmp("abc", "zqsd") != 0);
}


Test(my_strcmp, same_start_s1_shorter)
{
    cr_assert(my_strcmp("foob", "foobar") != 0);
}


Test(my_strcmp, same_start_s2_shorter)
{
    cr_assert(my_strcmp("foobar", "foob") != 0);
}

Test(my_strcmp, two_empty)
{
    cr_assert(my_strcmp("", "") == 0);
}

Test(my_strcmp, s1_or_s2_null)
{
    cr_assert(my_strcmp("foo", NULL) != 0);
    cr_assert(my_strcmp(NULL, "bar") != 0);
}
