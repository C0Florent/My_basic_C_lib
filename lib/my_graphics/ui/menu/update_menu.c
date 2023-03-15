/*
** EPITECH PROJECT, 2023
** update menu
** File description:
** Function to be called once per frame, to properly update the menu's state
*/

#include <stddef.h>
#include "my_ui.h"

static bool is_menu_folded(dropdown_menu_t const *menu)
{
    bool ret = false;

    if (menu->menu_button->state == HOVER
    || menu->menu_button->state == PRESSED
    || menu->menu_button->on == true) {
        return (true);
    }
    for (menu_opt_t *i = menu->option_ll; i != NULL; i = i->next) {
        if (i->option->state == HOVER || i->option->state == PRESSED) {
            ret = true;
        }
    }
    return (ret);
}

static void update_buttons(dropdown_menu_t *menu, sfEvent const *event)
{
    update_button_state(menu->menu_button, event);
    if (menu->is_folded == false) {
        for (menu_opt_t *i = menu->option_ll; i != NULL; i = i->next) {
            update_button_state(i->option, event);
        }
    }
}

void update_menu(dropdown_menu_t *menu, sfEvent const *event)
{
    update_buttons(menu, event);
    menu->is_folded = is_menu_folded(menu);
}
