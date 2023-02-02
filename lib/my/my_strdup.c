/*
** EPITECH PROJECT, 2022
** My strdup
** File description:
** Allocates memory to make a copy of a given string
*/

#include <stdlib.h>
#include "my.h"

char *my_strdup(char const *src)
{
    char *str;

    str = malloc(sizeof(char) * (my_strlen(src) + 1));
    my_strcpy(str, src);
    return (str);
}
