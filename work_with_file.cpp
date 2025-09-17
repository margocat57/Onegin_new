#include <sys/stat.h>
#include <sys/types.h>
#include <unistd.h>
#include <assert.h>
#include <stdio.h>
#include <stdlib.h>
#include <errno.h>
#include "structures_consts.h"

file_in_array read_file_to_string_array(const char *name_of_file)
{
    assert(name_of_file != NULL);
    file_in_array fptr_in_array = {};
    FILE *fptr = fopen(name_of_file, "r");
    assert(fptr != NULL);

    struct stat file_info;
    if (stat(name_of_file, &file_info) == -1)
    {
        perror("Stat error");
        fprintf(stderr, "Error code: %d\n", errno);
        exit(EXIT_FAILURE);
    }

    char *all_strings_in_file = (char *)calloc(file_info.st_size + 1, sizeof(char));
    assert(all_strings_in_file != NULL);
    fread(all_strings_in_file, sizeof(char), file_info.st_size, fptr);

    char *search_ptr = all_strings_in_file;

    int nmb_of_str = 1;

    while ((search_ptr = strchr(search_ptr, '\n')) != NULL)
    {
        nmb_of_str++;
        *(search_ptr) = '\0';
        search_ptr++;
    }

    fptr_in_array.amount_str = nmb_of_str;
    fptr_in_array.all_strings_in_file = all_strings_in_file;

    fclose(fptr);
    return fptr_in_array;
}

void put_sorted_onegin_to_file(const char *name_of_file, ptr_array_and_size_of_strings *arr, const size_t *amount_str)
{
    assert(arr != NULL);
    assert(name_of_file != NULL);

    FILE *fptr = fopen(name_of_file, "a+");
    assert(fptr != NULL);

    for (int string = 0; string < *amount_str; string++)
    {
        if (arr[string].ptr[0] != '\0' || arr[string].ptr[0] != '\n')
        {
            fputs(arr[string].ptr, fptr);
            fputs("\n", fptr);
        }
    }
    fputs("\n", fptr);
    fclose(fptr);
}
// Функция для проверки что символы не пробельные