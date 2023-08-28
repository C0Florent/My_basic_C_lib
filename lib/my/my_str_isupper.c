/*
** EPITECH PROJECT, 2022
** my str isupper
** File description:
** tests if the string is only composed of upper case letters
*/

#include "my.h"

int my_str_isupper(char const *str)
{
    int i = 0;
    int len = my_strlen(str);

    for (i = 0; i < len; i++) {
        if (str[i] < 'A' || str[i] > 'Z') {
            return (0);
        }
    }
    return (1);
}
