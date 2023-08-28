/*
** EPITECH PROJECT, 2022
** String copy
** File description:
** Copies a string into another
*/

#include "my.h"

char *my_strcpy(char *dest, char const *src)
{
    int i = 0;

    for (i = 0; i < my_strlen(src) + 1; i++) {
        dest[i] = src[i];
    }
    return (dest);
}
