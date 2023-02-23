/*
** EPITECH PROJECT, 2022
** Ultimate str to str array
** File description:
** Will get a char * to a char **, given either a
** list of suitable or unsuitable characters
** Side note :
** Unoptimised function, it is just made to perform a complex task
** and be as versatile as possible, to be used in as various situations
** as possible, but not optimised for a certain task
*/

#include <stddef.h>
#include <stdbool.h>
#include <stdlib.h>
#include "my.h"
#include "newmy.h"

static bool is_valid_char(char c_to_test, char const *list, bool valid)
{
    if (c_to_test == '\0') {
        return (false);
    }
    if (my_char_is_in_list(c_to_test, list)) {
        return (valid);
    } else {
        return (!valid);
    }
}

static int get_str_count(char const *dup, char const *list, bool valid)
{
    int str_count = 0;

    for (unsigned int i = 0; dup[i] != '\0'; i++) {
        if (is_valid_char(dup[i], list, valid) &&
        !is_valid_char(dup[i + 1], list, valid)) {
            str_count++;
        }
    }
    return (str_count);
}

static void reset_invalid_chars(imp_str_t *imp_dup,
    char const *list, bool valid)
{
    for (unsigned int i = 0; i < imp_dup->strlen; i++) {
        if (!is_valid_char(imp_dup->str[i], list, valid)) {
            imp_dup->str[i] = '\0';
        }
    }
}

static void get_to_str_array(imp_str_t *imp_str, char const *list,
    bool valid, char **array)
{
    int j = 0;

    for (unsigned int i = 0; i < imp_str->strlen; i++) {
        if (is_valid_char(imp_str->str[i], list, valid)) {
            array[j] = &imp_str->str[i];
            i += my_strlen(array[j]);
            j++;
        }
    }
    array[j] = NULL;
}

char **ult_str_to_str_array(char *src, char const *list, bool valid)
{
    char **ret_arr;
    int str_count = 0;
    imp_str_t *impish_str = get_str_to_imp_str(src);

    if (src == NULL) {
        return (NULL);
    }
    str_count = get_str_count(src, list, valid);
    ret_arr = malloc(sizeof(char *) * (str_count + 1));
    if (ret_arr == NULL) {
        free(impish_str);
        return (NULL);
    }
    reset_invalid_chars(impish_str, list, valid);
    get_to_str_array(impish_str, list, valid, ret_arr);
    free(impish_str);
    return (ret_arr);
}
