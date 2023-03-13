/*
** EPITECH PROJECT, 2023
** MY
** File description:
** eval_poly_tests
*/

#include <criterion/criterion.h>
#include <stdio.h>
#include "my_vector.h"
#include "my_math.h"

Test(eval_poly, basic_test)
{
    vector_t *coefs = alloc_vector_t(3);
    double result;

    cr_assert_not_null(coefs);
    coefs->coords[0] = 3.0;
    coefs->coords[1] = 2.0;
    coefs->coords[2] = 7.0;
    result = poly(coefs, 3);
    
    printf("%f == %f\n", result, 72.0);
    cr_assert(approx_eq(result, 72, 8));
}
