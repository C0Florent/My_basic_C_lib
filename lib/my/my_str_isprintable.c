/*
** EPITECH PROJECT, 2022
** my str is printable
** File description:
** tests if the str is composed only of printable characters
*/

#include "my.h"

int my_str_isprintable(char const *str)
{
    int i;
    int len = my_strlen(str);

    for (i = 0; i < len; i++) {
        if (str[i] < ' ' || str[i] > '~') {
            return (0);
        }
    }
    return (1);
}
