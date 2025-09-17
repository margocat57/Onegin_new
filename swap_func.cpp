#include <stdlib.h>
#include <assert.h>

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