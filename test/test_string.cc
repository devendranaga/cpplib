#include <stdio.h>
#include "cpplib_string.h"

int test_cpplib_string()
{
    cpplib::string s("string");
    cpplib::string n  = s + " concatenation";
    cpplib::string a = n;
    cpplib::string o;

    o = a;

    printf("length: %lu data: %s\n", s.len(), s.c_str());
    printf("n length: %lu data: %s\n", n.len(), n.c_str());
    printf("a length: %lu data: %s\n", a.len(), a.c_str());
    printf("o length: %lu data: %s\n", o.len(), o.c_str());

    return 0;
}

