#include <iostream>

#include "isValid.cpp"

int main() {
    Solution mySol;
    std::string str = "]";
    bool res = mySol.isValid(str);
    std::cout << res << std::endl;
    return 0;
}