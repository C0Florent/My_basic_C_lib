/*
** EPITECH PROJECT, 2023
** Frame reset button
** File description:
** Function to be called once per frame,
** to reset the button's falling edge and rising edge booleans
*/

#include "my_ui.h"

void frame_reset_button(button_t *button)
{
    button->falling_egde = false;
    button->rising_edge = false;
}
