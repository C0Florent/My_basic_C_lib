/*
** EPITECH PROJECT, 2023
** destroy menu
** File description:
** Functon to properly destroy (free) a drowdown menu
*/

#include <stdlib.h>
#include <SFML/Graphics/Text.h>
#include "my_ui.h"

static void free_one_opt(menu_opt_t *option)
{
    free(option->name);
    sfText_destroy(option->rendername);
    button_destroy(option->option);
    free(option);
}

static void free_opt_ll(menu_opt_t *opt_ll)
{
    menu_opt_t *prev;
    menu_opt_t *curr = opt_ll;

    while (curr != NULL) {
        prev = curr;
        curr = curr->next;
        free_one_opt(prev);
    }
}

void destroy_menu(dropdown_menu_t *menu)
{
    free(menu->name);
    sfText_destroy(menu->rendername);
    button_destroy(menu->menu_button);
    free_opt_ll(menu->option_ll);
    free(menu);
}
