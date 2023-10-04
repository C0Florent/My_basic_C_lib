/*
** EPITECH PROJECT, 2022
** Count arr occurencies
** File description:
** Counts the occurencies of a single character in a
** character double array (char **)
*/

#include <stddef.h>
#include "newmy.h"

int count_arr_occurencies(char c, char *const *arr)
{
    int occurencies = 0;

    if (arr == NULL) {
        return (-84);
    }
    for (int i = 0; arr[i] != NULL; i++) {
        occurencies += count_occurencies(arr[i], c);
    }
    return (occurencies);
}
