/**
 * @brief - Implements an Array.
 *
 * @author - Devendra Naga (devendra.aaru@outlook.com).
 * @copyright - 2022-present All rights reserved.
 */
#ifndef __CPPLIB_ARRAY_H__
#define __CPPLIB_ARRAY_H__

namespace cpplib {

/**
 * @brief - Implements Array class
 */
template <class T, size_t N>
class array {
    public:

        /**
         * @brief - Set the element val at idx.
         *
         * @param[in] T - val of type T.
         * @param[in] size_t - index.
         */
        void set(T val, size_t idx) { array_[idx] = val; }

        /**
         * @brief - [] operator, used for doing C style array indexing.
         *
         * @param[in] size_t - index.
         * @return array value at given index idx.
         */
        T &operator[](size_t idx) { return array_[idx]; }

        /**
         * @brief - return the value of array at given idx.
         *
         * @return value of type T.
         */
        T at(size_t idx) { return array_[idx]; }

        /**
         * @brief - clear the array.
         */
        void clear() {
            for (size_t idx = 0; idx < N; idx ++) {
                array_[idx] = 0;
            }
        }

        /**
         * @brief - Return the size of array.
         *
         * @return returns the size of array.
         */
        size_t size() { return N; }

    private:
        /* defines the C style array */
        T array_[N];
};

}

#endif

