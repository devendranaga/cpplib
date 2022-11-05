#include <functional>
#include <cpplib_thread.h>

namespace cpplib {

thread::~thread()
{
}

template <typename T1, typename T2>
int create(std::functional<T1(T2)> fn)
{
}

}

