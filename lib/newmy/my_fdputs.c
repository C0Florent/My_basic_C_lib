/*
** EPITECH PROJECT, 2023
** my_fdputs
** File description:
** Prints a character string on any fd
*/

#include <unistd.h>
#include "my.h"

int my_fdputs(char const *str, int fd)
{
    int len = my_strlen(str);
    int write_ret;

    if (len <= 0) {
        return (0);
    }
    write_ret = write(fd, str, len);
    return (write_ret);
}
