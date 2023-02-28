/*
** EPITECH PROJECT, 2023
** My eq test
** File description:
** Unit tests for my_eq
*/

#include <criterion/criterion.h>
#include "newmy.h"

#include "my_ui.h"
#include "my_graphics.h"

Test(my_eq, basic_success)
{
    int a = 42;
    int b = 42;
    cr_assert(my_eq(&a, &b, sizeof(int)) == true);
}

Test(my_eq, structure_success)
{
    slidebar_t a;
    slidebar_t b;

    memset(&a, 42, sizeof(slidebar_t));
    memset(&a + 14, 47, 7);
    memset(&a, 84, 7);

    memcpy(&b, &a, sizeof(slidebar_t));
    cr_assert(my_eq(&a, &b, sizeof(slidebar_t)) == true);
}

Test(my_eq, basic_fail)
{
    short a = 42;
    short b = 84;
    cr_assert(my_eq(&a, &b, sizeof(short)) == false);
}
