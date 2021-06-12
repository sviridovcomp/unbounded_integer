#include <iostream>

int main() {
    int a = 4294967296 * 2; // Overflow int.
    uint64_t b = 36893488000000000000000000; // Overflow uint64.
    std::cout << b << std::endl;
}