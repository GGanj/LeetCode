#include <iostream>

#include "z-convert.cpp"

int main() {
    Solution mySol;
    std::string s = "A";
    int numRows = 1;
    std::string res = mySol.convert(s, numRows);
    std::cout << res << std::endl;
    return 0;
}