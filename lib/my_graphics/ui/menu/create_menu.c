/*
** EPITECH PROJECT, 2023
** Create menu
** File description:
** Function to create a drop down menu
*/

#include <stdlib.h>
#include <SFML/Graphics/Text.h>
#include <SFML/Graphics/RectangleShape.h>
#include "my.h"
#include "newmy.h"
#include "my_ui.h"

static void init_rendername(dropdown_menu_t *menu, char const *name,
    sfFont *font, sfVector2f pos)
{
    menu->name = my_strdup(name);
    menu->rendername = sfText_create();
    sfText_setString(menu->rendername, menu->name);
    sfText_setFont(menu->rendername, font);
    sfText_setPosition(menu->rendername, pos);
    sfText_setFillColor(menu->rendername, sfBlack);
}

static void init_button(dropdown_menu_t *menu)
{
    sfFloatRect txt_bounds = sfText_getGlobalBounds(menu->rendername);
    sfVector2f center = {txt_bounds.left + txt_bounds.width / 2,
                        txt_bounds.top + txt_bounds.height / 2};
    sfVector2f size = {txt_bounds.width + 10, txt_bounds.height + 10};

    menu->menu_button = button_create(center, size, ON_OFF);
    sfRectangleShape_setOutlineThickness(menu->menu_button->rect, 2);
    menu->menu_button->display_function = &display_menu_button;
}

dropdown_menu_t *create_menu(char const *name, sfFont *font, sfVector2f pos)
{
    dropdown_menu_t *ret = malloc(sizeof(dropdown_menu_t));

    if (ret == NULL) {
        my_putsterr("create_menu: malloc failed\n");
        return (NULL);
    }
    init_rendername(ret, name, font, pos);
    init_button(ret);
    ret->font = font;
    ret->pos = pos;
    ret->is_folded = true;
    ret->opt_count = 0;
    ret->option_ll = NULL;
    return (ret);
}
