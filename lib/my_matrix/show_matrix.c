/*
** EPITECH PROJECT, 2022
** Show matrix
** File description:
** A function that provides a nice display
** tool for the matrix_t structure
*/

#include <unistd.h>
#include <stdio.h>
#include "my_matrix.h"

static void basic_display(double nb, int prec)
{
    printf("%.*f", prec, nb);
    fflush(stdout);
}

static void show_one_row(
    matrix_t *m,
    int i,
    int precision,
    void (*display_func)(double, int)
)
{
    display_func(m->coords[i][0], precision);
    for (unsigned int j = 1; j < m->width; j++) {
        write(1, "\t", 1);
        display_func(m->coords[i][j], precision);
    }
}

void show_matrix(
    matrix_t *m,
    int precision,
    unsigned char display_mode,
    void (*display_func)(double, int)
)
{
    if (display_mode == 0 || display_func == NULL) {
        display_func = &basic_display;
    }
    for (unsigned int i = 0; i < m->height; i++) {
        show_one_row(m, i, precision, display_func);
        printf("\n");
    }
}
