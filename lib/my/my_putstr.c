/*
** EPITECH PROJECT, 2022
** my putstr
** File description:
** displays one by one the chars of a string, without using the prinft function
*/

#include "my.h"

int my_putstr(char const *str)
{
    int i = 0;
    while (str[i] != '\0') {
        my_putchar(str[i]);
        i = i + 1;
    }
    return (i);
}
