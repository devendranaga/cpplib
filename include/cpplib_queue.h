/**
 * @brief - Implements Queue.
 *
 * @author - Devendra Naga (devendra.aaru@outlook.com).
 * @copyright - 2022-present All rights reserved.
 */
#ifndef __CPPLIB_QUEUE_H__
#define __CPPLIB_QUEUE_H__

#include <stdio.h>
#include <stdlib.h>

namespace cpplib {

template <typename T>
class queue {
    public:
        /**
         * @brief - Initialize queue.
         */
        explicit queue();
        ~queue() { clear_all(); }

        /**
         * @brief - Push an item to the queue.
         */
        int push(T item);

        /**
         * @brief - Return the data at the front of the queue.
         */
        T front() { return head_->data; }

        /**
         * @brief - Pop an element from the queue.
         */
        void pop() {
            if (head_) {
                node *t = head_;
                head_ = head_->next;
                free(t);
                len_ --;
            }

            if (head_ == NULL) {
                tail_ = NULL;
            }
        }

        /**
         * @brief - Return the length of the queue.
         *
         * @return length of the queue.
         */
        size_t len() { return len_; }

        /**
         * @brief - Check if the queue is empty
         *
         * @return true if queue is empty false if not.
         */
        bool empty() { return len_ == 0; }

        /**
         * @brief - Clear the queue.
         */
        void clear() { clear_all(); }

    private:
        /**
         * queue uses list to implement the abstraction
         */
        struct node {
            // actual data is stored here
            T data;
            node *next;
        };
        void clear_all();
        node *head_;
        node *tail_;
        size_t len_;
};

template <typename T>
queue<T>::queue() : head_(nullptr), tail_(nullptr), len_(0)
{ }

template <typename T>
void queue<T>::clear_all()
{
    node *t;
    /**
     * For each node .. delete the node and advance head.
     */
    while (head_) {
        t = head_;
        head_ = head_->next;
        free(t);
    }
    head_ = nullptr;
    tail_ = nullptr;
    len_ = 0;
}

/**
 * @brief - Push an element in to the queue.
 */
template <typename T>
int queue<T>::push(T item)
{
    node *n;

    n = (node *)calloc(1, sizeof(node));
    if (!n) {
        return -1;
    }

    n->data = item;

    if (!head_) {
        head_ = n;
        tail_ = n;
    } else {
        tail_->next = n;
        tail_ = n;
    }

    len_ ++;
    return 0;
}

}

#endif

