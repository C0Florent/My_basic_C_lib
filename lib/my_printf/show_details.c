#include <unistd.h>
#include "my.h"
#include "my_printf_internal.h"
#include "newmy.h"

#define my_put_nbr(nbr) mega_put_nbr((nbr), 10)

int show_details(conv_det_t *d)
{
    my_putstr("Detected conversion : ");
    my_putchar(d->conversion);
    my_putstr("\nDetected altform : ");
    my_put_nbr(d->is_alt_form);
    my_putstr("\nDetected 0 flag : ");
    my_put_nbr(d->zero_flag);
    my_putstr("\nDetected - flag : ");
    my_put_nbr(d->dash_flag);
    my_putstr("\nDetected + flag : ");
    my_put_nbr(d->plus_flag);
    my_putstr("\nDetected ' ' flag : ");
    my_put_nbr(d->space_flag);
    my_putstr("\nDetected Width : ");
    my_put_nbr(d->width);
    my_putstr("\nDetected Precision : ");
    my_put_nbr(d->precision);
    my_putstr("\nDetected length modifier : ");
    write(1, &d->len_modifier[0], 2);
    my_putchar('\n');
    return (0);
}
