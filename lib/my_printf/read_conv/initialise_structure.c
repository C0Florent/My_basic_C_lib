/*
** EPITECH PROJECT, 2023
** Initialise structure
** File description:
** function for my_printf that takes care of properly initialising
** (and reinitialising) the structure used to store the conversion details
*/

#include <stdbool.h>
#include "my.h"
#include "my_printf_internal.h"

void initialise_structure(conv_det_t *conv_struct)
{
    conv_struct->is_alt_form = false;
    conv_struct->zero_flag = false;
    conv_struct->dash_flag = false;
    conv_struct->space_flag = false;
    conv_struct->plus_flag = false;
    conv_struct->width = 0;
    conv_struct->precision = -1;
    my_str_initialise(conv_struct->len_modifier, 2);
}
