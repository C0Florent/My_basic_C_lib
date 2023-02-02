/*
** EPITECH PROJECT, 2023
** B-MUL-100-NAN-1-1-myradar-florent.charpentier
** File description:
** show_dump
*/

#include <stdlib.h>
#include <stdbool.h>
#include <sys/types.h>
#include "my.h"
#include "newmy.h"

static void show_byte(void *byte_ptr, char *buf)
{
    unsigned char byte_buffer = *((unsigned char *)(byte_ptr));

    mega_save_nbr(buf, byte_buffer, 16);
    if (buf[0] == '\0') {
        my_strcpy(buf, "00");
    }
    if (buf[1] == '\0') {
        my_shift_str(buf, 1);
        buf[0] = '0';
    }
    my_strupcase(buf);
    my_putstr(buf);
}

void show_dump(void *var_ptr, size_t var_size)
{
    char *buf = malloc(sizeof(char) * 3);
    bool first = true;

    for (unsigned int i = 0 ; i < var_size; i++) {
        my_str_initialise(buf, 3);
        if (!first) {
            my_putchar(' ');
        } else {
            first = false;
        }
        show_byte(var_ptr + i, buf);
    }
    my_putchar('\n');
    free(buf);
}
