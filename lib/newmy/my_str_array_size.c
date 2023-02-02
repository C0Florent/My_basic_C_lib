/*
** EPITECH PROJECT, 2022
** my word array size
** File description:
** returns the size (string count) of a char **
*/

#include <sys/types.h>
#include <stdlib.h>

unsigned int my_str_array_size(char * const *arr)
{
    int i = 0;

    for (; arr[i] != NULL; i++);
    return (i);
}
