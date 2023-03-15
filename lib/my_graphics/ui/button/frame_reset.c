/*
** EPITECH PROJECT, 2023
** Frame reset button
** File description:
** Function to be called once per frame,
** to reset the button's falling edge and rising edge booleans
*/

#include <stddef.h>
#include "my_ui.h"

void frame_reset_button(button_t *button)
{
    button->falling_egde = false;
    button->rising_edge = false;
}

void frame_reset_menu(dropdown_menu_t *menu)
{
    frame_reset_button(menu->menu_button);
    if (menu->is_folded == true) {
        return;
    }
    for (menu_opt_t *i = menu->option_ll; i != NULL; i = i->next) {
        frame_reset_button(i->option);
    }
}
