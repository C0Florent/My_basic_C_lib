/*
** EPITECH PROJECT, 2022
** My Str CmNp
** File description:
** checks if the n first chars of two strings given
** as argument by pointers are equal,
*/

#include "my.h"

int my_strncmp(char const *s1, char const *s2, int n)
{
    int i = 0;
    int len = my_strlen(s1);

    for (i = 0; i < len + 1 && i < n; i++) {
        if (s1[i] != s2[i])
            return (s1[i] - s2[i]);
    }
    return (0);
}
