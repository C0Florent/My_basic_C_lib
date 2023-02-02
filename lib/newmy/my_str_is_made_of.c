/*
** EPITECH PROJECT, 2022
** My_str_is_made_of
** File description:
** my_str_is_made_of
*/

#include <stdbool.h>
#include "my.h"

bool my_str_is_made_of(char const *str, char const *accepted_chars)
{
    for (int i = 0; str[i] != '\0'; i++) {
        if (my_char_is_in_list(str[i], accepted_chars) == 0)
            return (false);
    }
    return (true);
}
