/*
** EPITECH PROJECT, 2023
** 2d coords header
** File description:
** File containing the definition of the 2d_coords structure
*/

#ifndef _2D_COORDS_H_
    #define _2D_COORDS_H_

    #include <stdbool.h>

typedef struct coordinates_2d {
    int x;
    int y;
} _2d_coords_t;


// Checks if 2 _2d_coord_t structures are exactly equal in both axes
bool eq_2d_coords(_2d_coords_t const *c1, _2d_coords_t const *c2);

#endif /* !2D_COORDS_H_ */
