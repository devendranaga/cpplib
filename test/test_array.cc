#include <stdio.h>
#include "cpplib_array.h"

int test_array()
{
    cpplib::array<int, 6> a;

    a.clear();

    a[0] = 1;
    a[1] = 2;
    a[2] = 3;

    a.set(4, 3);
    for (size_t i = 0; i < a.size(); i ++) {
        printf("%d %d\n", a[i], a.at(i));
    }
    printf("%ju\n", a.size());

    return 0;
}

