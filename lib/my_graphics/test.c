/*
** EPITECH PROJECT, 2023
** MY
** File description:
** test
*/

#include "my_graphics.h"
#include "my_slidebar.h"
#include <stdio.h>

static void analyse_events(sfRenderWindow *wndw, slidebar_t *sb)
{
    sfEvent event;

    while (sfRenderWindow_pollEvent(wndw, &event)) {
        if (event.type == sfEvtClosed) {
            sfRenderWindow_close(wndw);
        }
        move_cursor(sb, &event);
    }
}

int main(void)
{
    sfRenderWindow *wndw = my_create_window("test");
    slidebar_t *sb = create_slidebar(vctr2f(1800, 200), vctr2f(100, 20));

    slidebar_set_bound_values(sb, 0, 5, KEEP_POS);
    while (sfRenderWindow_isOpen(wndw)) {
        display_slidebar(wndw, sb);
        printf("\r%f", sb->value);
        fflush(stdout);
        sfRenderWindow_display(wndw);
        sfRenderWindow_clear(wndw, sfColor_fromInteger(0x23272A00));
        analyse_events(wndw, sb);
    }
    destroy_slidebar(sb);
    sfRenderWindow_destroy(wndw);
    printf("\n");
    return (0);
}