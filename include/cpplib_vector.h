/**
 * @brief - Implements Vector.
 *
 * @author Devendra Naga (devendra.aaru@outlook.com).
 * @copyright 2022-present All rights reserved.
 */
#ifndef __CPPLIB_VECTOR_H__
#define __CPPLIB_VECTOR_H__

#include <stdio.h>
#include <stdlib.h>

namespace cpplib {

/**
 * @brief - Implements Vector.
 */
template <typename T>
class vector {
        struct node;
    public:
        explicit vector();
        ~vector();

        /**
         * @brief - Push an item in the Vector
         *
         * @param[in] T: item of type T
         *
         * @return 0 on success -1 on failure
         */
        int push_back(T item);

        /**
         * @brief - Get length of the Vector.
         *
         * @return size of the vector.
         */
        size_t len() { return len_; }

        /**
         * @brief - Check if Vector is empty.
         *
         * @return true if Vector is empty and false if not.
         */
        bool empty() { return len_ == 0; }

        /**
         * @brief - Clear the elements of a Vector.
         */
        void clear() { clear_all(); }

        /**
         * @brief - Implements Iterator for Vector.
         */
        class iterator {
            public:
                /**
                 * @brief - Initialize cur_ with nullptr.
                 */
                iterator() { cur_ = nullptr; }

                /**
                 * @brief - Set the cur node.
                 *
                 * @param[in] node: set the cur node with given node.
                 */
                iterator(node *n) { cur_ = n; }

                /**
                 * @brief - Implements it ++ increment operator.
                 *
                 * @return - Iterator.
                 */
                iterator operator++(int) {
                    if (cur_ != nullptr)
                        cur_ = cur_->next;
                    return *this;
                }

                /**
                 * @brief - Implements the *it deref operator.
                 *
                 * @return - Iterator.
                 */
                T operator*() { return cur_->item; }

                /**
                 * @brief - Iteartor destructor
                 */
                ~iterator() { cur_ = nullptr; }

                /**
                 * @brief - Implements it != end() operation.
                 *
                 * @param[in] iterator : value to be checked against the current
                 *                       class.
                 *
                 * @return true if it != rhs, false otherwise.
                 */
                bool operator!=(const iterator &rhs) { return cur_ != rhs.cur_; }

            private:
                /* Used by the Iterator and abstracts with iterator class. */
                node *cur_;
                /* Used as friend so that iterator private members can be
                 * accessed by the vector.
                 */
                friend vector;
        };

        /**
         * @brief - Implements the it.begin() operation.
         *
         * @details - set the iterator->cur_ to vector->head_; for iterating
         * purpose.
         *
         * @return iterator type.
         */
        iterator begin() { return iterator(head_); }

        /**
         * @brief - Implements the it.end() operation.
         *
         * @details - set the iterator cur to null and return a copy of the
         * iterator.
         *
         * @return iterator type.
         */
        iterator end() { return iterator(nullptr); }

        /**
         * @brief - Erase the particular item in the Vector.
         *
         * @param[in] iterator - element in the vector
         */
        void erase(iterator &it) {
            /**
             * Clear the node if its head.
             */
            if (head_ == it.cur_) {
                if (tail_ == head_) {
                    tail_ = nullptr;
                }
                head_ = head_->next;
                head_->prev = nullptr;
                free(it.cur_);
            } else {
                /**
                 * point the previous of current pointer to the next.
                 */
                it.cur_->prev->next = it.cur_->next;
                free(it.cur_);
            }
            len_ --;
        }
    private:
        /**
         * @brief - Defines the underlying doubly linked list.
         */
        struct node {
            /* Defines an abstract type */
            T item;

            /* Previous pointer */
            node *prev;

            /* Next pointer */
            node *next;
        };

        node *head_;
        node *tail_;
        size_t len_;
        void clear_all();
};

/**
 * Clear the head_, tail_ and len_
 */
template <typename T>
vector<T>::vector(): head_(nullptr), tail_(nullptr), len_(0)
{ }

template <typename T>
void vector<T>::clear_all()
{
   node *tmp = head_;

    /* For each element in the list */
    while (head_) {
        head_ = head_->next;
        /* free up the tmp and let head advance */
        free(tmp);
        tmp = head_;
    }

    head_ = nullptr;
    tail_ = nullptr;

    len_ = 0;
}

template <typename T>
vector<T>::~vector()
{
    clear_all();
}

template <typename T>
int vector<T>::push_back(T item)
{
    node *n = (node *)calloc(1, sizeof(node));
    if (!n) {
        return -1;
    }

    n->item = item;
    /* If its a new head then make tail and head points to each other
     * i.e tail->prev = head; and head->next = tail;
     */
    if (!head_) {
        head_ = n;
        tail_ = n;
        tail_->prev = head_;
        head_->next = tail_;
    } else {
        /* add an element at the end in O(1) operation, by adding an element at
         * the end of the tail.
         */
        n->prev = tail_;
        tail_->next = n;
        tail_ = n;
    }

    len_ ++;

    return 0;
}

}

#endif

