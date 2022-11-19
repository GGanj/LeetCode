#include <iostream>

#include "mySqrt.cpp"

int main() {
    Solution mySol;
    int n = 2147395599;
    int res = mySol.mySqrt(n);
    std::cout << res << std::endl;
    return 0;
}