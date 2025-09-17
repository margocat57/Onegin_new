#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <stdio.h>
#include <assert.h>
#include "structures_consts.h"
#include "swap_func.h"

// очень важная проблема - после \n мы получаем адрес всей строчки до \0,
// а этого нам не хочется ведь нам хочется получить адрес строчки только до следующего \n

ptr_array_and_size_of_strings *create_ptr_array(file_in_array *arr)
{
    assert(arr != NULL);
    ptr_array_and_size_of_strings *arr_with_ptr_sz = (ptr_array_and_size_of_strings *)calloc(arr->amount_str, sizeof(ptr_array_and_size_of_strings));
    assert(arr_with_ptr_sz != NULL);

    size_t num_of_elem = 0;
    (arr_with_ptr_sz[num_of_elem]).ptr = arr->all_strings_in_file;
    num_of_elem = 1;

    char *search_ptr = arr->all_strings_in_file;

    for (num_of_elem = 1; num_of_elem <= arr->amount_str; num_of_elem++)
    {
        (arr_with_ptr_sz[num_of_elem - 1]).str_size = strlen(search_ptr) + 1;
        (arr_with_ptr_sz[num_of_elem]).ptr = search_ptr + strlen(search_ptr) + 1;
        if (num_of_elem != arr->amount_str)
            search_ptr += strlen(search_ptr) + 1;
    }

    return arr_with_ptr_sz;
}

int compare_address(const void *a, const void *b)
{
    assert(a != NULL);
    assert(b != NULL);

    const ptr_array_and_size_of_strings *adress1 = (ptr_array_and_size_of_strings *)a;
    const ptr_array_and_size_of_strings *adress2 = (ptr_array_and_size_of_strings *)b;

    if (adress1->ptr > adress2->ptr)
        return 1;
    if (adress1->ptr < adress2->ptr)
        return -1;
    return 0;
}

char my_tolower(char ch)
{
    return ('A' <= ch && ch <= 'Z') ? ch + 'a' - 'A' - 1 : ch;
}

bool is_letter(char ch)
{
    return ((ch >= 'A' && ch <= 'Z') || (ch >= 'a' && ch <= 'z'));
}

int compare_strings_reverse(const char *str1, const char *str2)
{
    assert(str1 != NULL);
    assert(str2 != NULL);

    int idx1 = strlen(str1) - 1;
    int idx2 = strlen(str2) - 1;

    char char1 = '\0';
    char char2 = '\0';

    while (idx1 >= 0 && !is_letter(str1[idx1]))
        idx1--;
    while (idx2 >= 0 && !is_letter(str2[idx2]))
        idx2--;

    while (idx1 >= 0 && idx2 >= 0)
    {
        char1 = my_tolower(str1[idx1]);
        char2 = my_tolower(str2[idx2]);

        if (char1 != char2)
            return char1 - char2;

        idx1--;
        idx2--;
    }

    return idx1 - idx2;
}

int compare_strings_from_beginning(const char *str1, const char *str2)
{
    assert(str1 != NULL);
    assert(str2 != NULL);

    int idx1 = 0;
    int len1 = strlen(str1) - 1;

    int idx2 = 0;
    int len2 = strlen(str2) - 1;

    char char1 = '\0';
    char char2 = '\0';

    while (idx1 <= len1 && !is_letter(str1[idx1]))
        idx1++;
    while (idx2 <= len2 && !is_letter(str2[idx2]))
        idx2++;

    while (idx1 <= len1 - 1 && idx2 <= len2 - 1)
    {
        char1 = my_tolower(str1[idx1]);
        char2 = my_tolower(str2[idx2]);

        if (char1 != char2)
            return char1 - char2;

        idx1++;
        idx2++;
    }

    return len1 - len2;
}

void sort_array_set_by_ptr2arr(ptr_array_and_size_of_strings *arr, const size_t *strings, int (*how_to_compare)(const char *, const char *))
{
    assert(arr != NULL);
    assert(strings != NULL);

    int left = 0, right = *strings - 1;

    while (left < right)
    {

        for (int string = left; string < right; string++)
        {
            if (how_to_compare((const char *)arr[string].ptr,
                               (const char *)arr[string + 1].ptr) > 0)
            {
                swap_pointers(&arr[string].ptr, &arr[string + 1].ptr);
                swap_size(&arr[string].str_size, &arr[string + 1].str_size);
            }
        }
        right--;

        for (int string = right; string > left; string--)
        {
            if (how_to_compare((const char *)arr[string - 1].ptr,
                               (const char *)arr[string].ptr) > 0)
            {
                swap_pointers(&arr[string - 1].ptr, &arr[string].ptr);
                swap_size(&arr[string - 1].str_size, &arr[string].str_size);
            }
        }
        left++;
    }
}

void free_memory(ptr_array_and_size_of_strings *arr, file_in_array *array_for_size)
{
    assert(arr != NULL);
    assert(array_for_size != NULL);

    free(arr);
    free(array_for_size->all_strings_in_file);
}