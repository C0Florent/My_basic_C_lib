/*
** EPITECH PROJECT, 2022
** My concat params
** File description:
** concats a char ** in a char* where words are separated by '\n's
*/

#include <stdlib.h>
#include "my.h"

static char *alloc_ret(int argc, char **argv)
{
    char *ret;
    int lengths_sum = 0;

    for (int i = 0; i < argc; i++) {
        lengths_sum += my_strlen(argv[i]);
    }
    ret = malloc(sizeof(char) * (lengths_sum + 1));
    ret[0] = '\0';
    return (ret);
}

char *concat_params(int argc, char **argv)
{
    int i;
    char *retstr = alloc_ret(argc, argv);

    for (i = 0; i < argc - 1; i++) {
        my_strcat(retstr, argv[i]);
        my_strcat(retstr, "\n");
    }
    my_strcat(retstr, argv[i]);
    return (retstr);
}
