/*
** EPITECH PROJECT, 2022
** Put float right
** File description:
** Will display a float in the most sensical way
*/

#include <stdbool.h>
#include <stdlib.h>
#include <string.h>
#include <stdio.h>

static void format(char *nstr)
{
    bool neg = (nstr[0] == '-');
    int last_nonzero = neg;

    for (int i = neg; nstr[i] != '\0'; i++) {
        if (nstr[i] != '0') {
            last_nonzero = i;
        }
    }
    if (!strncmp("-0.", nstr, 3) && nstr[last_nonzero] == '.') {
        strcpy(nstr, "0.0");
        return;
    }
    if (nstr[last_nonzero] == '.') {
        nstr[last_nonzero + 2] = '\0';
    } else {
        nstr[last_nonzero + 1] = '\0';
    }
}

void put_float_right(double nb, int precision)
{
    int nb_len;
    char *nstr;

    if (precision <= 0) {
        dprintf(2, "put_float_right: refuses precision of zero, sets it to 1");
        precision = 1;
    }
    nb_len = precision + 4;
    *nstr = malloc(sizeof(char) * (nb_len));
    nstr[nb_len - 1] = '\0';
    sprintf(nstr, "%.*f", precision, nb);
    format(nstr);
    printf("%s", nstr);
    fflush(stdout);
    free(nstr);
}
