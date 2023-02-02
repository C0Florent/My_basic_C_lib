/*
** EPITECH PROJECT, 2023
** Destroy disp_sprt
** File description:
** Function to properly free a disp_sprt structure
*/

#include <stdlib.h>
#include <SFML/Graphics/Texture.h>
#include <SFML/Graphics/Sprite.h>
#include "my_graphics.h"

void destroy_disp_sprt(disp_sprt_t *disp_sprt)
{
    sfSprite_destroy(disp_sprt->sprt);
    sfTexture_destroy(disp_sprt->txtr);
    free(disp_sprt);
}
