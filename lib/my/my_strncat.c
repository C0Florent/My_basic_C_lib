/*
** EPITECH PROJECT, 2022
** Str cat
** File description:
** Adds the src string at the end of the dest string (concatenates them)
*/

#include "my.h"
#include "my_macros.h"

char *my_strncat(char *dest, char const *src, int nb)
{
    int len_src = my_strlen(src);
    int len_dest = my_strlen(dest);
    int i = 0;

    for (i = 0; i < nb && i < len_src; i++) {
        dest[len_dest + i] = src[i];
    }
    dest[MAX(len_dest + i, 0)] = '\0';
    return (dest);
}
