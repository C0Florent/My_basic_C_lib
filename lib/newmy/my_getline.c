/*
** EPITECH PROJECT, 2023
** My getline
** File description:
** Reproduction of the non-standard C library function: getline
*/

#include <stdbool.h>
#include <unistd.h>
#include <stdlib.h>
#include <sys/types.h>
#include "my.h"
#include "newmy.h"

static bool are_args_valid(char **lineptr, size_t *bufsiz_ptr, int fd)
{
    if (lineptr == NULL || bufsiz_ptr == NULL || fd < 0) {
        return (false);
    }
    if (*lineptr == NULL) {
        *bufsiz_ptr = 0;
    } else {
        my_str_initialise(*lineptr, *bufsiz_ptr);
    }
    return (true);
}

// Returns false if allocation failed
static bool realloc_buffer_if_necessary(char **lineptr,
    size_t *bufsiz_ptr, ssize_t bytes_read)
{
    if (bytes_read >= (long)(*bufsiz_ptr - 2)) {
        *bufsiz_ptr = (((*bufsiz_ptr / 256) + 1) * 256);
        free(*lineptr);
        *lineptr = malloc(sizeof(char) * (*bufsiz_ptr));
        if (*lineptr == NULL) {
            *lineptr = NULL;
            *bufsiz_ptr = 0;
            return (false);
        }
        my_str_initialise(*lineptr, *bufsiz_ptr);
    }
    return (true);
}

// Reads one line of given in file descriptor `fd` and stores it
// in `*lineptr`, reallocating it if need be, and accordingly setting
// `*bufsiz_ptr` to match the size of allocated buffer
//
// Return code: number of bytes read (positive or zero)
// Error codes (negative return codes):
// -1:  a call to `read()` returned -1 at any point
// -84: invalid arguments
// -42: allocation error occurred during execution
ssize_t my_fdgetline(char **lineptr, size_t *bufsiz_ptr, int fd)
{
    char buf = '\0';
    ssize_t read_ret = 1;
    ssize_t bytes_read = 0;

    if (are_args_valid(lineptr, bufsiz_ptr, fd) == false)
        return (-84);
    read_ret = read(fd, &buf, 1);
    while (read_ret > 0) {
        if (!realloc_buffer_if_necessary(lineptr, bufsiz_ptr, bytes_read)) {
            return (-42);
        }
        (*lineptr)[bytes_read++] = buf;
        if (buf == '\n')
            break;
        read_ret = read(fd, &buf, 1);
    }
    if (*lineptr != NULL) {
        (*lineptr)[bytes_read] = '\0';
    }
    return ((read_ret < 0) ? read_ret : bytes_read);
}
