/*
** EPITECH PROJECT, 2022
** Up Case
** File description:
** Puts every letter contained in the the string given as
** input (by a pointer) in lower case
*/

#include "my.h"

char *my_strlowcase(char *str)
{
    int i;
    int len = my_strlen(str);

    for (i = 0; i < len; i++) {
        if (str[i] >= 'A' && str[i] <= 'Z') {
            str[i] = str[i] + 'a' - 'A';
        }
    }
    return (str);
}
