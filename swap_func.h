//! @file
#ifndef SWAP_FUNC_H
#define SWAP_FUNC_H
#include <stdlib.h>

//! This function exchanges the values of two size_t variables.
//! In the context of sorting onegin, when we swap string pointers
//!     in the structure array, we must also swap their corresponding sizes to maintain
//!     consistency between each pointer and its associated string length.
//!
//! @warning Function uses assert for all pointers
void swap_size(size_t *size1, size_t *size2);

//! @warning Function uses assert for all pointers
void swap_pointers(char **str1, char **str2);

#endif // SWAP_FUNC_H