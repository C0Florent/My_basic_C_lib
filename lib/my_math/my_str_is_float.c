/*
** EPITECH PROJECT, 2022
** Number format
** File description:
** Conatins two functions to verify if given strings
** respect the format of numbers
*/

#include <stdbool.h>
#include "my.h"

bool my_str_is_float(char *fstr)
{
    int len = my_strlen(fstr);
    int dot_count = 0;
    int digit_count = 0;
    int minus = 0;

    if (fstr[0] == '-') {
        minus = 1;
    }
    for (int i = 0; i < len; i++) {
        if (fstr[i] == '.')
            dot_count++;
        if (fstr[i] >= '0' && fstr[i] <= '9')
            digit_count++;
    }
    if (dot_count <= 1 && digit_count == len - dot_count - minus) {
        return (true);
    }
    return (false);
}
