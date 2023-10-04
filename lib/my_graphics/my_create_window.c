/*
** EPITECH PROJECT, 2022
** My create window
** File description:
** my_create_window
*/

#include <SFML/Graphics/RenderWindow.h>
#include <SFML/System/Vector2.h>

sfRenderWindow *my_create_window(char const *window_name)
{
    sfVideoMode mode = {1920, 1024, 32};
    sfRenderWindow *window = sfRenderWindow_create(
        mode,
        window_name,
        sfClose | sfResize,
        NULL
    );

    sfRenderWindow_setFramerateLimit(window, 60);
    return (window);
}
