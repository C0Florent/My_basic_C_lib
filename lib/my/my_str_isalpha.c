/*
** EPITECH PROJECT, 2022
** My str isalpha
** File description:
** Returns 1 if the string only contains letters
*/

#include "my.h"

int my_char_isalpha(char c)
{
    if ((c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z')) {
        return (1);
    }
    return (0);
}

int my_str_isalpha(char const *str)
{
    int i;
    int len = my_strlen(str);

    for (i = 0; i < len; i++) {
        if (my_char_isalpha(str[i]) == 0) {
            return (0);
        }
    }
    return (1);
}
