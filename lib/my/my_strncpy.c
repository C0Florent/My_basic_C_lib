/*
** EPITECH PROJECT, 2022
** String N Copy
** File description:
** Copies the n first characters of a string into another
*/

#include "my.h"

char *my_strncpy(char *dest, char const *src, int n)
{
    int i = 0;
    int len = my_strlen(src);

    if (n < 0)
        return (dest);
    for (i = 0; i < n; i++) {
        if (i >= len) {
            dest[i] = '\0';
        } else {
            dest[i] = src[i];
        }
    }
    dest[n] = '\0';
    return (dest);
}
