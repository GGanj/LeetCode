#include <iostream>

#include "longestPalindrome.cpp"

int main() {
    Solution mySol;
    std::string s = "cbbd";
    // std::string res = s.substr(1, 2);
    std::string res = mySol.longestPalindrome(s);

    std::cout << res << std::endl;
    return 0;
}