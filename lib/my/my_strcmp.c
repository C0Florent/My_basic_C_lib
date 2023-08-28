/*
** EPITECH PROJECT, 2022
** My Str Cmp
** File description:
** checks if two strings given as argument by pointers are equal
*/

#include <stddef.h>
#include "my.h"

int my_strcmp(char const *s1, char const *s2)
{
    int len = my_strlen(s1);

    if (s1 == NULL || s2 == NULL) {
        return (84);
    }
    for (int i = 0; i <= len; i++) {
        if (s1[i] != s2[i]) {
            return (s1[i] - s2[i]);
        }
    }
    return (0);
}
