/*
** EPITECH PROJECT, 2022
** My str isnum
** File description:
** Returns 1 if the string only contains digits from 0 to 9
*/

#include "my.h"

int my_str_isnum(char const *str)
{
    int i;
    int len = my_strlen(str);

    for (i = 0; i < len; i++) {
        if (str[i] < '0' || str[i] > '9') {
            return (0);
        }
    }
    return (1);
}
