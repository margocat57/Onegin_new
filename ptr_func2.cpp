#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <stdio.h>
#include <assert.h>
#include "structures_consts.h"

// очень важная проблема - после \n мы получаем адрес всей строчки до \0,
// а этого нам не хочется ведь нам хочется получить адрес строчки только до следующего \n
// TODO спросить у ментора про то как делать обработку пустых строк если они в середине текста
// TODO компаратор не void желательно

pointer_and_string_size *create_ptr_array(file_in_array *arr)
{
    assert(arr != NULL);
    pointer_and_string_size *arr_with_ptr_sz = (pointer_and_string_size *)calloc(arr->amount_str, sizeof(pointer_and_string_size));
    assert(arr_with_ptr_sz != NULL);

    size_t num_of_elem = 0;
    (arr_with_ptr_sz[num_of_elem]).ptr = arr->all_strings_in_file;
    num_of_elem = 1;

    char *search_ptr = arr->all_strings_in_file;
    // printf("amnt = %lu\n", arr->amount_str);

    for (num_of_elem = 1; num_of_elem <= arr->amount_str; num_of_elem++)
    {
        if (search_ptr[0] != '\0')
        {
            (arr_with_ptr_sz[num_of_elem - 1]).str_size = strlen(search_ptr) + 1;
            (arr_with_ptr_sz[num_of_elem]).ptr = search_ptr + strlen(search_ptr) + 1;
            if (num_of_elem != arr->amount_str)
                search_ptr += strlen(search_ptr) + 1 + 1;
        }
        // printf("elem = %lu, len = %lu\n", num_of_elem - 1, arr_with_ptr_sz[num_of_elem - 1].str_size);
    }

    return arr_with_ptr_sz;
}

int compare_address(const pointer_and_string_size *a, const pointer_and_string_size *b)
{
    assert(a != NULL);
    assert(b != NULL);

    if (a->ptr > b->ptr)
        return 1;
    if (a->ptr < b->ptr)
        return -1;
    return 0;
}

char my_tolower(char ch)
{
    return ('A' <= ch && ch <= 'Z') ? ch + 'a' - 'A' - 1 : ch;
}

void swap_size(size_t *size1, size_t *size2)
{
    assert(size1 != NULL);
    assert(size2 != NULL);

    size_t temp_size = *size1;
    *size1 = *size2;
    *size2 = temp_size;
}

void swap_pointers(char **str1, char **str2)
{
    assert(str1 != NULL);
    assert(*str1 != NULL);

    assert(str2 != NULL);
    assert(*str2 != NULL);

    char *temp = *str1;
    *str1 = *str2;
    *str2 = temp;
}

what_to_do what_do_with_letters(char letter1, char letter2)
{
    char letter1_lower = my_tolower(letter1);
    char letter2_lower = my_tolower(letter2);

    if (letter1_lower > letter2_lower)
    {
        return SWAP;
    }
    else if (letter1_lower == letter2_lower)
    {
        return CONTINUE;
    }
    return BREAK;
}

size_t find_idx_of_first_letter_start(char *string, size_t size)
{
    assert(string != NULL);

    for (size_t idx = 0; idx < size; idx++)
    {
        if (isalpha((string)[idx]))
        {
            return idx;
        }
    }
    return size;
}

size_t find_idx_of_first_letter_end(char *string, size_t size)
{
    assert(string != NULL);

    for (long int idx = size - 1; idx >= 0; idx--)
    {
        if (isalpha((string)[idx]))
        {
            return idx;
        }
    }
    return size;
}

void check_strings_for_sort_from_start(int str1_idx, int str2_idx, bool *is_elem_to_sort, pointer_and_string_size *arr)
{
    size_t idx_letter_str1 = find_idx_of_first_letter_start(arr[str1_idx].ptr, arr[str1_idx].str_size);
    size_t idx_letter_str2 = find_idx_of_first_letter_start(arr[str2_idx].ptr, arr[str2_idx].str_size);

    for (int elem1 = idx_letter_str1, elem2 = idx_letter_str2; elem1 < arr[str1_idx].str_size && elem2 < arr[str2_idx].str_size; elem1++, elem2++)
    {
        if (what_do_with_letters(arr[str1_idx].ptr[elem1], arr[str2_idx].ptr[elem2]) == SWAP)
        {
            swap_pointers(&arr[str1_idx].ptr, &arr[str2_idx].ptr);
            swap_size(&arr[str1_idx].str_size, &arr[str2_idx].str_size);
            *is_elem_to_sort = 1;
            return;
        }
        else if (what_do_with_letters(arr[str1_idx].ptr[elem1], arr[str2_idx].ptr[elem2]) == BREAK)
        {
            return;
        }
    }
}

void check_strings_for_sort_from_end(int str1_idx, int str2_idx, bool *is_elem_to_sort, pointer_and_string_size *arr)
{
    size_t idx_letter_str1 = find_idx_of_first_letter_end(arr[str1_idx].ptr, arr[str1_idx].str_size);
    size_t idx_letter_str2 = find_idx_of_first_letter_end(arr[str2_idx].ptr, arr[str2_idx].str_size);

    for (int elem1 = idx_letter_str1, elem2 = idx_letter_str2; elem1 >= 0 && elem2 >= 0; elem1--, elem2--)
    {
        if (what_do_with_letters(arr[str1_idx].ptr[elem1], arr[str2_idx].ptr[elem2]) == SWAP)
        {
            swap_pointers(&arr[str1_idx].ptr, &arr[str2_idx].ptr);
            swap_size(&arr[str1_idx].str_size, &arr[str2_idx].str_size);
            *is_elem_to_sort = 1;
            return;
        }
        else if (what_do_with_letters(arr[str1_idx].ptr[elem1], arr[str2_idx].ptr[elem2]) == BREAK)
        {
            return;
        }
    }
}

void sort_array_set_by_ptr2arr(pointer_and_string_size *arr, const size_t *strings, void (*type_of_check_for_sort)(int, int, bool *, pointer_and_string_size *))
{
    assert(arr != NULL);
    assert(arr->ptr != NULL);
    assert(strings != NULL);

    int left = 0, right = *strings - 1;
    bool is_elem_to_sort = 1;

    while (left < right && is_elem_to_sort)
    {
        is_elem_to_sort = 0;

        for (int string = left; string < right; string++)
        {
            type_of_check_for_sort(string, string + 1, &is_elem_to_sort, arr);
        }
        right--;

        for (int string = right; string > left; string--)
        {
            type_of_check_for_sort(string - 1, string, &is_elem_to_sort, arr);
        }
        left++;
    }
}

void put_sorted_by_ptr2arr_onegin_to_file(const char *name_of_file, pointer_and_string_size *arr, file_in_array *array_for_size)
{
    assert(arr != NULL);
    assert(name_of_file != NULL);
    assert(array_for_size != NULL);

    FILE *fptr = fopen(name_of_file, "a+");
    assert(fptr != NULL);

    for (int string = 0; string < array_for_size->amount_str; string++)
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

void free_memory(pointer_and_string_size *arr, file_in_array *array_for_size)
{
    assert(arr != NULL);
    assert(array_for_size != NULL);

    free(arr);
    free(array_for_size->all_strings_in_file);
}