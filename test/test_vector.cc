#include <cpplib_vector.h>

int test_vector()
{
    cpplib::vector<int> v;

    printf("testing vectors\n");

    v.push_back(3);
    v.push_back(1);
    v.push_back(2);
    v.push_back(5);
    v.push_back(6);

    cpplib::vector<int>::iterator it;

    for (it = v.begin(); it != v.end(); it ++) {
        if (*it == 2) {
            v.erase(it);
            break;
        }
        printf("item %d\n", *it);
    }

    it = v.begin();
    v.insert(it, 1);

    for (it = v.begin(); it != v.end(); it ++) {
        printf("item %d\n", *it);
    }
    return 0;
}

