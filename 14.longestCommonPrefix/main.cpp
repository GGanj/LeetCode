#include <iostream>

#include "longestCommonPrefix.cpp"

int main() {
    Solution mySol;
    std::vector<std::string> s = {"flower","flow","flight"};
    std::string res = mySol.longestCommonPrefix(s);
    std::cout << res << std::endl;
    return 0;
}