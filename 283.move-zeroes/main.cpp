#include <iostream>

#include "move-zeroes.cpp"

int main() {
    Solution mySol;
    std::vector<int> nums = {1, 0};
    mySol.moveZeroes(nums);
    for(int i : nums) {
        std::cout << i << " ";
    }
    std::cout << std::endl;
    return 0;
}