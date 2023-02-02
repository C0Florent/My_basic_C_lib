/*
** EPITECH PROJECT, 2022
** clean_structure.c
** File description:
** clean the structure
*/

#include "my_printf.h"
#include "my.h"

void clean_struct(conv_det_t *structure)
{
    char integer_number[] = {'d', 'i', 'o', 'u', 'x', 'X', '\0'};
    char float_number[] = {'e', 'E','f', 'F', 'g', 'G', 'a', 'A', '\0'};

    if (structure->zero_flag == 1 && structure->dash_flag == 1) {
        structure->zero_flag = 0;
    }
    if (structure->plus_flag == 1 && structure->space_flag == 1) {
        structure->space_flag = 0;
    }
    if (my_char_is_in_list(structure->conversion, &integer_number[0]) == 1) {
        if (structure->precision != -1 && structure->zero_flag == 1)
            structure->zero_flag = 0;
        if (structure->precision == -1)
            structure->precision = 1;
    }
    if (my_char_is_in_list(structure->conversion, &float_number[0])
        && structure->precision == -1) {
        structure->precision = 6;
    }
}
