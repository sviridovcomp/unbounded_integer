#include <gtest/gtest.h>
#include <unbounded_integer.h>
#include <sstream>

TEST(InitTest, UnboundedIntegerInitTests) {
    unbounded_integer init_by_int {4234234523554};
    unbounded_integer init_by_str {"10000000000000000000000000000000"};

    ASSERT_EQ((std::stringstream << init_by_int), 4234234523554)
}