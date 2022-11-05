#include <stdio.h>
#include <cpplib_helpers.h>

int test_helpers()
{
    int val = cpplib::min(1, 2);
    int val_2  = cpplib::max(1, 2);

    printf("min %d max %d\n", val, val_2);

    return 0;
}

