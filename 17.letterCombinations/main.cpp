#include <iostream>

#include "letterCombinations.cpp"

int main() {
    Solution mySol;
    std::string digits = "23";
    std::vector<std::string> res = mySol.letterCombinations(digits);
    for(std::string item : res) {
        std::cout << item << std::endl;
    }
    return 0;
}