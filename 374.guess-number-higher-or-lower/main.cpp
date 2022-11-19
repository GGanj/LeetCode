#include <iostream>

#include "guess-number-higher-or-lower.cpp"

int main() {
    Solution mySol;
    int n = 10;
    int res = mySol.guessNumber(n);
    std::cout << res << std::endl;
    return 0;
}