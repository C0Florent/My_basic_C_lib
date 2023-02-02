/*
** EPITECH PROJECT, 2022
** Free l_list_t
** File description:
** Frees all the elements of a linked list
*/

#include <stddef.h>
#include <stdlib.h>
#include "newmy.h"

// Frees a l_list_t, element by element
void free_l_list_t(l_list_t *list)
{
    l_list_t *previous_ptr;
    l_list_t *ptr_buffer = list;

    while (ptr_buffer != NULL) {
        previous_ptr = ptr_buffer;
        ptr_buffer = ptr_buffer->next;
        free(previous_ptr);
    }
}
