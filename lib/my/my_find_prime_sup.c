/*
** EPITECH PROJECT, 2022
** my find prime
** File description:
** finds the next prime equal or greater than input int
*/
#include "my.h"

int my_find_prime_sup(int nb)
{
    if (my_is_prime(nb) != 1)
        return (my_find_prime_sup(nb + 1));
    else
        return (nb);
}
