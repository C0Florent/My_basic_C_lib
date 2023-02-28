/*
** EPITECH PROJECT, 2023
** My slidebar Header
** File description:
** Header file for evertything around the slidebar_t
** structure, which is a great CSFML UI tool
*/

#ifndef MY_SLIDEBAR_H_
    #define MY_SLIDEBAR_H_

    #include <stdbool.h>
    #include <SFML/Graphics/Types.h>
    #include <SFML/System/Vector2.h>
    #include <SFML/Window/Event.h>


    #ifndef ABS
        #define ABS(val)    (((val) < 0) ? (-(val)) : (val))
    #endif /* ABS */


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




// Create a slidebar, which will be centered at `pos`, and of size `bar_size`
slidebar_t *create_slidebar(sfVector2f pos, sfVector2f bar_size);

// Display a slidebar
void display_slidebar(sfRenderWindow *window, slidebar_t const *slidebar);

// Destroy (free) a slidebar
void destroy_slidebar(slidebar_t *sb);


typedef enum {
    KEEP_POS,
    KEEP_VAL,
    RESET_NONE,
} set_bound_val_mode_t;
// There are three modes possible for set_mode: KEEP_POS to keep the
// cursor position constant and thus update the slidebar's value to match
// The new scale, KEEP_VAL to keep the slidebar's value and thus move the
// cursor's position to match the new scale
//
// Special case if the value is out of range of the newly set bounds with
// KEEP_VAL mode: the cursor will be set to the closest bound but the value
// will not be updated (will stay out of range)
void slidebar_set_bound_values(slidebar_t *sb, float min,
float max, set_bound_val_mode_t set_mode);

void slidebar_cursor_set_pos(slidebar_t *sb, float pos);
void slidebar_cursor_set_pos_from_mouse_pos(slidebar_t * sb,
sfMouseButtonEvent const *click_pos);
void slidebar_cursor_set_value(slidebar_t *sb, float value);

#endif /* !MY_SLIDEBAR_H_ */
