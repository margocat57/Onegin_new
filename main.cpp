#include <stdlib.h>
#include <string.h>
#include <assert.h>
#include "structures_consts.h"
// #include "swap_func.h"
#include "cmd_ln_args.h"
#include "work_with_file.h"
#include "functions_for_sort.h"

// const char* те указатели значения которых мы не меняем
// const char* const * const argv
int main(int argc, char **argv)
{
    where_put_sorted_onegin(argc, argv, PTR_FILE_NM);
    file_in_array info = read_file_to_string_array("debug.txt");

    ptr_array_and_size_of_strings *x = create_ptr_array(&info);

    /* for (int i = 0; i < info.amount_str; i++)
    {
        printf("ptr = %p\n", x[i].ptr);
        printf("str = %s\n", x[i].ptr);
        printf("len = %lu\n", x[i].str_size);
    }*/

    sort_array_set_by_ptr2arr(x, &(info.amount_str), compare_strings_from_beginning);
    put_sorted_onegin_to_file(FILE_NAME, x, &(info.amount_str));

    sort_array_set_by_ptr2arr(x, &(info.amount_str), compare_strings_reverse);
    put_sorted_onegin_to_file(FILE_NAME, x, &(info.amount_str));

    qsort(x, info.amount_str, sizeof(x[0]), compare_address);
    put_sorted_onegin_to_file(FILE_NAME, x, &(info.amount_str));

    free_memory(x, &info);

    return 0;
}

// ./ptr_array2