/*
** EPITECH PROJECT, 2022
** My str to word array
** File description:
** Converts a given string of words to array of strings
** containing individual words
*/

#include <stdlib.h>
#include "my.h"

static int my_char_alphnm(char *c)
{
    if (*c >= '0' && *c <= '9') {
            return (1);
    }
    if ((*c >= 'a' && *c <= 'z') || (*c >= 'A' && *c <= 'Z')) {
        return (1);
    }
    *c = '\0';
    return (0);
}

char **my_str_to_word_array(char const *str)
{
    char **retstr;
    int len = my_strlen(str);
    int nb_words = 0;
    int y = 0;
    char *str2 = my_strdup(str);

    for (int i = 0; i < len; i++) {
        if (my_char_alphnm(&str2[i]) == 1 && my_char_alphnm(&str2[i + 1]) == 0)
            nb_words++;
    }
    retstr = malloc(sizeof(char *) * (nb_words + 1));
    for (int i = 0; i < len; i++) {
        if (my_char_alphnm(&str2[i]) == 1) {
            retstr[y] = &str2[i];
            i = i + my_strlen(&str2[i]);
            y++;
        }
    }
    retstr[y] = 0;
    return (retstr);
}
