//! @file
#ifndef CMD_LN_ARGS_H
#define CMD_LN_ARGS_H

char *FILE_NAME = (char *)"onegin_ptr_sorted.txt";
char **PTR_FILE_NM = &FILE_NAME;

//! Finds and sets output file name from command line arguments
//!
//! Searches through command line arguments for a string containing ".txt" extension.
//! If found, sets the pointer to point to that filename for output operations.
//!
//! @note Searches for first occurrence of ".txt" in any argument
//! @note Only modifies the pointer if .txt file is found
//! @note Does not validate if the file actually exists or is accessible
//!
//! @warning Function uses assert for all pointers
void where_put_sorted_onegin(int argc, const char *const *const argv, char **ptrfile_to_put_results);

#endif // CMD_LN_ARGS_H