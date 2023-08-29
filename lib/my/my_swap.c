/*
** EPITECH PROJECT, 2022
** my swap
** File description:
** swaps the contents of two given variables whose
** adresses are given as parameters
*/

#include "my.h"

void my_swap(int *a, int *b)
{
    int temp = *a;

    *a = *b;
    *b = temp;
}
