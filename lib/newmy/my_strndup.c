/*
** EPITECH PROJECT, 2023
** My strndup
** File description:
** duplicates the (at most) n bytes of src into a newly
** allocated array, which is returned
*/

#include <stddef.h>
#include <stdlib.h>
#include "my.h"

char *my_strndup(char const *src, unsigned int n)
{
    char *ret;

    if (src == NULL) {
        return (NULL);
    }
    ret = malloc(sizeof(char) * (n + 1));
    if (ret == NULL) {
        return (NULL);
    }
    my_strncpy(ret, src, n);
    ret[n] = '\0';
    return (ret);
}
