/*
** EPITECH PROJECT, 2022
** StrStr
** File description:
** searches the needle (parameter 2) in the haystack(parameter 1)
*/

#include <stddef.h>
#include "my.h"

char *my_strstr(char *str, char const *to_find)
{
    int i = 0;
    int len1 = my_strlen(str);
    int len2 = my_strlen(to_find);
    char to_compare[len2 + 1];

    to_compare[len2] = '\0';
    if (len2 > len1)
        return (NULL);
    for (i = 0; i < len1 - len2 + 1; i++) {
        my_strncpy(to_compare, &str[i], len2);
        if (my_strcmp(to_compare, to_find) == 0) {
            return (&str[i]);
        }
    }
    return (NULL);
}
