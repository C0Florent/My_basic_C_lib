/*
** EPITECH PROJECT, 2023
** sfvctr
** File description:
** Function to return a sfVector2f from coordinates
*/

#include <SFML/System/Vector2.h>

sfVector2f vctr2f(float x, float y)
{
    sfVector2f ret = {x, y};

    return (ret);
}

sfVector2i vctr2i(int x, int y)
{
    sfVector2i ret = {x, y};

    return (ret);
}
