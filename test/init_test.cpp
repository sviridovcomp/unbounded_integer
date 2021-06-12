#include <gtest/gtest.h>
#include <unbounded_integer.h>
#include <vector>

TEST(InitTest, UnboundedIntegerInitTests) {
    unbounded_integer init_by_int {4234234523554};
    std::vector<int32_t> init_by_int_test {4, 2, 3, 4, 2, 3, 4, 5, 2, 3, 5, 5, 4};
    unbounded_integer init_by_str {"10000000000000000000000000000000"};

    ASSERT_TRUE(init_by_int.data(), init_by_int_test);
}