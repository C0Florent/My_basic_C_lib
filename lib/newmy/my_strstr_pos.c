/*
** EPITECH PROJECT, 2023
** MY
** File description:
** my_strstr_pos
*/

#include <sys/types.h>
#include "my.h"

// Searches for a pattern (needle) in a bigger string and returns the
// index corresponding to the starting point of the found pattern
ssize_t my_strstr_pos(char const *haystack, char const *needle)
{
    int hs_len = my_strlen(haystack);
    int n_len = my_strlen(needle);
    char to_compare[n_len + 1];

    if (n_len > hs_len) {
        return (-1);
    }
    for (ssize_t i = 0; i < hs_len - n_len + 1; i++) {
        my_strncpy(to_compare, &haystack[i], n_len);
        if (my_strcmp(to_compare, needle) == 0) {
            return (i);
        }
    }
    return (-1);
}
