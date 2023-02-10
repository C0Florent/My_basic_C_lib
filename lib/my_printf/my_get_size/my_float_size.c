/*
** EPITECH PROJECT, 2022
** My float size
** File description:
** Returns the size of a float number (ceiling function of log of any base)
*/

#include "my.h"

int my_float_int_part_size(double nb, int base)
{
    int size = 0;

    nb = ABS(nb);
    if (base < 2)
        return (-84);
    if (nb >= 1) {
        for (size = 0; nb >= 1; size++) {
            nb = nb / base;
        }
    } else {
        for (size = 1; nb <= 1 && size > -839; size--) {
            nb = nb * base;
        }
    }
    return (size);
}
