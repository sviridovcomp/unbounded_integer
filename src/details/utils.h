#ifndef UNBOUNDED_INTEGER_UTILS_H
#define UNBOUNDED_INTEGER_UTILS_H

#include <string_view>

namespace details {
    template <typename Number, std::enable_if_t<std::is_integral<Number>::value> = true>
    Number to_integer(std::string_view other) {
        auto value = 0;

        if (auto [pointer, err] = std::from_chars(other.begin(), other.end(), value); err == std::errc{}) {
            return value;
        }
        return 0;
    }
}

#endif //UNBOUNDED_INTEGER_UTILS_H
