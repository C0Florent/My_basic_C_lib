/*
** EPITECH PROJECT, 2022
** My word array copy
** File description:
** Copies the strings of a word array into a new one
** Only copies pointers, without any new allocation
*/

#include <stddef.h>
#include "newmy.h"

char **my_str_array_copy(char **src, char **dest)
{
    unsigned int src_size = my_str_array_size(src);

    for (size_t i = 0; i <= src_size; i++) {
        dest[i] = src[i];
    }
    return (dest);
}
