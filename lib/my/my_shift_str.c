/*
** EPITECH PROJECT, 2022
** My shift_str
** File description:
** If a character string is stored at the beginning of an
** array bigger than its length, it might be useful to shift it
** few chars forwards in order to add anything at the start of it
** or backwards to delete the start of the string
*/

#include "my.h"

// If given a positive shift, this function will move byte by
// byte each character of the string by `shift` bytes forwards, and
// reset the first `shift` characters of the string to NUL bytes
//
// If given a negative shift, it this function will essentially overwrite
// the first `shift` bytes of the string with what is written afterwards
// my_shift_str(str, -n) sort of perfors the same as strcpy(str, str + n),
// but it's the intended use case (doing it w/ strcpy is undefined behaviour)
int my_shift_str(char *str, int shift)
{
    int len = my_strlen(str);

    if (shift > 0) {
        for (int i = len - 1; i >= 0; i--) {
            str[shift + i] = str[i];
        }
        my_str_initialise(str, shift);
    } else {
        shift = -shift;
        for (int i = 0; i <= len; i++) {
            str[i] = str[i + shift];
        }
    }
    return (0);
}
