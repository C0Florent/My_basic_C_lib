/*
** EPITECH PROJECT, 2023
** MY
** File description:
** display_menu
*/

#include <SFML/Graphics/Text.h>
#include <SFML/Graphics/RenderWindow.h>
#include "my_ui.h"

static bool need_to_display_opts(dropdown_menu_t const *menu)
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

static void display_options(
    sfRenderWindow *window,
    dropdown_menu_t const *menu
)
{
    if (need_to_display_opts(menu) == false) {
        return;
    }
    for (menu_opt_t *i = menu->option_ll; i != NULL; i = i->next) {
        button_display(window, i->option);
        sfRenderWindow_drawText(window, i->rendername, NULL);
    }
}

void display_menu(sfRenderWindow *window, dropdown_menu_t const *menu)
{
    button_display(window, menu->menu_button);
    sfRenderWindow_drawText(window, menu->rendername, NULL);
    display_options(window, menu);
}
