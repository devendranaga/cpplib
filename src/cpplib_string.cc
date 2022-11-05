/**
 * @brief - Implements string class.
 *
 * @author - Devendra Naga (devendra.aaru@outlook.com).
 * @copyright - 2022-present All rights reserved.
 */
#include <stdlib.h>
#include <cpplib_string.h>
#include <cpplib_exception.h>

namespace cpplib {

// Fixed length to assign / allocate string
const size_t fixed_len = 1024;

/**
 * @brief - get the length of the string.
 */
static size_t get_length(const char *ptr)
{
    size_t len = 0;

    if (!ptr) {
        return len;
    }

    while (ptr[len] != '\0') {
        len ++;
    }

    return len;
}

/**
 * @brief - Copy one string to another.
 */
static int string_copy(char *dst, const char *src)
{
    int i;

    if (!src || !dst) {
        return -1;
    }

    for (i = 0; src[i] != '\0'; i ++) {
        dst[i] = src[i];
    }
    dst[i] = '\0';

    return i;
}

/**
 * @brief - Concatenate two strings.
 */
static int string_cat(char *dst, const char *src)
{
    int j = 0;
    int i = 0;

    for (i = 0; dst[i] != '\0'; i ++);

    for (; src[j] != '\0'; i ++, j ++) {
        dst[i] = src[j];
    }
    dst[i] = '\0';

    return i;
}

/**
 * @brief - Compare two strings.
 */
static int string_cmp(const char *src, const char *dst)
{
    int src_len = get_length(src);
    int dst_len = get_length(dst);
    int i;

    if (src_len != dst_len) {
        return src_len - dst_len;
    }

    for (i = 0; i < src_len; i ++) {
        if (dst[i] != src[i]) {
            return src[i] - dst[i];
        }
    }

    return 0;
}

string string::operator+(const string &rhs)
{
    string s(ptr_);

    string_cat(s.ptr_, rhs.ptr_);
    return s;
}

string string::operator+(const char *rhs)
{
    string s(ptr_);

    string_cat(s.ptr_, rhs);
    return s;
}

bool string::operator==(const string &rhs)
{
    return (string_cmp(ptr_, rhs.ptr_) == 0);
}

/**
 * @brief - Allocate string pointer and set length to 0.
 *
 * allocation can fail so the constructor throws.
 */
string::string() : ptr_(nullptr), len_(0)
{
    if (!ptr_) {
        ptr_ = (char *)calloc(1, fixed_len);
        if (!ptr_) {
            throw memory_error("failed to allocate memory");
        }
    }
}

/**
 * @brief - Allocate and Copystring pointer and set length to 0.
 *
 * allocation can fail so the constructor throws.
 */
string::string(const char *str)
{
    len_ = get_length(str);
    if (len_ == 0) {
        throw runtime_error("string is invalid");
    }
    if (!ptr_) {
        ptr_ = (char *)calloc(1, fixed_len);
        if (!ptr_) {
            throw memory_error("failed to allocate memory");
        }
    }

    string_copy(ptr_, str);
}

/**
 * @brief - Allocate and Copystring pointer and set length to 0.
 *
 * allocation can fail so the constructor throws.
 */
string::string(const string &str)
{
    len_ = get_length(str.ptr_);
    if (len_ == 0) {
        throw runtime_error("string is invalid");
    }

    if (!ptr_) {
        ptr_ = (char *)calloc(1, fixed_len);
        if (!ptr_) {
            throw memory_error("failed to allocate memory");
        }
    }

    string_copy(ptr_, str.ptr_);
}

/**
 * @brief - Assign one string to another during `a=b` assignment.
 */
string string::operator=(const string &rhs)
{
    string_copy(this->ptr_, rhs.ptr_);
    return *this;
}

/**
 * @brief - Free underlying pointer
 */
string::~string()
{
    if (ptr_) {
        free(ptr_);
        ptr_ = nullptr;
    }
}

/**
 * @brief - Get the length of underlying pointer
 */
size_t string::len()
{
    return get_length(ptr_);
}

}

