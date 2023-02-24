/*
** EPITECH PROJECT, 2022
** My Printf Header
** File description:
** Header file for the project my_printf
*/

#ifndef MY_PRINTF_H
    #define MY_PRINTF_H

    #include <stdarg.h>

int my_printf(char *format, ...);

int my_vprintf(char *format, va_list *args);


#endif /*MY_PRINTF_H*/
