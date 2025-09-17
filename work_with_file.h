//! @file
#ifndef WORK_WITH_FILE_H
#define WORK_WITH_FILE_H
#include "structures_consts.h"

//! @brief Reads a file and puts it's content into array
//!
//! The function reads all file's content into a buffer,
//!     created by using ^calloc function,
//!     replaces newline characters with null terminators,
//!     and counts the number of lines based on number of newline characters + 1
//!         (somestimes last string may not have newline character).
//!
//! ^Creates a buffer with 1 extra byte compared to the file size for safety
//!
//! @return file_in_array structure containing:
//!     - all_strings_in_file: pointer to buffer with file content (strings separated by '\0')
//!     - amount_str: number of lines in the file
//!
//! @note Allocated memory must be freed by the caller
//! @warning Function uses assert for pointer name_of_file
//! @warning Function checks file status using fstat to get file size in bytes.
//!          If fstat fails, error message is printed to stderr and program exit with EXIT_FAILURE
file_in_array read_file_to_string_array(const char *name_of_file);

//! Writes sorted Onegin lines to a file in append mode
//!
//! Appends sorted string array to the specified file using "a+" mode.
//!
//! The function preserves existing null terminators in strings and
//! adds newline characters at the end of each line.
//!
//! @note Skips empty strings (starting with '\0' or '\n')
//! @note Adds an extra newline at the end for separation
//!
//! @warning Function uses assert for all pointers
void put_sorted_onegin_to_file(const char *name_of_file, ptr_array_and_size_of_strings *arr, const size_t *amount_str);

#endif // WORK_WITH_FILE_H