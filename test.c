/*
** EPITECH PROJECT, 2023
** MY
** File description:
** test
*/

#include <SFML/Graphics/Font.h>
#include "my_graphics.h"
#include "my_ui.h"
#include <stdio.h>

static void analyse_events(sfRenderWindow *wndw, slidebar_t *sb,
button_t *btn1, button_t *btn2, button_t *btn3, dropdown_menu_t *menu)
{
    sfEvent event;

    frame_reset_button(btn1);
    frame_reset_button(btn2);
    frame_reset_button(btn3);
    frame_reset_button(menu->menu_button);
    while (sfRenderWindow_pollEvent(wndw, &event)) {
        if (event.type == sfEvtClosed) {
            sfRenderWindow_close(wndw);
        }
        move_cursor(sb, &event);
        update_button_state(btn1, &event);
        update_button_state(btn2, &event);
        update_button_state(btn3, &event);
        update_menu(menu, &event);
    }
    if (btn1->rising_edge) {
        printf("Pressed!...   ");
        fflush(stdout);
    }
    if (btn1->falling_egde) {
        printf("Released!\n");
        fflush(stdout);
    }
}

int main(void)
{
    sfRenderWindow *wndw = my_create_window("test");
    slidebar_t *sb = create_slidebar(vctr2f(1800, 200), vctr2f(100, 20));
    button_t *button1 = button_create(vctr2f(500, 200), vctr2f(45, 45), BASIC);
    button_t *button2 = button_create(vctr2f(575, 200), vctr2f(45, 45), ON_OFF);
    button_t *button3 = button_create(vctr2f(650, 200), vctr2f(45, 45), BASIC);
    sfFont *font = sfFont_createFromFile("assets/Calibri Regular.ttf");
    dropdown_menu_t *menu = create_menu("iiiiii\nii\n iiii.", font, vctr2f(50, 100));

    slidebar_set_bound_values(sb, 0, 5, KEEP_POS);
    while (sfRenderWindow_isOpen(wndw)) {
        sfRenderWindow_clear(wndw, sfColor_fromInteger(0x23272A00));
        analyse_events(wndw, sb, button1, button2, button3, menu);
        display_slidebar(wndw, sb);
        button_display(wndw, button1);
        button_display(wndw, button2);
        button_display(wndw, button3);
        display_menu(wndw, menu);
        sfRenderWindow_display(wndw);
    }
    destroy_slidebar(sb);
    button_destroy(button1);
    button_destroy(button2);
    button_destroy(button3);
    destroy_menu(menu);
    sfRenderWindow_destroy(wndw);
    sfFont_destroy(font);
    printf("\n");
    return (0);
}
