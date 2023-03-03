/*
** EPITECH PROJECT, 2022
** mem dup 2d array
** File description:
** strdup but for char **
*/

#include <stdlib.h>
#include "my.h"
#include "newmy.h"

static void emergency_free(char **arrdup, unsigned int nb_to_free)
{
    for (unsigned int i = 0; i < nb_to_free; i++) {
        free(arrdup[i]);
    }
    free(arrdup);
}

static bool dup_rows(char * const *arr, char **arrdup)
{
    unsigned int i = 0;

    while (arr[i] != NULL) {
        arrdup[i] = my_strdup(arr[i]);
        if (arrdup[i] == NULL) {
            my_putsterr("str_arr_dup: malloc failed, returning NULL\n");
            emergency_free(arrdup, i + 1);
            return (EXIT_FAILURE);
        }
        i++;
    }
    arrdup[i] = NULL;
    return (EXIT_SUCCESS);
}

char **my_str_array_dup(char * const *arr)
{
    unsigned int size;
    char **ret;
    bool dup_rows_ret;

    if (arr == NULL) {
        return (NULL);
    }
    size = my_str_array_size(arr);
    ret = malloc(sizeof(char *) * (size + 1));
    if (ret == NULL) {
        my_putsterr("str_arr_dup: malloc failed, returning NULL\n");
        return (NULL);
    }
    dup_rows_ret = dup_rows(arr, ret);
    if (dup_rows_ret == EXIT_FAILURE) {
        return (NULL);
    } else {
        return (ret);
    }
}
