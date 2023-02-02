/*
** EPITECH PROJECT, 2022
** Str cat
** File description:
** Adds the src string at the end of the dest string (concatenates them)
*/

#include "my.h"

char *my_strcat(char *dest, char const *src)
{
    int lensrc = my_strlen(src);
    int lendest = my_strlen(dest);
    int i;

    for (i = 0; i < lensrc; i++)
        dest[lendest + i] = src[i];
    dest[lendest + i] = '\0';
    return (dest);
}
