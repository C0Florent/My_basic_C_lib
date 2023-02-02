/*
** EPITECH PROJECT, 2022
** MY
** File description:
** my_math
*/

#ifndef MY_MATH_H_
    #define MY_MATH_H_

    #include <stdbool.h>
    #define SQ(nb)  (nb) * (nb)
    #define MY_PI   3.14159265358979323846
    #define DELTA(a, b, c)  SQ(b) - 4 * (a) * (c)

/* DISPLAY */

// Displays a float in the most sensible way: going up to 'precision'
// decimal places, only if said decimal places are nonzero.
//
// Will always print at least 1 decimal place after the decimal dot,
// to clearly indicate that the displayed number is a float.
void put_float_right(double nb, int precision);

//////////////////////////////////////


/* TESTS */

// Returns true if `a` and `b`'s first `precision` decimal place are equal
bool approx_eq(double a, double b, int precision);

// Returns true if str corresponds to a float number format:
// contains potentially a '-' as a first character, then 1 or 0
// '.', and is made only of digits except for the previous cases
bool my_str_is_float(char *str);

#endif /* !MY_MATH_H_ */
