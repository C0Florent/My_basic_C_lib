/*
** EPITECH PROJECT, 2022
** My char is in list
** File description:
** Returns true if the given char is somewhere
** in the given string, otherwise returns false
*/

#include <stdbool.h>

bool my_char_is_in_list(char c, char *str)
{
    for (int i = 0; str[i] != '\0'; i++) {
        if (str[i] == c)
            return (true);
    }
    return (false);
}
