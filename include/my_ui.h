/*
** EPITECH PROJECT, 2023
** My slidebar Header
** File description:
** Header file for evertything around the slidebar_t
** structure, which is a great CSFML UI tool
*/

#ifndef MY_SLIDEBAR_H_
    #define MY_SLIDEBAR_H_

    #include "my_ui_types.h"

    #ifndef ABS
        #define ABS(val)    (((val) < 0) ? (-(val)) : (val))
    #endif /* ABS */




//////////////////////////////
//      ALL-PURPOSE UI      //
//////////////////////////////


// Function to check if a sfEvent refers to a mouse event
// (and even of a specific mouse button for press/release events)
bool is_mouse_event(sfEvent const *event, sfMouseButton accepted_click);

// Returns the mouse position contained in the
// sfEvent, or (-84;-84) if not a mouse event
sfVector2f get_mouse_pos(sfEvent const *event);


// Scale should be (initial_size / current_size) i.e. the reduction scale
sfVector2f get_scaled_mouse_pos(sfEvent const *event, sfVector2f scale);



///////////////////////////
//        BUTTONS        //
///////////////////////////


// Function to properly initialise a button_t structure
button_t *button_create(sfVector2f position, sfVector2f size,
    enum button_type type);

// Function to properly destroy (free) a button_t structure
void button_destroy(button_t *button);

// Function to draw a button on the window's framebuffer,
// which will the button's display function specified in its structure
void button_display(sfRenderWindow *wndw, button_t const *button);

// Proof of concept display function, which shows the possibilities of the
// button structure, without much concern for aesthetic
void poc_button_display(sfRenderWindow *wndw, button_t const *button);

// Function to be called once per frame,
// to reset the button's falling edge and rising edge booleans
void frame_reset_button(button_t *button);

// Returns true if the given coordinates are within the button boundary
bool is_mouse_on_button(
    float mouse_x,
    float mouse_y,
    button_t const *button
);

// Function to be called during the sfRenderWindow_pollEvent loop,
// to update the button's internal state depending on mouse actions
void update_button_state(
    button_t *button,
    sfEvent const *event,
    sfVector2f window_scale
);


/////////////////////////////
//        SLIDEBARS        //
/////////////////////////////


// Create a slidebar, which will be centered at `pos`, and of size `bar_size`
slidebar_t *create_slidebar(sfVector2f pos, sfVector2f bar_size);

// Display a slidebar
void display_slidebar(sfRenderWindow *window, slidebar_t const *slidebar);

// Destroy (free) a slidebar
void destroy_slidebar(slidebar_t *sb);

// This function needs to be called for each frame of rendered image,
// in order to properly update the sb's cursor position
void move_cursor(slidebar_t *sb, sfEvent const *event);

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
void slidebar_set_bound_values(
    slidebar_t *sb,
    float min,
    float max,
    set_bound_val_mode_t set_mode
);

// Sets the slidebar's cursor position to given pos, which is, in pixels,
// the relative distance of the cursor's center and the slidebar's center
void slidebar_cursor_set_pos(slidebar_t *sb, float pos);

// Sets the slidebar's cursor position to the
// mouse position which is given as parameter
void slidebar_cursor_set_pos_from_mouse_pos(
    slidebar_t *sb,
    sfMouseButtonEvent const *click_pos
);

// Sets the slidebar's value to given value, and
// updating its graphical position accordingly
void slidebar_cursor_set_value(slidebar_t *sb, float value);




//////////////////////////////////
//        DROP DOWN MENUS       //
//////////////////////////////////


dropdown_menu_t *create_menu(char const *name, sfFont *font, sfVector2f pos);

void add_menu_option(
    dropdown_menu_t *menu,
    char const *option_name,
    enum button_type type
);

void destroy_menu(dropdown_menu_t *menu);

// Function to be called once per fram,
// to reset the menu's buttons' falling and rising edge booleans
void frame_reset_menu(dropdown_menu_t *menu);

// Function to be called once per frame, to update the menu's state
void update_menu(
    dropdown_menu_t *menu,
    sfEvent const *event,
    sfVector2f wndw_scale
);

void display_option_button(sfRenderWindow *wndw, button_t const *button);
void display_menu_button(sfRenderWindow *wndw, button_t const *button);

void display_menu(sfRenderWindow *window, dropdown_menu_t const *menu);

#endif /* !MY_SLIDEBAR_H_ */
