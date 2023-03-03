/*
** EPITECH PROJECT, 2022
** Redirect to right conv
** File description:
** Sub-function for my printf
*/

#include <stddef.h>
#include "my.h"
#include "my_printf_internal.h"

static const put_conv_ptr_t conv_funcs[] = {
    {&my_put_conv_i, 'i'},
    {&my_put_conv_i, 'd'},
    {&my_put_conv_u, 'u'},
    {&my_put_conv_b, 'b'},
    {&my_put_conv_o, 'o'},
    {&my_put_conv_x, 'x'},
    {&my_put_conv_x, 'X'},
    {&my_put_conv_p, 'p'},
    {&my_put_conv_f, 'f'},
    {&my_put_conv_f, 'F'},
    {&my_put_conv_e, 'e'},
    {&my_put_conv_e, 'E'},
    {&my_put_conv_s, 's'},
    {&my_put_conv_c, 'c'},
    {&my_put_conv_percent, '%'},
    {NULL, '\0'}};

int redirect_to_right_conv(conv_det_t *details, va_list *arguments,
    int *count, int fd)
{
    for (size_t i = 0; conv_funcs[i].fptr != NULL; i++) {
        if (conv_funcs[i].conversion == details->conversion) {
            (*count) += conv_funcs[i].fptr(details, arguments, fd);
            return (0);
        }
    }
    return (84);
}
