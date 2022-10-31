#include <iostream>
#include "cpplib_stack.h"

int test_stack()
{
    cpplib::stack<int> ints;

    ints.push(4);
    ints.push(3);
    ints.push(2);
    ints.push(6);
    ints.push(8);
    ints.push(7);

    printf("length %d\n", ints.len());
    while (!ints.empty()) {
        int *data = ints.top();
        printf("data %d\n", *data);
        ints.pop();
    }

    return 0;
}

