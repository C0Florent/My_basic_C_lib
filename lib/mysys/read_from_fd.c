/*
** EPITECH PROJECT, 2023
** cbanana - read_from_fd
** File description:
** Function to read a file from its file descriptor,
** and returns the read content
*/

#include <my_system.h>
#include <stdlib.h>
#include <unistd.h>
#include "newmy.h"

// Function to read from a file which already has a open file descriptor
char *read_from_fd(fd_t to_read, long filesize)
{
    char *ret = malloc(sizeof(char) * (filesize + 1));

    if (ret == NULL) {
        my_putsterr("read_from_fd: malloc failed");
        return (NULL);
    }
    if (read(to_read, ret, filesize) != filesize) {
        my_putsterr("read_from_fd: could not properly read file");
        return (NULL);
    }
    ret[filesize] = '\0';
    return (ret);
}
