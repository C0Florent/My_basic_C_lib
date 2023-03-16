/*
** EPITECH PROJECT, 2023
** Add menu option
** File description:
** Function to add an option to a dropdown menu
*/

#include <stdlib.h>
#include <SFML/Graphics/Text.h>
#include "my.h"
#include "newmy.h"
#include "my_ui.h"

static button_t *init_option_button(__attribute((unused))dropdown_menu_t const *menu)
{
    return (button_create((sfVector2f){0, 0}, (sfVector2f){20, 20}, BASIC));
}

static menu_opt_t *init_option(dropdown_menu_t *menu, char const *opt_name)
{
    menu_opt_t *ret = malloc(sizeof(menu_opt_t));

    if (ret == NULL) {
        my_putsterr("init_option: malloc failed\n");
        return (NULL);
    }
    ret->requests_action = false;
    ret->requests_menu_close = false;
    ret->name = my_strdup(opt_name);
    ret->rendername = sfText_create();
    sfText_setFont(ret->rendername, menu->font);
    sfText_setString(ret->rendername, opt_name);
    ret->option = init_option_button(menu);
    return (ret);
}

void add_menu_option(dropdown_menu_t *menu, char const *opt_name)
{
    menu_opt_t *new_opt = init_option(menu, opt_name);

    if (new_opt == NULL) {
        return;
    }
    menu->opt_count++;
    new_opt->next = menu->option_ll;
    menu->option_ll = new_opt;
}
