/*
** EPITECH PROJECT, 2022
** My concat params
** File description:
** concats a char ** in a char* where words are separated by '\n's
*/

#include <stdlib.h>
#include "my.h"

char *concat_params(int argc, char **argv)
{
    int i;
    char *retstr;
    int lenmax;

    for (i = 0; i < argc; i++) {
        if (my_strlen(argv[i]) > lenmax)
            lenmax = my_strlen(argv[i]);
    }
    retstr = malloc(sizeof(char) * argc * (lenmax + 1));
    for (i = 0; i < argc - 1; i++) {
        my_strcat(retstr, argv[i]);
        my_strcat(retstr, "\n");
    }
    my_strcat(retstr, argv[i]);
    return (retstr);
}
