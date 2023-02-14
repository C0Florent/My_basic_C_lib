/*
** EPITECH PROJECT, 2023
** Show_details
** File description:
** Function to print one by one all the fiels of a conv_det_t structure
*/

#include <unistd.h>
#include "my.h"
#include "my_printf_internal.h"
#include "newmy.h"

int show_details(conv_det_t *d)
{
    my_putstr("Detected conversion : ");
    my_putchar(d->conversion);
    my_putstr("\nDetected altform : ");
    mega_put_nbr(d->is_alt_form, 10);
    my_putstr("\nDetected 0 flag : ");
    mega_put_nbr(d->zero_flag, 10);
    my_putstr("\nDetected - flag : ");
    mega_put_nbr(d->dash_flag, 10);
    my_putstr("\nDetected + flag : ");
    mega_put_nbr(d->plus_flag, 10);
    my_putstr("\nDetected ' ' flag : ");
    mega_put_nbr(d->space_flag, 10);
    my_putstr("\nDetected Width : ");
    mega_put_nbr(d->width, 10);
    my_putstr("\nDetected Precision : ");
    mega_put_nbr(d->precision, 10);
    my_putstr("\nDetected length modifier : ");
    write(1, &d->len_modifier[0], 2);
    my_putchar('\n');
    return (0);
}
