/*
** EPITECH PROJECT, 2022
** mem dup 2d array
** File description:
** strdup but for char **
*/

#include <stdlib.h>
#include "my.h"

char **my_str_array_dup(char **arr, unsigned int nb_rows)
{
    char **arrdup = malloc(sizeof(char *) * nb_rows + 1);

    if (arrdup == NULL)
        return (NULL);
    for (unsigned int i = 0; i < nb_rows; i++) {
        arrdup[i] = my_strdup(arr[i]);
        if (arrdup[i] == NULL)
            return (NULL);
    }
    arrdup[nb_rows] = NULL;
    return (arrdup);
}
