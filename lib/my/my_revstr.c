/*
** EPITECH PROJECT, 2022
** My RevStr
** File description:
** a shameless copy of my evil str from day 4
*/

#include "my.h"

char *my_revstr(char *str)
{
    int i = 0;
    char c;
    int len = my_strlen(str);

    while (i < len / 2) {
        c = str[i];
        str[i] = str[len - i - 1];
        str[len - i - 1] = c;
        i = i + 1;
    }
    return (str);
}
