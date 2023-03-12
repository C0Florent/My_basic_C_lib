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




//////////////////////////////
//      ALL-PURPOSE UI      //
//////////////////////////////

// Defines three states for clickable UI elements:
// Hovered, Pressed, Released
enum clickable_ui_elem_state {
    NONE = 0,
    HOVER,
    PRESSED,
    RELEASED
};


// Function to check if a sfEvent refers to a mouse event
// (and even of a specific mouse button for press/release events)
bool is_mouse_event(sfEvent const *event, sfMouseButton accepted_click);




///////////////////////////
//        BUTTONS        //
///////////////////////////

enum button_type {
    BASIC,  // Proceeds the same action on each press,
            //  typically used for incrementors
    ON_OFF  // Keeps in memory an on/off state, and can be linked
            //  to another boolean to update it dynamically
};

typedef struct {
    enum clickable_ui_elem_state state;
    bool clicked;       // Remains true as long as a mouse click
                        //  started in the button area is not released
    bool rising_edge;   // Is true for 1 frame, when `click` becomes true
    bool falling_egde;  // Is true for 1 frame, when `click` becomes false
    enum button_type type;


    //Use only if type is ON_OFF

    bool on;        // Local boolean
    bool *on_ptr;   // Pointer to a boolean that can be modified remotely
                    //  by a button press. No operation will be done if NULL
    ///////////////////////////////

    sfRectangleShape *rect;
    sfVector2f pos;     // Center point
    sfVector2f size;
} button_t;


// Function to properly initialise a button_t structure
button_t *button_create(sfVector2f position, sfVector2f size,
    enum button_type type);

// Function to properly destroy (free) a button_t structure
void button_destroy(button_t *button);

// Function to draw a button on the window's framebuffer
void button_display(sfRenderWindow *wndw, button_t const *button);

// Function to be called during the sfRenderWindow_pollEvent loop,
// to update the button's internal state depending on mouse actions
void update_button_state(button_t *button, sfEvent const *event);


/////////////////////////////
//        SLIDEBARS        //
/////////////////////////////

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
void slidebar_set_bound_values(slidebar_t *sb, float min,
float max, set_bound_val_mode_t set_mode);

// Sets the slidebar's cursor position to given pos, which is, in pixels,
// the relative distance of the cursor's center and the slidebar's center
void slidebar_cursor_set_pos(slidebar_t *sb, float pos);

// Sets the slidebar's cursor position to the
// mouse position which is given as parameter
void slidebar_cursor_set_pos_from_mouse_pos(slidebar_t * sb,
sfMouseButtonEvent const *click_pos);

// Sets the slidebar's value to given value, and
// updating its graphical position accordingly
void slidebar_cursor_set_value(slidebar_t *sb, float value);

#endif /* !MY_SLIDEBAR_H_ */
