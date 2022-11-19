#include <iostream>

#include "plusOne.cpp"

int main() {
    Solution mySol;
    std::vector<int> nums = {9};
    std::vector<int> res = mySol.plusOne(nums);
    for(int i : res) {
        std::cout << i << " ";
    }
    std::cout << std::endl;
    return 0;
}