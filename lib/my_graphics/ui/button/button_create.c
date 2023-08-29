/*
** EPITECH PROJECT, 2023
** Init button
** File description:
** Function to properly initialise a button_t structure
*/

#include <unistd.h>
#include <stdlib.h>
#include <SFML/System/Vector2.h>
#include <SFML/Graphics/RectangleShape.h>
#include "my_ui.h"

static void init_sfrect_shape(sfRectangleShape *rect,
    sfVector2f size, sfVector2f pos)
{
    sfVector2f center_pos = {pos.x - size.x / 2, pos.y - size.y / 2};

    sfRectangleShape_setPosition(rect, center_pos);
    sfRectangleShape_setSize(rect, size);
    sfRectangleShape_setFillColor(rect, sfWhite);
    sfRectangleShape_setOutlineColor(rect, sfBlack);
    sfRectangleShape_setOutlineThickness(rect, 2.2);
}

static bool init_button(button_t *button, sfVector2f pos,
    sfVector2f size, enum button_type type)
{
    button->rect = sfRectangleShape_create();
    if (button->rect == NULL) {
        write(2, "init_button: could not create rectangle\n", 40);
        free(button);
        return (EXIT_FAILURE);
    }
    button->state = NONE;
    button->clicked = false;
    button->rising_edge = false;
    button->falling_egde = false;
    button->type = type;
    button->on = false;
    button->on_ptr = NULL;
    init_sfrect_shape(button->rect, size, pos);
    button->size = size;
    button->pos = pos;
    button->display_function = NULL;
    return (EXIT_SUCCESS);
}

button_t *button_create(sfVector2f position, sfVector2f size,
enum button_type type)
{
    button_t *ret = malloc(sizeof(button_t));
    bool init_ret;

    if (ret == NULL) {
        write(2, "create_button: malloc error\n", 27);
        return (NULL);
    }
    init_ret = init_button(ret, position, size, type);
    if (init_ret == EXIT_FAILURE) {
        return (NULL);
    }
    return (ret);
}
