/*
** EPITECH PROJECT, 2022
** My_system header
** File description:
** Contains homemade system-oriented function prototypes
*/

#ifndef MY_SYSTEM_H_
    #define MY_SYSTEM_H_

    #include <stdbool.h>

typedef int fd_t;

/// @brief Structure representing a textfile and its content
//
/// @param filename The name of the file (heap-allocated)
/// @param extension Extension of the file
/// @param content Text content of the file
/// @param filesize Size of the file
typedef struct {
    // Name of the file, heap-allocated string
    char *filename;

    // Extension of the file:
    //  - NULL if no `'.'` is found in the filename,
    //
    // Otherwise points to the byte following the last `'.'` found
    // Thus:
    //  - Empty string if filename ends with `'.'`
    //  - Actual extension with the `'.'` ommitted
    //
    // This pointer must not be freed, since it points to the filename's block
    char *extension;

    // Raw content of the file, should always be non-null
    // on a valid instance of this `file_t` structure
    char *content;

    // Size of the file (in bytes)
    long filesize;

} file_t;

// Returns the size (in bytes) of a given file whose filepath is known
long my_get_file_size(char const *filepath);


// Function to read from a file which already has a open file descriptor
// Returns a heap-allocated buffer containing the file's content, or NULL
char *read_from_fd(fd_t to_read, long filesize);


// Will always perform a read on `buffer->filename`
// - On error, no write is performed on `buffer`, and EXIT_FAILURE is returned
// - On success `buffer->filesize` and `buffer->content` are written and
// EXIT_SUCCESS is returned
bool read_file(file_t *buffer);


#endif /* !MY_SYSTEM_H_ */
