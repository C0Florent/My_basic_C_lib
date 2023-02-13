/*
** EPITECH PROJECT, 2023
** my_printf internal header
** File description:
** Contains function prototypes and structure declarations required
** for the internal operation of my_printf
*/

#ifndef MY_PRINTF_INTERNAL_H_
    #define MY_PRINTF_INTERNAL_H_

    #include <stdarg.h>
    #include <stdbool.h>


int my_save_nbr_rec(char *buf, unsigned long long nb,
                    unsigned char base, int *count);
int my_save_float_digits(double nb, int precision, char *buf);

typedef struct conversion_details {
    char conversion;
    int precision;
    bool is_alt_form;        /*either 0 or 1*/
    char len_modifier[2];
    int width;
    bool dash_flag;
    bool zero_flag;
    bool space_flag;
    bool plus_flag;
} conv_det_t;


typedef struct put_conv_ptr {
    int (*fptr)(conv_det_t *details, va_list *arguments);
    char conversion;
} put_conv_ptr_t;

typedef struct signed_length_redirector {
    long long(*fptr)(va_list *list);
    char len_modifier[2];
} signed_len_redir_t;

typedef struct unsigned_length_redirector {
    unsigned long long(*fptr)(va_list *list);
    char len_modifier[2];
} unsigned_len_redir_t;


void initialise_structure(conv_det_t *conv_struct);

void read_flag(conv_det_t *details, char flag_to_add);
void read_width(int *width, unsigned int *i, char const *conv, va_list *args);
void read_precision(int *precision, unsigned int *i,
    char const *conv, va_list *args);
void read_len_modifier(char *len_modifier, char const *conv);

void clean_struct(conv_det_t *structure);


int my_put_conv_i(conv_det_t *details, va_list *arguments);
int my_put_conv_u(conv_det_t *details, va_list *arguments);
int my_put_conv_b(conv_det_t *details, va_list *arguments);
int my_put_conv_o(conv_det_t *details, va_list *arguments);
int my_put_conv_x(conv_det_t *details, va_list *arguments);
int my_put_conv_p(conv_det_t *details, va_list *arguments);
int my_put_conv_f(conv_det_t *details, va_list *arguments);
int my_put_conv_e(conv_det_t *details, va_list *arguments);
int my_put_conv_g(conv_det_t *details, va_list *arguments);

int my_put_conv_c(conv_det_t *details, va_list *arguments);
int my_put_conv_s(conv_det_t *details, va_list *arguments);
int my_put_conv_percent(conv_det_t *details, va_list *arguments);

int redirect_to_right_conv(conv_det_t *details, va_list *arguments, int *count);

int my_get_nbrsize(unsigned long long nb, int base);
int my_float_int_part_size(double nb, int base);
int add_precision(char *nbr, int precision);
int fill_width_i(char *final_str, conv_det_t *details);
int fill_width_u(char *final_str, conv_det_t *details);
int fill_width_o(char *final_str, conv_det_t *details);
int fill_width_x(char *final_str, conv_det_t *details);
int my_get_di_core_size(long long nb, conv_det_t *details);
int my_get_di_total_size(long long nb, conv_det_t *details);
int my_get_u_total_size(unsigned long long nb, conv_det_t *details);
int my_get_o_total_size(unsigned long long nb, conv_det_t *details);
int my_get_x_total_size(unsigned long long nb, conv_det_t *details);
int my_get_f_total_size(double, conv_det_t *details);
int my_get_e_total_size(double, conv_det_t *details);
int read_conv(char *conv, conv_det_t *conv_details, va_list *args);
int show_details(conv_det_t *d);
int put_char_space (int nb);

long long redirect_signed(conv_det_t *details, va_list *list);
unsigned long long redirect_unsigned(conv_det_t *details, va_list *list);

long long next_arg_default_i(va_list *list);
unsigned long long next_arg_default_u(va_list *list);
long long next_arg_hhi(va_list *list);
unsigned long long next_arg_hhu(va_list *list);
long long next_arg_hi(va_list *list);
unsigned long long next_arg_hu(va_list *list);
long long next_arg_li(va_list *list);
unsigned long long next_arg_lu(va_list *list);
long long next_arg_lli(va_list *list);
unsigned long long next_arg_llu(va_list *list);
unsigned long long next_arg_void_star(va_list *list);


#endif /* !MY_PRINTF_INTERNAL_H_ */
