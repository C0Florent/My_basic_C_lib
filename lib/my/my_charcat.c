/*
** EPITECH PROJECT, 2022
** My charcat
** File description:
** concatenates a char to a string
*/

#include "my.h"

int my_charcat(char *dest, char c)
{
    int len = my_strlen(dest);

    dest[len] = c;
    dest[len + 1] = '\0';
    return (0);
}
