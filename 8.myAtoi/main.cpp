#include <iostream>

#include "myAtoi.cpp"

int main() {
    Solution mySol;
    std::string s = "21474836460";
    int res = mySol.myAtoi(s);
    std::cout << res << std::endl;
    return 0;
}