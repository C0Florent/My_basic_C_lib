/*
** EPITECH PROJECT, 2023
** My macros
** File description:
** Header file containing various macros for all sorts of purposes
*/

#ifndef MY_MACROS_H_
    #define MY_MACROS_H_

    #ifndef ABS
        #define ABS(val)    (((val) < 0) ? (-(val)) : (val))
    #endif /* ABS */


    #define MAX(a, b)   (((a) > (b)) ? (a) : (b))
    #define MIN(a, b)   (((a) < (b)) ? (a) : (b))


    #ifndef EXIT_FAILURE
        #define EXIT_FAILURE 1
    #endif /* EXIT_FAILURE */

    #ifndef EXIT_SUCCESS
        #define EXIT_SUCCESS 0
    #endif /* EXIT_SUCCESS */

#endif /* !MY_MACROS_H_ */
