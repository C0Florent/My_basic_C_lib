/*
** EPITECH PROJECT, 2022
** isprime
** File description:
** tells if the input is prime or not
*/

#include <stdbool.h>
#include "my.h"

int sqrt_roundup(int nb)
{
    int i = 0;
    int square_i = 0;

    if (nb <= 0) {
        return (0);
    }
    while (square_i < nb) {
        square_i = i * i;
        if (square_i >= nb) {
            return (i);
        }
        i = i + 1;
    }
    return (0);
}

bool my_is_prime(int nb)
{
    int sqrt_nb = sqrt_roundup(nb);
    int i = 2;

    if (nb < 2) {
        return (false);
    }
    if (nb == 2) {
        return (true);
    }
    while (i <= sqrt_nb) {
        if (nb % i == 0) {
            return (false);
        }
        i = i + 1;
    }
    return (true);
}
