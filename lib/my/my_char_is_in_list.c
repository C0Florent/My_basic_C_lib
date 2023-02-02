/*
** EPITECH PROJECT, 2022
** My char is in list
** File description:
** Returns 1 if the given char is somewhere
** in the given string, otherwise returns 0
*/

int my_char_is_in_list(char c, char *str)
{
    for (int i = 0; str[i] != '\0'; i++) {
        if (str[i] == c)
            return (1);
    }
    return (0);
}
