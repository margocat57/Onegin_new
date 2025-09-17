//! @file
#ifndef PTR_FUNC2_5_H
#define PTR_FUNC2_5_H
#include "structures_consts.h"

//! @brief Creates an array of pointer_and_string_size structures from file content
//!
//! This function processes a null-terminated array of strings and creates a parallel array
//!     each element of which containing pointers to each string and their sizes.
//! It uses strlen to find the len of each string and
//!     moves pointer to idx strlen+1 to find index of new string(except last string for not to be out of index)
//!
//! @return Pointer to allocated array of pointer_and_string_size structures
//!
//! @warning UNDEFINED BEHAVIOR if the source text contains empty strings in the middle.
//! @warning Function uses assert for pointer arr
//!
//! @note Memory allocated by this function must be freed by the caller
pointer_and_string_size *create_ptr_array(file_in_array *arr);

char my_tolower(char ch);

//! @warning Function uses assert for all pointers
int compare_address(const void *a, const void *b);

//! This function exchanges the values of two size_t variables.
//! In the context of sorting onegin, when we swap string pointers
//!     in the structure array, we must also swap their corresponding sizes to maintain
//!     consistency between each pointer and its associated string length.
//!
//! @warning Function uses assert for all pointers
void swap_size(size_t *size1, size_t *size2);

//! @warning Function uses assert for all pointers
void swap_pointers(char **str1, char **str2);

bool is_letter(char ch);

//! @brief Compares two strings in reverse lexicographical order
//!
//! Compares strings from end to start using letter-by-letter comparison.
//!
//! Starts comparison from the first letter character found from the end of each string.
//!
//! Continues comparison character-by-character including non-letter characters.
//!
//! @return Negative value if str1 < str2 in reverse order
//!         Zero if str1 == str2 in reverse order
//!         Positive value if str1 > str2 in reverse order
//!
//! @warning Function uses assert for all pointers
int compare_strings_reverse(const char *str1, const char *str2);

//! @brief Compares two strings in lexicographical order
//!
//! Compares strings using letter-by-letter comparison.
//!
//! Starts comparison from the first letter character found from the each string.
//!
//! Continues comparison character-by-character including non-letter characters.
//!
//! @return Negative value if str1 < str2
//!         Zero if str1 == str2
//!         Positive value if str1 > str2
//!
//! @warning Function uses assert for all pointers
int compare_strings_from_beginning(const char *str1, const char *str2);

//! Implements the shaker (cocktail) sort algorithm for an array of string pointers
//!
//! @param[in,out] arr Pointer to the array of pointer_and_string_size structures to be sorted
//! @param[in] strings Pointer to the number of strings in the array
//! @param[in] type_of_check_for_sort Function pointer to the custom comparison function
//!                                   that performs character-by-character comparison
//!
//! @note The comparison function in this task(sorting poem Eugene Onegin) implement either:
//!       - Forward character comparison (from start of string)
//!       - Reverse character comparison (from end of string)
//!
//! @warning Function uses assert for all pointers
void sort_array_set_by_ptr2arr(pointer_and_string_size *arr, const size_t *strings, int (*how_to_compare)(const char *, const char *));

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
void put_sorted_by_ptr2arr_onegin_to_file(const char *name_of_file, pointer_and_string_size *arr, const size_t *amount_str);

void free_memory(pointer_and_string_size *arr, file_in_array *array_for_size);

#endif // PTR_FUNC2_5_H