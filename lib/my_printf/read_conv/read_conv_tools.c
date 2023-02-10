/*
** EPITECH PROJECT, 2023
** Read conv tools
** File description:
** Functions to read step by step the conversion string
*/

#include "my.h"
#include "my_printf_internal.h"

int put_char_space(int nb)
{
    for (int i = 0; i < nb; i++) {
        my_putchar(' ');
    }
    return (0);
}

void read_flag(conv_det_t *details, char flag_to_add)
{
    switch (flag_to_add) {
    case ' ':
        details->space_flag = true;
        break;
    case '+':
        details->plus_flag = true;
        break;
    case '0':
        details->zero_flag = true;
        break;
    case '-':
        details->dash_flag = true;
        break;
    case '#':
        details->is_alt_form = true;
        break;
    }
}

void read_width(int *width, unsigned int *i, char const *conv, va_list *args)
{
    if (conv[0] == '*') {
        *width = va_arg(*args, int);
        *i += 1;
        return;
    }
    *width = my_getnbr(conv);
    *i += my_get_nbrsize(*width, 10);
}

void read_precision(int *precision, unsigned int *i,
char const *conv, va_list *args)
{
    read_width(precision, i, conv + 1, args);
    (*i)++;
}

void read_len_modifier(char *len_modifier, char const *conv)
{
    unsigned int i = 0;

    while (i < 2 && my_char_is_in_list(conv[i], "hl")) {
        len_modifier[i] = conv[i];
        i++;
    }
}
