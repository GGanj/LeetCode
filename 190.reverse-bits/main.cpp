#include <iostream>

#include "reverse-bits.cpp"

int main() {
    Solution mySol;
    int n = 1;
    // n = n & 111;
    // std::cout << n << std::endl;
    int res = mySol.reverseBits(n);
    std::cout << res << std::endl;
    return 0;
}