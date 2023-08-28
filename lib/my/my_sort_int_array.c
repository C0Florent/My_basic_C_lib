/*
** EPITECH PROJECT, 2022
** an attempt of my_sort_int_array
** File description:
** is meant to sort an array
** of ints in ascending order
*/

#include "my.h"

/*scans all the pairs of neighbouring ints and swaps them*/
void swap_once(int *arr, int size)
{
    for (int i = 0; i < size - 1; i++) {
        if (arr[i] > arr[i + 1]) {
            my_swap(&arr[i], &arr[i + 1]);
        }
    }
}

/*will loop _size_ times, calling the swap_once function*/
void my_sort_int_array(int *arr, int size)
{
    for (int i = 0; i < size; i++) {
        swap_once(arr, size);
    }
}
