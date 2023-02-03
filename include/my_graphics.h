/*
** EPITECH PROJECT, 2022
** MY
** File description:
** my_graphics
*/

#ifndef MY_GRAPHICS_H_
    #define MY_GRAPHICS_H_

    #include <SFML/Graphics/RenderWindow.h>
    #include <SFML/System/Vector2.h>

typedef struct {
    sfTexture *txtr;
    sfSprite *sprt;
} disp_sprt_t;



sfVector2f vctr2f(float x, float y);
sfVector2i vctr2i(int x, int y);

// Will create a displayable sprite, into a disp_sprt_t
// structure, from a the filepath of the texture to use
disp_sprt_t *my_create_sprite(char *txtr_path, float scale_x, float scale_y);

// Will properly free a disp_sprt_t structure
void destroy_disp_sprt(disp_sprt_t *displayble_sprite);


sfRenderWindow *my_create_window(char const *window_name);

#endif /* !MY_GRAPHICS_H_ */
