/*
** EPITECH PROJECT, 2023
** Add menu option
** File description:
** Function to add an option to a dropdown menu
*/

#include <stdlib.h>
#include <SFML/Graphics/Text.h>
#include <SFML/Graphics/RectangleShape.h>
#include "my.h"
#include "newmy.h"
#include "my_ui.h"

static sfVector2f get_button_pos(dropdown_menu_t const *menu,
    sfVector2f button_size)
{
    sfVector2f ret;

    if (menu->opt_count == 0) {
        ret.x = menu->menu_button->pos.x - menu->menu_button->size.x / 2 + 150;
        ret.y = menu->menu_button->pos.y +
            menu->menu_button->size.y / 2 + button_size.y / 2 + 4;
    } else {
        ret.x = menu->option_ll->option->pos.x;
        ret.y = menu->option_ll->option->pos.y +
            menu->option_ll->option->size.y / 2 + button_size.y / 2 + 4;
    }
    return (ret);
}

static button_t *init_option_button(dropdown_menu_t const *menu,
    sfText *rendername)
{
    button_t *ret;
    sfVector2f button_size;
    sfVector2f button_pos;

    button_size.x = 300;
    button_size.y = sfText_getGlobalBounds(rendername).height + 10;
    button_pos = get_button_pos(menu, button_size);
    ret = button_create(button_pos, button_size, BASIC);
    sfRectangleShape_setOutlineThickness(ret->rect, 2);
    return (ret);
}

static menu_opt_t *init_option(dropdown_menu_t *menu, char const *opt_name)
{
    menu_opt_t *ret = malloc(sizeof(menu_opt_t));
    sfVector2f text_pos;

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
    sfText_setFillColor(ret->rendername, sfBlack);
    ret->option = init_option_button(menu, ret->rendername);
    text_pos = ret->option->pos;
    text_pos.x -= ret->option->size.x / 2 - 5;
    text_pos.y -= ret->option->size.y / 2 + 5;
    sfText_setPosition(ret->rendername, text_pos);
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
