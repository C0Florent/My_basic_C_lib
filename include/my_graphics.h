/*
** EPITECH PROJECT, 2022
** MY
** File description:
** my_graphics
*/

#ifndef MY_GRAPHICS_H_
    #define MY_GRAPHICS_H_

    #include <stdbool.h>
    #include <SFML/Graphics/RenderWindow.h>
    #include <SFML/System/Vector2.h>

    #ifndef ABS
        #define ABS(val)    (((val) < 0) ? (-(val)) : (val))
    #endif /* ABS */


/* STRUCTURES */

// Structure for easy-to-use sprites, containing both the sprite
// and the texture in a sinlge object
typedef struct {
    sfTexture *txtr;
    sfSprite *sprt;
} disp_sprt_t;




// Create a window with some basic set() for the usual window
sfRenderWindow *my_create_window(char const *window_name);

sfVector2i vctr2i(int x, int y);
sfVector2f vctr2f(float x, float y);
sfVector2f scalar_v2f(sfVector2f vector, float scalar);

// Will create a displayable sprite, into a disp_sprt_t
// structure, from a the filepath of the texture to use
disp_sprt_t *my_create_sprite(char *txtr_path, float scale_x, float scale_y);

// Will properly free a disp_sprt_t structure
void destroy_disp_sprt(disp_sprt_t *displayble_sprite);



#endif /* !MY_GRAPHICS_H_ */
