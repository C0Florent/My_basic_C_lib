/*
** EPITECH PROJECT, 2022
** square root
** File description:
** computes (a bit less) wildly the square root
** of perfect squares
*/

#include "my.h"

int my_compute_square_root(int nb)
{
    int square_i = 0;

    if (nb <= 0)
        return (0);
    for (int i = 0; square_i <= nb; i++) {
        if (square_i == nb)
            return (i);
        square_i += 2 * i + 1;
    }
    return (0);
}
