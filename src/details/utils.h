#ifndef UNBOUNDED_INTEGER_UTILS_H
#define UNBOUNDED_INTEGER_UTILS_H

#include <string_view>
#include <charconv>

namespace details {
    int32_t to_integer(std::string_view other) {
        auto value = 0;

        if (auto[pointer, err] = std::from_chars(other.begin(), other.end(), value); err == std::errc{}) {
            return value;
        }
        return 0;
    }
}

#endif //UNBOUNDED_INTEGER_UTILS_H
