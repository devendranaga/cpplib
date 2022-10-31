#include <stdio.h>
#include <stdlib.h>
#include <cpplib_stack.h>

namespace cpplib {

template <typename T>
stack<T>::stack()
{
    s_head_ = NULL;
    len_ = 0;
}

template <typename T>
int stack<T>::push(T item)
{
    stack_internal *new_elem;

    new_elem = (stack_internal *)calloc(1, sizeof(stack_internal));
    if (!new_elem) {
        return -1;
    }

    new_elem->data = (T *)calloc(1, sizeof(T));
    if (!new_elem->data) {
        free(new_elem);
        return -1;
    }

    *(new_elem->data) = item;

    // First element of the stack
    if (!s_head_) {
        s_head_ = new_elem;
    } else {
        //
        // Move the head and make new as head
        //
        // (new) -> (head) -> elem -> NULL
        // (head) -> (old_head) -> elem -> NULL
        new_elem->next = s_head_;
        s_head_ = new_elem;
    }

    len_ ++;

    return 0;
}

template<typename T>
void stack<T>::pop()
{
    if (s_head_ == NULL) {
        return;
    }

    stack_internal *tmp;

    tmp = s_head_->next;
    free(s_head_->data);
    free(s_head_);
    s_head_ = tmp;
    len_ --;
}

template <typename T>
T *stack<T>::top()
{
    if (s_head_ == NULL) {
        return NULL;
    }

    return s_head_->data;
}

template <typename T>
stack<T>::~stack()
{
    stack_internal *t = s_head_;

    while (s_head_ != NULL) {
        t = s_head_;
        s_head_ = s_head_->next;
        free(t->data);
        free(t);
    }
}

template class stack<int>;
template class stack<float>;

}

