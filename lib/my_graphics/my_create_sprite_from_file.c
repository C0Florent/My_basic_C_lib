/*
** EPITECH PROJECT, 2023
** My create sprite from file
** File description:
** Will create a displayable sprite, into a disp_sprt_t
** structure, from a the filepath of the texture to use
*/

#include <stdlib.h>
#include <SFML/Graphics/Sprite.h>
#include <SFML/Graphics/Texture.h>
#include "my_graphics.h"

disp_sprt_t *my_create_sprite(char *txtr_path, float scale_x, float scale_y)
{
    disp_sprt_t *disp_sprt = malloc(sizeof(disp_sprt_t));
    sfVector2f scale = {scale_x, scale_y};

    disp_sprt->txtr = sfTexture_createFromFile(txtr_path, NULL);
    disp_sprt->sprt = sfSprite_create();
    if (disp_sprt->txtr == NULL || disp_sprt->sprt == NULL) {
        return (disp_sprt);
    }
    sfSprite_setTexture(disp_sprt->sprt, disp_sprt->txtr, sfTrue);
    sfSprite_setScale(disp_sprt->sprt, scale);
    return (disp_sprt);
}
