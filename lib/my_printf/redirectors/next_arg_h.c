/*
** EPITECH PROJECT, 2022
** Next arg h
** File description:
** Goes one forward in the va_list for my_printf
*/

#include "my.h"
#include <stdarg.h>

long long next_arg_hi(va_list *arguments)
{
    return ((short)va_arg(*arguments, int));
}

unsigned long long next_arg_hu(va_list *arguments)
{
    return ((unsigned short)va_arg(*arguments, unsigned int));
}
