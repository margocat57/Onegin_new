#include <string.h>
#include <stdlib.h>
#include "assert_without_ndebug.h"

void where_put_sorted_onegin(int argc, const char *const *const argv, char **ptrfile_to_put_results)
{
    MY_ASSERT_WTHOUT_NDEBUG(argv != NULL && *argv != NULL);
    MY_ASSERT_WTHOUT_NDEBUG(ptrfile_to_put_results != NULL && *ptrfile_to_put_results != NULL);

    for (size_t flg_idx = 0; flg_idx < argc; flg_idx++)
    {
        if (strstr(argv[flg_idx], ".txt") != NULL)
        {
            *ptrfile_to_put_results = (char *)argv[flg_idx];
        }
    }
}