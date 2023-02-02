/*
** EPITECH PROJECT, 2022
** My get nbrsize
** File description:
** Returns the number of chars needed to write a given number in a given base
*/

int my_get_nbrsize(unsigned long long nb, int base)
{
    int size = 0;

    if (base < 2)
        return (-84);
    for (size = 0; nb != 0; size++)
        nb = nb / base;
    return (size);
}
