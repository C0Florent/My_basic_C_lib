/*
** EPITECH PROJECT, 2022
** Get file size
** File description:
** Returns the size (in bytes) of a given file whose filepath is known
*/

#include <sys/stat.h>

long my_get_file_size(char const *filepath)
{
    struct stat s;
    int stat_ret;

    stat_ret = stat(filepath, &s);
    if (stat_ret < 0) {
        return (-84);
    }
    return (s.st_size);
}
