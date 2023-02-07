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

typedef struct {
    bool is_grabbed;
    float cursor_pos;
    float value;
    float min_val;
    float max_val;
    sfVector2f center;
    sfVector2f bar_size;
    sfRectangleShape *bar;
    sfRectangleShape *cursor;
} slidebar_t;



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




// Create a slidebar, which will be centered at `pos`, and of size `bar_size`
slidebar_t *create_slidebar(sfVector2f pos, sfVector2f bar_size);

// Display a slidebar
void display_slidebar(sfRenderWindow *window, slidebar_t const *slidebar);

// Destroy (free) a slidebar
void destroy_slidebar(slidebar_t *sb);


void slidebar_set_min_max_values(slidebar_t *sb, float min, float max);
void slidebar_cursor_set_pos(slidebar_t *sb, float pos);
void slidebar_cursor_set_pos_from_mouse_pos(slidebar_t * sb,
sfMouseButtonEvent const *click_pos);
void slidebar_cursor_set_value(slidebar_t *sb, float value);


#endif /* !MY_GRAPHICS_H_ */
