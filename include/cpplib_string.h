/**
 * @brief - Implements string class.
 *
 * @author - Devendra Naga (devendra.aaru@outlook.com).
 * @copyright - 2022-present All rights reserved.
 */
#ifndef __CPPLIB_STRING_H__
#define __CPPLIB_STRING_H__

#include <stdio.h>

namespace cpplib {

/**
 * @brief - Implements String class
 */
class string {
    public:
        explicit string();
        explicit string(const char *str);
        string(const string &);
        ~string();

        /**
         * @brief - Get the length of string.
         *
         * @return returns length of string.
         */
        size_t len();

        /**
         * @brief - Append one string to another.
         *
         * @param[in] rhs - string of type string to append.
         *
         * @return string object.
         */
        string operator+(const string &rhs);

        /**
         * @brief - Append one string to another.
         *
         * @param[in] rhs - string of type const char * to append.
         *
         * @return string object.
         */
        string operator+(const char *rhs);

        /**
         * @brief - Compare two strings.
         *
         * @param[in] rhs - string to compare.
         *
         * @return true if both strings are same, false if not same.
         */
        bool operator==(const string &rhs);

        /**
         * @brief - Assign one string to another.
         *
         * @param[in] rhs - string to assign.
         *
         * @return string object.
         */
        string operator=(const string &rhs);

        /**
         * @brief - Get C String (const char *)
         *
         * @return C string returned
         */
        const char *c_str() { return (const char *)ptr_; }

    private:
        char *ptr_ = nullptr;
        int len_ = 0;
};

}

#endif

