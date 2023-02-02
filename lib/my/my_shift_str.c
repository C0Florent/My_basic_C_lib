/*
** EPITECH PROJECT, 2022
** My shift_str
** File description:
** If a character string is stored at the beginning of an
** array bigger than its length, it might be useful to shift it
** few chars forwards in order to add anything at the start of it
*/

#include "my.h"

int my_shift_str(char *str, int shift)
{
    int len = my_strlen(str);

    for (int i = len - 1; i >= 0; i--)
        str[shift + i] = str[i];
    my_str_initialise(str, shift);
    return (0);
}
