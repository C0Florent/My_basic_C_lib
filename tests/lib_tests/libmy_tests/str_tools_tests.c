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
#include <string.h>
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

Test(my_strncmp, basic_success)
{
    cr_assert(my_strncmp("isson", "isson", 5) == 0);
}

Test(my_strncmp, shorter_n_success)
{
    cr_assert(my_strncmp("azer@@@", "azertyui", 4) == 0);
}

Test(my_strncmp, equal_strs_longer_n)
{
    cr_assert(my_strncmp("Lorem", "Lorem", 18) == 0);
}

Test(my_strncmp, basic_fail)
{
    cr_assert(my_strncmp("ABC", "DEF", 5) != 0);
}

Test(my_strncmp, same_start_n_longer)
{
    cr_assert(my_strncmp("hello everyone", "hello world", 7) != 0);
}

Test(my_strstr, find_stringQRS_in_the_alphabet)
{
    char needle[] = "QRS";
    char haystack[] = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
    char *my_find = my_strstr(haystack, needle);
    char *strs_find = strstr(haystack, needle);
    cr_assert_str_eq(my_find, strs_find);
}

Test(my_strstr, find_the_haystack_in_the_needle)
{
    char needle[] = "QRS";
    char haystack[] = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
    cr_assert_null(strstr(needle, haystack));
    cr_assert_null(my_strstr(needle, haystack));
}

Test(my_strstr, search_for_a_needle_when_theres_none)
{
    char needle[] = "A";
    char haystack[] = "15623465451";
    cr_assert_null(strstr(haystack, needle));
    cr_assert_null(my_strstr(haystack, needle));
}

Test(my_strstr, hello)
{
    char needle[] = "lo";
    char haystack[] = "hello";
    cr_assert_str_eq(my_strstr(haystack, needle), "lo");
    cr_assert_str_eq(my_strstr("hello", "he"), "hello");
}

Test(my_strdup, basic)
{
    char original[10] = {'a', 'b', 'c'};
    char *dup = my_strdup(original);

    cr_assert(strcmp(original, dup) == 0);
    cr_assert_neq(original, dup);
    free(dup);
}

Test(my_strdup, empty)
{
    char *one_byte = my_strdup("");

    cr_assert_eq(*one_byte, '\0');
    free(one_byte);
}

Test(my_str_isnum, basic_success)
{
    cr_assert(my_str_isnum("145246413998516"));
}

Test(my_str_isnum, basic_fail)
{
    cr_assert(!my_str_isnum("abfdsl"));
    cr_assert(!my_str_isnum("/,+"));
}

Test(my_str_isnum, one_letter_in_the_middle)
{
    cr_assert(!my_str_isnum("145246413B98516"));
}

Test(my_str_isnum, edge_cases_fail)
{
    cr_assert(!my_str_isnum("@45246413998516"));
    cr_assert(!my_str_isnum("45246413998516@"));
}

Test(my_str_isalpha, basic_success)
{
    cr_assert(my_str_isalpha("jgksdgjsdgj"));
    cr_assert(my_str_isalpha("DFSJFKSJFKGFNDSJG"));
    cr_assert(my_str_isalpha("jgkDSGHJfdshfjhfkDSFJSD"));
}

Test(my_str_isalpha, basic_fail)
{
    cr_assert(!my_str_isalpha("[564&'-|`{}"));
    cr_assert(!my_str_isalpha("fdshfkjhsfk|fdsnfkls"));
    cr_assert(!my_str_isalpha("14fdfq"));
}

Test(my_str_isalpha, empty)
{
    cr_assert(my_str_isalpha(""));
}

Test(my_str_islower, basic_success)
{
    cr_assert(my_str_islower("jgksdgjsdgj"));
}

Test(my_str_islower, fail_cases)
{
    cr_assert(!my_str_islower("123456"));
    cr_assert(!my_str_islower("{[^#{[]}]}"));
    cr_assert(!my_str_islower("fsffdsaasdq5fdsfsdf"));
    cr_assert(!my_str_islower("fdsf#fdsfsf[s]ggjhkih"));
    cr_assert(!my_str_islower("AAAAAAAA"));
}

Test(my_str_isupper, basic_success)
{
    cr_assert(my_str_isupper("FDHSJGNSKJLGLK"));
}

Test(my_str_isupper, fail_cases)
{
    cr_assert(!my_str_isupper("123456"));
    cr_assert(!my_str_isupper("{[^#{[]}]}"));
    cr_assert(!my_str_isupper("FDSJFDS5JKJFDIOSJF"));
    cr_assert(!my_str_isupper("VDSVD#FDSFSF[FDNSFK]FD"));
    cr_assert(!my_str_isupper("aaaaa"));
}

Test(my_str_isprintable, normal_test)
{
    cr_assert(my_str_isprintable("djfhdsk34~&)") == true);
    cr_assert(my_str_isprintable("fŸ") == false);
    cr_assert(my_str_isprintable("") == true);
    cr_assert(my_str_isprintable("ŝf6") == false);
}

Test(my_str_isprintable, non_printable_bytes)
{
    cr_assert(my_str_isprintable("\04") == false);
    cr_assert(my_str_isprintable("\01\03\07") == false);
    cr_assert(my_str_isprintable("\xF1\xE2") == false);
    cr_assert(my_str_isprintable("\xFF\03") == false);
}

Test(my_str_isprintable, DEL)
{
    cr_assert(my_str_isprintable("\x7F") == false);
}

Test(my_revstr, basic_test)
{
    char *test_string = strdup("Hi there!");

    my_revstr(test_string);
    cr_assert_str_eq(test_string, "!ereht iH");
}

Test(my_show_word_array, basic_test, .init = redirect_all_std)
{
    char *test_arr[] = {"Hi", "This", "is", "a", "multiline", "sentence", NULL};

    my_show_word_array(test_arr);
    cr_assert_stdout_eq_str("Hi\nThis\nis\na\nmultiline\nsentence\n");
}

Test(my_shift_str, big_positive_shift)
{
    char test_buffer[7] = "Hi";
    char expected_result[7] = {'\0', '\0', '\0', 'H', 'i', '\0', '\0'};

    my_shift_str(test_buffer, 3);

    cr_assert_arr_eq(test_buffer, expected_result, 7);
}

Test(my_shift_str, small_positive_shift)
{
    char test_buffer[8] = "Hello";
    char expected_result[8] = {'\0', 'H', 'e', 'l', 'l', 'o', '\0', '\0'};

    my_shift_str(test_buffer, 1);

    cr_assert_arr_eq(test_buffer, expected_result, 7);
}

Test(my_shift_str, negative_shift)
{
    char test_buffer[7] = "--AAA";
    char expected_result[7] = {'A', 'A', 'A', '\0', '\0', '\0', '\0'};

    my_shift_str(test_buffer, -2);

    cr_assert_arr_eq(test_buffer, expected_result, 7);
}

Test(my_shift_str, negative_shift_in_heap)
{
    char *test_buffer = strdup("--AAA");
    char expected_result[] = "AAA";

    my_shift_str(test_buffer, -2);

    cr_assert_arr_eq(test_buffer, expected_result, 4);
    free(test_buffer);
}
