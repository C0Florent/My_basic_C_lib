/*
** EPITECH PROJECT, 2022
** Next arg default
** File description:
** Goes one forward in the va_list for my_printf
*/

#include "my.h"
#include <stdarg.h>

long long next_arg_default_i(va_list *arguments)
{
    return (va_arg(*arguments, int));
}

unsigned long long next_arg_default_u(va_list *arguments)
{
    return (va_arg(*arguments, unsigned int));
}
