#include <iostream>

#include "divide.cpp"

int main() {
    Solution mySol;
    int dividend = 10, divisor = 1;
    int res = mySol.divide(dividend, divisor);
    std::cout << res << std::endl;
    return 0;
}