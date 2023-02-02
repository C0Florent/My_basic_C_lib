/*
** EPITECH PROJECT, 2022
** Alloc new node
** File description:
** Allocs a new node
*/

#include <unistd.h>
#include <stdlib.h>
#include "newmy.h"

// Allocs a new node to a l_list_t, and puts it at the beginning of
// the list, then returns the new node, which is the new first element
// Error: if malloc fails, the function returns the list unchanged
l_list_t *alloc_new_node(l_list_t *list, int new_value)
{
    l_list_t *new_node = malloc(sizeof(l_list_t));

    if (new_node == NULL) {
        write(2, "alloc_new_node: malloc failed, list will be left as is\n",
            55);
        return (list);
    }
    new_node->nb = new_value;
    new_node->next = list;
    return (new_node);
}
