#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <assert.h>
#include "structures_consts.h"
#include "swap_string.h"
#include "ptr_func2.h"
#include "cmd_ln_args.h"
#include "work_with_file.h"

int main(int argc, char **argv)
{
    whete_put_sorted_onegin(argc, argv, PTR_FILE_NM);
    file_in_array info = read_file_to_string_array("textonegin.txt");

    pointer_and_string_size *x = create_ptr_array(&info);

    /*
    for (int i = 0; i < info.amount_str; i++)
    {
        printf("ptr = %p\n", x[i].ptr);
        printf("str = %s\n", x[i].ptr);
        printf("len = %lu\n", x[i].str_size);
    }*/

    sort_array_set_by_ptr2arr(x, &(info.amount_str), check_strings_for_sort_from_start);
    put_sorted_by_ptr2arr_onegin_to_file(FILE_NAME, x, &info);

    sort_array_set_by_ptr2arr(x, &(info.amount_str), check_strings_for_sort_from_end);
    put_sorted_by_ptr2arr_onegin_to_file(FILE_NAME, x, &info);

    qsort(x, info.amount_str, sizeof(x[0]), compare_address);
    put_sorted_by_ptr2arr_onegin_to_file(FILE_NAME, x, &info);

    free_memory(x, &info);

    return 0;
}

// ./ptr_array2