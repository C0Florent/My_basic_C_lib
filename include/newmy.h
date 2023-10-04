/*
** EPITECH PROJECT, 2022
** Newmy.h
** File description:
** Header file for the newmy lib, cointaining
** reusable functions that are a bit
** more advanced than the classic my lib
** They turned out to be a bit more than 'a bit more' advanced
*/

#ifndef NEWMY_H_
    #define NEWMY_H_

/* BASIC INCLUDES */

    #include <sys/types.h>
    #include <stdbool.h>
    #include "coords_2d.h"



/* TEXT FORMAT MACROS */

    #define UNDERLINE(text) "\033[4m"text"\033[0m"



/* MATH MACROS */

    #define SIGN(x) (((x) == 0) ? 0 : (((x) < 0) ? (-1) : (1)))



/* STRUCTURES */

    #ifndef MY_LINKED_LIST_T
        #define MY_LINKED_LIST_T

// Linked list for int type only
typedef struct linked_list {
    int nb;
    struct linked_list *next;
} l_list_t;

    #endif /* MY_LINKED_LIST_T */


// Structure made for impish usage of strings,
// namely setting '\0' characters in the middle, while
// still wanting to access the characters beyond them
typedef struct impish_string_s {
    char *str;
    unsigned int strlen;
} imp_str_t;


// Length-based constant character string.
// The main idea is to get an equivalent for Rust's `&str` type, which
// is a fixed-length, immutable string which can be used to represent
// substrings of more generic strings.
//
// The string pointed to by `str` must be readable on at least `len`
// and may contain NUL bytes.
// Typical use case for this structure should be: getting read-only
// substrings of (potentially) heap-allocated strings instead of making a new
// allocation with strndup to get the substring, which would use more memory.
typedef struct string_slice {
    char const *str;
    size_t len;
} str_slice_t;


/* MISCELLANEOUS */

// Frees as many pointers as you wish in a single function call
void multi_free(unsigned int arg_count, ...);

// Returns the number of chars needed to write a given number in a given base
int my_get_nbrsize(unsigned long long nb, int base);

// Displays in hexadecimal the value of each individual byte
// of any variable, no matter its type
//
// Usage example: `show_dump(&my_var, sizeof(my_var));`
void show_dump(void *var_ptr, size_t var_size);

// Function to check if 2 variables of any type are equal, byte by byte
// Example usage: my_eq(&my_var1, &my_var2, sizeof(my_var1))
bool my_eq(void const *var1, void const *var2, size_t var_size);



/* NUMBER TOOLS */

// Prints on stdout any number up to long long size
int mega_put_nbr(long long nb, unsigned char base);

// Saves in a buffer any positive number, up to ~10E19
// Does not allocate nor checks if buffer is big enough, use cautiously
int mega_save_nbr(char *buf, unsigned long long nb, unsigned char base);





/* STRING TOOLS */


// Writes a string to standard output, and adds a trailing newline
void my_puts(char const *str);

// Writes a string to standard error
void my_putsterr(char const *str);

// Writes a string to any fd
int my_fdputs(char const *str, int fd);

// Searches for a pattern (needle) in a bigger string and returns the
// index corresponding to the starting point of the found pattern
//
// Returns -1 if the needle is not found
ssize_t my_strstr_pos(char const *haystack, char const *needle);

// Dupes the (at most) n first bytes of src and returns it
//
// If ever (strlen(src) < n): returned array still has an allocated space of n
// and the trailing allocated bytes will be set to null bytes
char *my_strndup(char const *src, unsigned int n);

//Returns true if str is made of only the chars listed in second arg
bool my_str_is_made_of(char const *str, char const *accepted_chars);

//Counts the occurencies of a given char in a given string
//If the goal is just to check if a character is present at all,
//rather use my_char_is_in_list, which will be faster
int count_occurencies(char const *tested_str, char to_count);

// Basic function for the imp_str_t structure,
// which just gets any regular string into an imp_str structure,
// so that it is ready for impish usage
// Only copies the pointer, without any allocation
imp_str_t *get_str_to_imp_str(char *str);



// Reads one line of given in file descriptor `fd` and stores it
// in `*lineptr`, reallocating it if need be, and accordingly setting
// `*bufsiz_ptr` to match the size of allocated buffer
//
// Return code: number of bytes read (positive or zero)
// Error codes (negative return codes):
// -1:  a call to `read()` returned -1 at any point
// -84: invalid arguments
// -42: allocation error occurred during execution
ssize_t my_fdgetline(char **lineptr, size_t *bufsiz_ptr, int fd);

// Same as my_fdgetline, except that the delimitor may be other than newline,
// as specified in the `delim` argument
ssize_t my_fdgetdelim(char **lineptr, size_t *bufsiz_ptr, char delim, int fd);

// The same as my_fdgetdelim, except there can be several delimitor characters.
// The read will stop at the when a character that appears in `delims` is read.
ssize_t my_fdgetdelims(char **lineptr, size_t *bufsiz_ptr,
    char const *delims, int fd);



/* STRING ARRAY TOOLS */

// Returns the number of consecutive non-NULL strings from the start of arr
unsigned int my_str_array_size(char *const *arr);

// Concatenates an strdup of src at the end of arr,
// and sets arr's next str to NULL
void my_str_array_cat(char const *src, char **arr);

//Counts the occurencies of c in the char **arr
int count_arr_occurencies(char c, char *const *arr);

// Sorts in ascending ascii order (bubble sort)
int my_sort_str_array(char **arr);

// Copies the strings of a word array into a new one
// Only copies pointers, without any new allocation
char **my_str_array_copy(char **src, char **dest);

// Name is as explicit as could be.
// Returns newly allocated str array on success, NULL otherwise
char **my_str_array_dup(char *const *arr);

// Separates replaces all delimitors of `src` with '\0'
// Takes the chars from `list` as separators if `valid` is false,
// or takes all characters except those listed in `list` if valid is true
char **ult_str_to_str_array(char *src, char const *list, bool valid);



/* LINKED LISTS */

// Allocs a new node to a l_list_t, and puts it at the beginning of
// the list, then returns the new node, which is the new first element
// Error: if malloc fails, the function returns the list unchanged
l_list_t *alloc_new_node(l_list_t *list, int new_value);

// Frees a l_list_t, element by element
void free_l_list_t(l_list_t *list);

#endif /* !NEWMY_H_ */
