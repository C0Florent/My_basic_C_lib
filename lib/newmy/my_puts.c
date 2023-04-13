/*
** EPITECH PROJECT, 2023
** MY
** File description:
** my_puts
*/

#include <unistd.h>
#include "my.h"
#include "newmy.h"

void my_puts(char const *str)
{
    int len = my_strlen(str);

    if (len == -84) {
        my_putsterr("my_puts: NULL\n");
    }
    write(1, str, len);
    my_putchar('\n');
}
