#include <stdio.h>
#include "test_header.h"

int main()
{
    int ret;

    ret = test_stack();
    ret = test_helpers();
    ret = test_cpplib_string();
    ret = test_array();
    ret = test_vector();

    return ret;
}

