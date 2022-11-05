#include <functional>

namespace cpplib {

class thread {
    public:
        explicit thread() = default;
        ~thread();

        template <typename T1, typename T2>
        int create(std::functional<T1(T2)> fn);
};

}

