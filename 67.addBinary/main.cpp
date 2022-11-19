#include <iostream>

#include "addBinary.cpp"

int main() {
    Solution mySol;
    std::string s1 = "1010", s2 = "1011";
    std::string res = mySol.addBinary(s1, s2);
    std::cout << res << std::endl;
    return 0;
}