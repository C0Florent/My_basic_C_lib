/*
** EPITECH PROJECT, 2023
** slidebar_set_bounds
** File description:
** Function to set the minimum and maximum values for a slidebar
*/

#include <unistd.h>
#include "my_ui.h"

void slidebar_set_bound_values(
    slidebar_t *sb,
    float min,
    float max,
    set_bound_val_mode_t set_mode
)
{
    sb->min_val = min;
    sb->max_val = max;
    switch (set_mode) {
    case KEEP_POS:
        sb->value = ((sb->max_val - sb->min_val) / sb->bar_size.x)
        * (sb->cursor_pos + sb->bar_size.x / 2.0) + sb->min_val;
        break;
    case KEEP_VAL:
        write(2, "KEEP_VAL is not handled yet\n", 28);
        break;
    default:
        break;
    }
}
