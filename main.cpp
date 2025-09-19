#include <stdlib.h>
#include <string.h>
#include <assert.h>
#include "structures_consts.h"
#include "cmd_ln_args.h"
#include "work_with_file.h"
#include "functions_for_sort.h"

int main(int argc, const char *const *const argv)
{
    where_put_sorted_onegin(argc, argv, PTR_FILE_NM);
    file_in_array info = read_file_to_string_array("textonegin.txt");
    if (!info.is_stat_err)
    {
        ptr_array_and_size_of_strings *array = create_ptr_array(&info);

        /* for (int i = 0; i < info.amount_str; i++)
        {
            printf("ptr = %p\n", x[i].ptr);
            printf("str = %s\n", x[i].ptr);
            printf("len = %lu\n", x[i].str_size);
        }*/

        // сортировка совместима с strcmp
        sort_array_set_by_ptr2arr(array, &(info.amount_str), compare_strings_from_beginning);
        put_sorted_onegin_to_file(FILE_NAME, array, &(info.amount_str));

        sort_array_set_by_ptr2arr(array, &(info.amount_str), compare_strings_reverse);
        put_sorted_onegin_to_file(FILE_NAME, array, &(info.amount_str));

        qsort(array, info.amount_str, sizeof(array[0]), compare_address);
        put_sorted_onegin_to_file(FILE_NAME, array, &(info.amount_str));

        put_buffer_to_file(FILE_NAME, &info);

        free_memory(array, &info);
    }

    return 0;
}

// ./onegin