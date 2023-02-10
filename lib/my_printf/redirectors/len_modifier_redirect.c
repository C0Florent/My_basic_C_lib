/*
** EPITECH PROJECT, 2022
** Length modifier redirector
** File description:
** Redirects to the correct function to va_arg the right type
*/

#include <stddef.h>
#include <stdarg.h>
#include "my.h"
#include "my_printf_internal.h"

static const signed_len_redir_t redir_funcs_signed[] = {
    {&next_arg_hhi, "hh"},
    {&next_arg_hi, "h"},
    {&next_arg_li, "l"},
    {&next_arg_lli, "ll"},
    {&next_arg_lli, "q"},
    {NULL, "\0"}};

static const unsigned_len_redir_t redir_funcs_unsigned[] = {
    {&next_arg_hhu, "hh"},
    {&next_arg_hu, "h"},
    {&next_arg_lu, "l"},
    {&next_arg_llu, "ll"},
    {&next_arg_llu, "q"},
    {&next_arg_void_star, "v*"},
    {NULL, "\0"}};

long long int redirect_signed(conv_det_t *details, va_list *list)
{
    for (int i = 0; redir_funcs_signed[i].fptr != NULL; i++) {
        if (my_strncmp(details->len_modifier,
            redir_funcs_signed[i].len_modifier, 2) == 0) {
            return (redir_funcs_signed[i].fptr(list));
        }
    }
    return (next_arg_default_i(list));
}

long long unsigned int redirect_unsigned(conv_det_t *details, va_list *list)
{
    for (int i = 0; redir_funcs_unsigned[i].fptr != NULL; i++) {
        if (my_strncmp(details->len_modifier,
            redir_funcs_unsigned[i].len_modifier, 2) == 0) {
            return (redir_funcs_unsigned[i].fptr(list));
        }
    }
    return (next_arg_default_u(list));
}
