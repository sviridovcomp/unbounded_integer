#ifndef UNBOUNDED_INTEGER_UNBOUNDED_INTEGER_H
#define UNBOUNDED_INTEGER_UNBOUNDED_INTEGER_H

#include <vector>
#include "details/utils.h"

template<std::size_t DigitsCount = 1024>
class unbounded_integer {
public:
    unbounded_integer() {
        integer_storage_.reserve(DigitsCount);
    }

    template<typename Number, std::enable_if_t<std::is_integral<Number>::value, bool> = true>
    unbounded_integer(Number value);

    unbounded_integer(std::string_view value);

private:
    std::vector<int> integer_storage_;
};

template<std::size_t DigitsCount>
template<typename Number, std::enable_if_t<std::is_integral<Number>::value, bool>>
unbounded_integer<DigitsCount>::unbounded_integer(Number value) {
    for (auto i = value; i; i /= 10) {
        integer_storage_.push_back(i);
    }
    integer_storage_.reserve();
}

template<std::size_t DigitsCount>
unbounded_integer<DigitsCount>::unbounded_integer(std::string_view value) {
}


#endif //UNBOUNDED_INTEGER_UNBOUNDED_INTEGER_H
