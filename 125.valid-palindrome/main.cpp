#include <iostream>

#include "valid-palindrome.cpp"

int main() {
    std::cout << (int)'a' << std::endl;
    std::cout << (int)'z' << std::endl;
    std::cout << (int)'A' << std::endl;
    std::cout << (int)'Z' << std::endl;
    std::cout << (int)'0' << std::endl;
    std::cout << (int)'9' << std::endl;
    Solution mySol;
    std::string s = "0P";
    bool res = mySol.isPalindrome(s);
    std::cout << res << std::endl;
    return 0;
}