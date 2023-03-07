/*
** EPITECH PROJECT, 2023
** MY
** File description:
** test
*/

#include "my_graphics.h"
#include "my_ui.h"
#include <stdio.h>

static void analyse_events(sfRenderWindow *wndw, slidebar_t *sb,
button_t *btn1, button_t *btn2, button_t *btn3)
{
    sfEvent event;

    while (sfRenderWindow_pollEvent(wndw, &event)) {
        if (event.type == sfEvtClosed) {
            sfRenderWindow_close(wndw);
        }
        move_cursor(sb, &event);
        update_button_state(btn1, &event);
        update_button_state(btn2, &event);
        update_button_state(btn3, &event);
    }
}

int main(void)
{
    sfRenderWindow *wndw = my_create_window("test");
    slidebar_t *sb = create_slidebar(vctr2f(1800, 200), vctr2f(100, 20));
    button_t *button1 = button_create(vctr2f(500, 200), vctr2f(45, 45));
    button_t *button2 = button_create(vctr2f(575, 200), vctr2f(45, 45));
    button_t *button3 = button_create(vctr2f(650, 200), vctr2f(45, 45));

    slidebar_set_bound_values(sb, 0, 5, KEEP_POS);
    while (sfRenderWindow_isOpen(wndw)) {
        display_slidebar(wndw, sb);
        button_display(wndw, button1);
        button_display(wndw, button2);
        button_display(wndw, button3);
        printf("\r%f", sb->value);
        fflush(stdout);
        sfRenderWindow_display(wndw);
        sfRenderWindow_clear(wndw, sfColor_fromInteger(0x23272A00));
        analyse_events(wndw, sb, button1, button2, button3);
    }
    destroy_slidebar(sb);
    button_destroy(button1);
    button_destroy(button2);
    button_destroy(button3);
    sfRenderWindow_destroy(wndw);
    printf("\n");
    return (0);
}
