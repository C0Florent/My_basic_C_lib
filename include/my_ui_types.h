/*
** EPITECH PROJECT, 2023
** My_UI types
** File description:
** Files containing definitions of types and macros
*/

#ifndef MY_UI_TYPES_H_
    #define MY_UI_TYPES_H_


    #include <stdbool.h>
    #include <SFML/Graphics/Types.h>
    #include <SFML/System/Vector2.h>
    #include <SFML/Window/Event.h>


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



//////////////////////////////////
//        DROP DOWN MENUS       //
//////////////////////////////////

typedef struct menu_option {
    char *name;
    sfText *rendername;
    button_t *option;
    bool requests_action;
    bool requests_menu_close;

    struct menu_option *next;
} menu_opt_t;

typedef struct {
    char *name;
    unsigned int opt_count;
    bool is_folded;
    sfFont *font;           // Font to be used for the whole menu
    sfText *rendername;     // Title of the menu
    sfVector2f pos;         // Top left corner
    button_t *menu_button;  // Appears even when the menu is folded up
    menu_opt_t *option_ll;  // Linked list containing the options
} dropdown_menu_t;



#endif /* !MY_UI_TYPES_H_ */
