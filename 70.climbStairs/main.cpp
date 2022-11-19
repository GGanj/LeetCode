#include <iostream>

#include "climbStairs.cpp"

int main() {
    Solution mySol;
    int n = 44;
    int res = mySol.climbStairs(n);
    std::cout << res << std::endl;
    return 0;
}