/*
** EPITECH PROJECT, 2022
** My show word array
** File description:
** Displays word per word, with each word on a
** separate line, all the words of a word array
*/

#include "my.h"

int my_show_word_array(char * const *tab)
{
    int i;
    int nb_lines = 0;

    while (tab[nb_lines] != 0) {
        nb_lines++;
    }
    for (i = 0; i < nb_lines; i++) {
        my_putstr(tab[i]);
        my_putchar('\n');
    }
    return (0);
}
