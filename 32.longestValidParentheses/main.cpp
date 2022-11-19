#include <iostream>

#include "longestValidParentheses.cpp"

int main() {
    Solution mySol;
    std::string s = "()(()";
    int res = mySol.longestValidParentheses(s);
    std::cout << res << std::endl;
    return 0;
}