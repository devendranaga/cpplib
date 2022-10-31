#ifndef __CPPLIB_LISTS_H__
#define __CPPLIB_LISTS_H__

namespace cpplib {

template <typename T>
class linked_list {
    public:
        explicit linked_list();
        ~linked_list();

        void add(T &data);

    private:
        struct node {
            T *data;
            node *next;
        };

        node *head_;
        node *tail_;
};

}

#endif

