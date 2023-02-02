/*
** EPITECH PROJECT, 2022
** My putstErr
** File description:
** Writes a string to standard error
*/

#include <unistd.h>

void my_putsterr(char const *str)
{
    for (int i = 0; str[i] != '\0'; i++) {
        write(2, &str[i], 1);
    }
}
