#include <iostream>

#include "strStr.cpp"

int main() {
    Solution mySol;
    std::string h = "hello";
    std::string n = "ll";
    int res = mySol.strStr(h, n);
    std::cout << res << std::endl;
    return 0;
}