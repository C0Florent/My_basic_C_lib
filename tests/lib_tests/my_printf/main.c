/*
** EPITECH PROJECT, 2022
** main.c
** File description:
** main function
*/

#include <stdio.h>

int incr_nbr(int *n)
{
    printf("%d\n", (*n));
    (*n)++;
    printf("%d\n", (*n));
    return (0);
}

int main (void)
{
    int nbr = 2;
    printf("% 0da\n", nbr);
    printf("% 1da\n", nbr);
    printf("% 2da\n", nbr);
    printf("% 3da\n", nbr);
    printf("% 4da\n", nbr);
    printf("% 5da\n", nbr);
    printf("% da\n", nbr);
    printf("@\n%- 0da\n", nbr);
    printf("%- 1da\n", nbr);
    printf("%- 2da\n", nbr);
    printf("%- 3da\n", nbr);
    printf("%- 4da\n", nbr);
    printf("%- 5da\n", nbr);
    printf("%- da\n", nbr);
    return 0;
}
