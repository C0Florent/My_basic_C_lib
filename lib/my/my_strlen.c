/*
** EPITECH PROJECT, 2022
** string length
** File description:
** returns the length of a string given as parameter
*/

#include <stddef.h>
#include "my.h"

int my_strlen(char const *str)
{
    int	i = 0;

    if (str == NULL) {
        return (-84);
    }
    while (str[i] != '\0') {
        i = i + 1;
    }
    return (i);
}
