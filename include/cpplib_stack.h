/**
 * @brief - Implements stack class
 *
 * @author - Devendra Naga (devendra.aaru@outlook.com)
 * @copyright - 2022-present All rights reserved
 */
#ifndef __CPPLIB_STACK_H__
#define __CPPLIB_STACK_H__

#include <stdio.h>

namespace cpplib {

/**
 * @brief - Implements stack class
 */
template <typename T>
class stack {
    public:
        explicit stack();
        ~stack();

        /**
         * @brief - Push an element T into the stack
         *
         * @param [in] data - data of type T
         *
         * @return 0 on success -1 on failure
         */
        int push(T data);

        /**
         * @brief - get the top element in the stack
         *
         * return - pointer to the top element
         */
        T *top();

        /**
         * @brief - remove an element from the stack
         */
        void pop();

        /**
         * @brief - get number of elements in the stack
         *
         * @return number of elements
         */
        size_t len() { return len_; }

        /**
         * @brief - check if stack is empty
         *
         * @return true if no elements are present
         * @return false if elements are present
         */
        bool empty() { return len_ == 0; }

    private:
        /**
         * @brief - internal structure that enclose the stack
         */
        struct stack_internal {
            // store the data of type T
            T *data;
            // pointer to the next element
            stack_internal *next;
        };

        // first element of the stack
        stack_internal *s_head_;

        // length of the stack
        size_t len_;
};

}

#endif

