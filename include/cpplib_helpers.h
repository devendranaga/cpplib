/**
 * @brief - Implements a list of helper utilities
 *
 * @author - Devendra Naga (devendra.aaru@outlook.com)
 * @copyright - 2022-present All rights reserved
 */
#ifndef __CPPLIB_HELPERS_H__
#define __CPPLIB_HELPERS_H__

namespace cpplib {

template <typename T>
T min(T a, T b) { return a < b ? a : b; }

template <typename T>
T max(T a, T b) { return a > b ? a : b; }

}

#endif

