/*
** EPITECH PROJECT, 2022
** Str cat
** File description:
** Adds the src string at the end of the dest string (concatenates them)
*/

#include "my.h"

char *my_strncat(char *dest, char const *src, int nb)
{
    int len2 = my_strlen(dest);
    int i = 0;

    for (i = 0; i < nb && src[i] != '\0'; i++)
        dest[len2 + i] = src[i];
    dest[len2 + i] = '\0';
    return (dest);
}
