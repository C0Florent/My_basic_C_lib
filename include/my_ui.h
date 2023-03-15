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

/// COLOURS ///

#define MY_PINK         sfColor_fromInteger(0xFF54A6FF)
#define MY_SKYBLUE      sfColor_fromInteger(0x00FFFBFF)
#define DISCORD_GREY    sfColor_fromInteger(0x23272A00)
#define MY_LIGHTGREY    sfColor_fromInteger(0xD4D4D4FF)
#define MY_MIDGREY      sfColor_fromInteger(0x808080FF)
#define MY_DARKGREY     sfColor_fromInteger(0x424242FF)
#define MY_BLUE         sfColor_fromInteger(0x3D70E0FF)


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

typedef struct button {
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

    // Specify here the function which should be used to display the button
    // This function will be called, when calling `button_display()`
    void (*display_function)(sfRenderWindow *wndw, struct button const *button);
} button_t;


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




//////////////////////////////////
//        DROP DOWN MENUS       //
//////////////////////////////////

typedef struct menu_option {
    char *name;
    sfText *rendername;
    button_t *option;
    bool requests_action;

    struct menu_option *next;
} menu_opt_t;

typedef struct {
    char *name;
    unsigned int opt_count;
    sfFont *font;           // Font to be used for the whole menu
    sfText *rendername;     // Title of the menu
    sfVector2f pos;         // Top left corner
    button_t *menu_button;  // Appears even when the menu is folded up
    menu_opt_t *option_ll;  // Linked list containing the options
} dropdown_menu_t;


dropdown_menu_t *create_menu(char const *name, sfFont *font, sfVector2f pos);

void add_menu_option(dropdown_menu_t *menu, char const *option_name);

void destroy_menu(dropdown_menu_t *menu);

// Function to be called once per frame, to update the menu's state
void update_menu(dropdown_menu_t *menu);

void display_option_button(sfRenderWindow *wndw, button_t const *button);

void display_menu_button(sfRenderWindow *wndw, button_t const *button);

void display_menu(sfRenderWindow *window, dropdown_menu_t const *menu);

#endif /* !MY_SLIDEBAR_H_ */
