/*
** EPITECH PROJECT, 2022
** Mutli-free
** File description:
** Variadic function that can produce several calls to free, in order
** to avoid having to call free several times in other programs
*/

//SysCalls: free

#include <sys/types.h>
#include <stdarg.h>
#include <stdlib.h>

void multi_free(size_t arg_count, ...)
{
    va_list pointers;

    if (arg_count == 0)
        return;
    va_start(pointers, arg_count);
    for (size_t i = 0; i < arg_count; i++) {
        free(va_arg(pointers, void *));
    }
    va_end(pointers);
}
