/*
** EPITECH PROJECT, 2022
** Next arg hh
** File description:
** Goes one forward in the va_list for my_printf
*/

#include "my.h"
#include <stdarg.h>

long long next_arg_li(va_list *arguments)
{
    return (va_arg(*arguments, long));
}

unsigned long long next_arg_lu(va_list *arguments)
{
    return (va_arg(*arguments, unsigned long));
}
