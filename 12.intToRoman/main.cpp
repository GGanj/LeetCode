#include <iostream>

#include "intToRoman.cpp"

int main() {
    Solution mySol;
    int x = 1994;
    std::string res = mySol.intToRoman(x);
    std::cout << res << std::endl;
    return 0;
}