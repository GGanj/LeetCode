#include <iostream>

#include "romanToInt.cpp"

int main() {
    Solution mySol;
    std::string s = "MCMXCIV";
    int res = mySol.romanToInt(s);
    std::cout << res << std::endl;
    return 0;
}