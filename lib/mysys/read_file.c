/*
** EPITECH PROJECT, 2023
** cbanana - read_file.c
** File description:
** Function to read a file from disk and load it to RAM,
** in a file_t structure
*/

#include <stddef.h>
#include <fcntl.h>
#include <sys/stat.h>
#include <stdlib.h>
#include "newmy.h"
#include "my_system.h"

static long get_file_size(fd_t opened)
{
    struct stat statbuf;

    if (fstat(opened, &statbuf) == -1) {
        my_putsterr("get_file_size: fstat failed");
        return (-1);
    }
    return (statbuf.st_size);
}

// Will always perform a read on `buffer->filename`
// - On error, no write is performed on `buffer`, and EXIT_FAILURE is returned
// - On success `buffer->filesize` and `buffer->content` are written and
// EXIT_SUCCESS is returned
bool read_file(file_t *buffer)
{
    fd_t readfrom = open(buffer->filename, O_RDONLY);
    long filesize;
    char *content;

    if (readfrom == -1) {
        my_putsterr("read_file: open failed");
        return (EXIT_FAILURE);
    }
    filesize = get_file_size(readfrom);
    if (filesize == -1) {
        return (EXIT_FAILURE);
    }
    content = read_from_fd(readfrom, filesize);
    if (content == NULL) {
        return (EXIT_FAILURE);
    }
    buffer->filesize = filesize;
    buffer->content = content;
    return (EXIT_SUCCESS);
}
