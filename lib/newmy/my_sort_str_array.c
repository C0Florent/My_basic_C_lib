/*
** EPITECH PROJECT, 2022
** My sort word array
** File description:
** Sorts all the entries (words or more generally strings)
** of a word array (in fact any char **)
*/

#include <sys/types.h>
#include <stdlib.h>
#include "newmy.h"
#include "my.h"

static void swap_strings(char **str_ptr1, char **str_ptr2)
{
    char *ptr_buffer = *str_ptr1;

    *str_ptr1 = *str_ptr2;
    *str_ptr2 = ptr_buffer;
}

/* scans all the pairs of neighbouring ints and swaps them
**  if required, by calling the swap_strings function   */
static void swap_once(char **arr, size_t size)
{
    for (size_t i = 0; i < size - 1; i++) {
        if (my_strcmp(arr[i], arr[i + 1]) > 0)
            swap_strings(&arr[i], &arr[i + 1]);
    }
}

/*will loop _size_ times, calling the swap_once function*/
int my_sort_str_array(char **arr)
{
    size_t size = my_str_array_size(arr);

    for (size_t i = 0; i < size; i++) {
        swap_once(arr, size);
    }
    return (0);
}
