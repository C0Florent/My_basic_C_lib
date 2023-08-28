/*
** EPITECH PROJECT, 2022
** Count char occurencies
** File description:
** count_char_occurencies
*/

int count_occurencies(char const *tested_str, char to_count)
{
    int count = 0;

    for (int i = 0; tested_str[i] != '\0'; i++) {
        if (tested_str[i] == to_count) {
            count++;
        }
    }
    return (count);
}
