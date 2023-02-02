/*
** EPITECH PROJECT, 2022
** Get str to imp str
** File description:
** Gets a given string into an imp_str structure
*/

#include <stdlib.h>
#include "my.h"
#include "newmy.h"

imp_str_t *get_str_to_imp_str(char *src)
{
    imp_str_t *imp_str;

    if (src == NULL) {
        return (NULL);
    }
    imp_str = malloc(sizeof(imp_str_t));
    imp_str->str = src;
    imp_str->strlen = my_strlen(src);
    return (imp_str);
}
