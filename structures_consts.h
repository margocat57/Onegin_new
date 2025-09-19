//! @file
#ifndef STRUCTURES_CONSTS_H
#define STRUCTURES_CONSTS_H

#include <string.h>

//! for pointer to start of string and len of string
struct ptr_array_and_size_of_strings
{
    size_t str_size; //!< size of string
    char *ptr;       //!< pointer for start of string
};

//! for containing array with all symbols of file and amount of strings
struct file_in_array
{
    size_t amount_str;         //!< quantity of strings
    char *all_strings_in_file; //!< array with all strings of file
    bool is_stat_err;          //!< is there error in stat function
};

#endif // STRUCTURES_CONSTS_H