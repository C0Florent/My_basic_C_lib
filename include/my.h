/*
** EPITECH PROJECT, 2022
** My functions prototyped
** File description:
** Contains the prototypes of all functions from mylib
*/

#ifndef MACRO_ABS
    #define MACRO_ABS

    #define ABS(value) (((value) >= 0) ? (value) : (-(value)))

#endif /*MACRO_ABS*/

#ifndef PROTOTYPES
    #define PROTOTYPES

    #include <stdbool.h>

void my_putchar(char c);
int my_put_nbr(int n);
void my_swap(int *n1, int *n2);
int my_putstr(char const *str);
int my_strlen(char const *str);

int my_getnbr(char const *str);
int sign_counter(char const *str, int *sign);
int read_nbr(char const *str, int i, int sign);
int add_if_possib(int *curr_value, int new_term, int sign);

void my_sort_int_array(int *, int);
int my_compute_power_rec(int b, int p);
int my_compute_square_root(int n);
int my_is_prime(int n);
int sqrt_roundup(int nb);
int my_find_prime_sup(int n);
char *my_strcpy(char *dest, char const *src);
char *my_strncpy(char *dest, char const *src, int n);
char *my_revstr(char *str);
char *my_strstr(char *str, char const *to_find);
int my_strcmp(char const *str1, char const *str2);
int my_strncmp(char const *str1, char const *str2, int n);
char *my_strupcase(char *str);
char my_char_upcase(char *c);
char *my_strlowcase(char *str);
char my_charlowcase(char *c);
char *my_strcapitalize(char *str);
int my_str_isalpha(char const *str);
int my_str_isnum(char const *str);
int my_char_isnum(char c);
int my_str_islower(char const *str);
int my_str_isupper(char const *str);
int my_str_isprintable(char const *str);
int my_charcat(char *dest, char c);
char *my_strcat(char *dest, char const *src);
char *my_strncat(char *dest, char const *src, int n);
int my_char_isalpha(char c);
int my_show_word_array(char * const *tab);
char **my_str_to_word_array(char const *str);
char *concat_params(int argc, char **argv);
int my_str_initialise(char *str, int size);

// If given a positive shift, this function will move byte by
// byte each character of the string by `shift` bytes forwards, and
// reset the first `shift` characters of the string to NUL bytes
//
// If given a negative shift, it this function will essentially overwrite
// the first `shift` bytes of the string with what is written afterwards
// my_shift_str(str, -n) sort of perfors the same as strcpy(str, str + n),
// but it's the intended use case (doing it w/ strcpy is undefined behaviour)
int my_shift_str(char *str, int shift);
bool my_char_is_in_list(char c, char const *str);

char *my_strdup(char const *str);

double my_compute_float_power(double nb, int power);

#endif /*PROTOTYPES*/
