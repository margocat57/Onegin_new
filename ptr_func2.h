//! @file
#ifndef PTR_FUNC2_H
#define PTR_FUNC2_H
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
//!
//! @note Memory allocated by this function must be freed by the caller
pointer_and_string_size *create_ptr_array(file_in_array *arr);

char my_tolower(char ch);

int compare_address(const pointer_and_string_size *a, const pointer_and_string_size *b);

void swap_size(size_t *size1, size_t *size2);

void swap_pointers(char **str1, char **str2);

what_to_do what_do_with_letters(char letter1, char letter2);

size_t find_idx_of_first_letter_start(char *string, size_t size);

size_t find_idx_of_first_letter_end(char *string, size_t size);

void check_strings_for_sort_from_start(int str1_idx, int str2_idx, bool *is_elem_to_sort, pointer_and_string_size *arr);

void check_strings_for_sort_from_end(int str1_idx, int str2_idx, bool *is_elem_to_sort, pointer_and_string_size *arr);

void sort_array_set_by_ptr2arr(pointer_and_string_size *arr, const size_t *strings, void (*type_of_check_for_sort)(int, int, bool *, pointer_and_string_size *));

void put_sorted_by_ptr2arr_onegin_to_file(const char *name_of_file, pointer_and_string_size *arr, file_in_array *array_for_size);

void free_memory(pointer_and_string_size *arr, file_in_array *array_for_size);

#endif // PTR_FUNC2_H