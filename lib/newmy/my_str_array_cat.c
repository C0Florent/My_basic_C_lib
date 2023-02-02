/*
** EPITECH PROJECT, 2022
** My word arrya cat
** File description:
** concatenates a new string at the end of an existing word array
*/

#include "newmy.h"
#include "my.h"
#include <sys/types.h>
#include <stddef.h>

void my_str_array_cat(char const *src, char **arr)
{
    size_t size = my_str_array_size(arr);

    arr[size] = my_strdup(src);
    arr[size + 1] = NULL;
}
