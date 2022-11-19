#include <iostream>

#include "isMatch.cpp"

int main() {
    Solution mySol;
    std::string s1 = "mississippi";
    std::string s2 = "mis*is*p*.";
    bool res = mySol.isMatch(s1, s2);
    std::cout << res << std::endl;
    return 0;
}