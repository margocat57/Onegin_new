#include <sys/stat.h>
#include <sys/types.h>
#include <unistd.h>
#include <assert.h>
#include <stdio.h>
#include <stdlib.h>
#include "structures_consts.h"

file_in_array read_file_to_string_array(const char *name_of_file)
{
    assert(name_of_file != NULL);
    file_in_array fptr_in_array = {};
    FILE *fptr = fopen(name_of_file, "r");
    assert(fptr != NULL);

    struct stat file_info;
    stat(name_of_file, &file_info);

    char *all_strings_in_file = (char *)calloc(file_info.st_size + 1, sizeof(char));
    assert(all_strings_in_file != NULL);
    fread(all_strings_in_file, sizeof(char), file_info.st_size, fptr);

    char *search_ptr = all_strings_in_file;
    char *ptr = NULL;

    int nmb_of_str = 1;

    while ((ptr = strchr(search_ptr, '\n')) != NULL)
    {
        nmb_of_str++;
        search_ptr = ptr + 1;
        *(search_ptr - 1) = '\0';
    }

    fptr_in_array.amount_str = nmb_of_str;
    fptr_in_array.all_strings_in_file = all_strings_in_file;
    // printf("how_many_strings = %lu\n", fptr_in_array.amount_str);

    fclose(fptr);
    return fptr_in_array;
}