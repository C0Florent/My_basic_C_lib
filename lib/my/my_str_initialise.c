/*
** EPITECH PROJECT, 2022
** My str initialise
** File description:
** Sets the n first chars of given str to '\0'
*/

int my_str_initialise(char *str, int size)
{
    for (int i = 0; i < size; i++)
        str[i] = '\0';
    return (0);
}
