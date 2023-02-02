/*
** EPITECH PROJECT, 2022
** Next arg hh
** File description:
** Goes one forward in the va_list for my_printf
*/

#include "my.h"
#include "my_printf.h"
#include <stdarg.h>

long long next_arg_hhi(va_list *arguments)
{
    return ((char)va_arg(*arguments, int));
}

unsigned long long next_arg_hhu(va_list *arguments)
{
    return ((unsigned char)va_arg(*arguments, unsigned int));
}
