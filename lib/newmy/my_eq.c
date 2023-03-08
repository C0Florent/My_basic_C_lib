/*
** EPITECH PROJECT, 2023
** My eq
** File description:
** Magic function to compare any type of variables
*/

#include <sys/types.h>
#include <stdint.h>
#include <stdbool.h>

// Function to check if 2 variables of any type are equal, byte by byte
// Example usage: my_eq(&my_var1, &my_var2, sizeof(my_var1))
bool my_eq(void const *var1, void const *var2, size_t var_size)
{
    uint8_t *var1_ptr = (uint8_t *)var1;
    uint8_t *var2_ptr = (uint8_t *)var2;

    for (unsigned int i = 0; i < var_size; i++) {
        if (var1_ptr[i] != var2_ptr[i]) {
            return (false);
        }
    }
    return (true);
}
