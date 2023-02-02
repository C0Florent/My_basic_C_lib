/*
** EPITECH PROJECT, 2022
** My string capitaliser
** File description:
** Makes the first letter of every word be an upper case
** and any other letter be a lower case
*/

#include "my.h"

char my_charupcase(char *c)
{
    if (*c >= 'a' && *c <= 'z')
        *c = (*c - 'a' + 'A');
    return (*c);
}

char my_charlowcase(char *c)
{
    if (*c >= 'A' && *c <= 'Z')
        *c = *c - 'A' + 'a';
    return (*c);
}

int my_char_isnum(char c)
{
    if (c < '0' || c > '9')
        return (0);
    return (1);
}

char *my_strcapitalize(char *str)
{
    int len = my_strlen(str);

    my_charupcase(&str[0]);
    for (int i = 1; i < len; i++) {
        if (my_char_isnum(str[i - 1]) == 1 || my_char_isalpha(str[i - 1]) == 1)
            my_charlowcase(&str[i]);
        else
            my_charupcase(&str[i]);
    }
    return (str);
}
