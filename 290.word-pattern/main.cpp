#include <iostream>

#include "word-pattern.cpp"

int main() {
    Solution mySol;
    std::string pattern = "abba";
    std::string s = "dog cat cat dog";
    bool res = mySol.wordPattern(pattern, s);
    std::cout << res << std::endl;
    return 0;
}