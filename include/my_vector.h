/*
** EPITECH PROJECT, 2022
** MY
** File description:
** my_vector
*/

#ifndef MY_VECTOR_H_
    #define MY_VECTOR_H_

typedef struct {
    double *coords;
    unsigned int size;
} vector_t;

vector_t *alloc_vector_t(unsigned int size);

void free_vector_t(vector_t *vector);

void show_vector(vector_t *vector);

#endif /* !MY_VECTOR_H_ */
