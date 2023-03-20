/*
** EPITECH PROJECT, 2022
** B-MAT-100-NAN-1-1-102architect-florent.charpentier
** File description:
** matrix
*/

#ifndef MATRIX_H_
    #define MATRIX_H_

    #include <stdbool.h>

    #ifndef MATRIX_T
        #define MATRIX_T
typedef struct {
    unsigned int height;
    unsigned int width;
    double **coords;
} matrix_t ;
    #endif /* MATRIX_T */

matrix_t *alloc_matrix_t(unsigned int height, unsigned int width);
void free_matrix_t(matrix_t *m);


void set_to_zero(matrix_t *m);

// Will print a warning on stderr if m is not square and silent is false
void set_to_id(matrix_t *m, bool silent);

void scalar(matrix_t *m, double scale);

// Computes the sum of two matrices
void addition(matrix_t const *m1, matrix_t const *m2, matrix_t *res);

void product(matrix_t *m1, matrix_t *m2, matrix_t *result);

void matrix_copy(matrix_t const *src, matrix_t *dest);
matrix_t *matrix_dup(matrix_t const *src);

// Shows all the elements of given matrix.
// For default display, pass 0 as display mode or/and NULL as display function
//
// For other display types, pass a specific display mode as parameter, and the
// function you want to display the numbers in the matrix
void show_matrix(matrix_t *m, int precision,
unsigned char display_mode, void (*display_func)(double, int));

void transpose(matrix_t *src, matrix_t *dest);


void submatrix(matrix_t const *m, unsigned int row, unsigned int col,
matrix_t *submatrix);


double determinant(matrix_t const *m);

void comatrix(matrix_t const *src, matrix_t *dest);

int inverse(matrix_t const *src, matrix_t *dest);


#endif /* !MATRIX_H_ */
