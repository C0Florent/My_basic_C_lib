/*
** EPITECH PROJECT, 2022
** my str islower
** File description:
** tests if the string is only composed of lower case letters
*/

#include <stdbool.h>
#include "my.h"

bool my_str_islower(char const *str)
{
    int i = 0;
    int len = my_strlen(str);

    for (i = 0; i < len; i++) {
        if (str[i] < 'a' || str[i] > 'z') {
            return (false);
        }
    }
    return (true);
}
