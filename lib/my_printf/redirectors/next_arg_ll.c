/*
** EPITECH PROJECT, 2022
** Next arg ll
** File description:
** Goes one forward in the va_list for my_printf
*/

#include "my.h"
#include "my_printf.h"
#include <stdarg.h>

long long next_arg_lli(va_list *arguments)
{
    return (va_arg(*arguments, long long));
}

unsigned long long next_arg_llu(va_list *arguments)
{
    return (va_arg(*arguments, unsigned long long));
}

unsigned long long next_arg_void_star(va_list *arguments)
{
    return ((unsigned long long)va_arg(*arguments, void *));
}
