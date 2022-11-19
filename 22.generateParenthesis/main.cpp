#include <iostream>

#include "generateParenthesis.cpp"

int main() {
    Solution mySol;
    int n = 3;
    std::vector<std::string> res = mySol.generateParenthesis(n);
    for(std::string item: res) {
        std::cout << item << std::endl;
    }
    return 0;
}