#ifndef UNBOUNDED_INTEGER_UNBOUNDED_INTEGER_H
#define UNBOUNDED_INTEGER_UNBOUNDED_INTEGER_H

#include <vector>
#include "details/utils.h"

class unbounded_integer {
public:
    unbounded_integer() = default;

    template<typename Number, std::enable_if_t<std::is_integral<Number>::value, bool> = true>
    unbounded_integer(Number value);

    unbounded_integer(std::string_view value);

    std::vector <int32_t> const data() const { return integer_storage_; }

    std::size_t digits_count() const { return digits_count_; }

    friend std::ostream &operator<<(std::ostream &os, unbounded_integer const &value) {
        for (auto i = 0; i < value.digits_count(); i++) {
            os << value.data()[i];
        }
        return os;
    }

private:
    std::vector <int32_t> integer_storage_;
    std::size_t digits_count_{0};
};

template<typename Number, std::enable_if_t<std::is_integral<Number>::value, bool>>
unbounded_integer::unbounded_integer(Number value) {
    for (auto i = value; i; i /= 10) {
        integer_storage_.push_back(i % 10);
        ++digits_count_;
    }

    std::reverse(integer_storage_.begin(), integer_storage_.end());
}

unbounded_integer::unbounded_integer(std::string_view value) {
    integer_storage_.clear();
    for (; !value.empty(); value.remove_prefix(1)) {
        integer_storage_.push_back(static_cast<int>(value.front()) - 48);
        ++digits_count_;
    }
}


#endif //UNBOUNDED_INTEGER_UNBOUNDED_INTEGER_H
