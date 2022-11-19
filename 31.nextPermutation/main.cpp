#include <iostream>

#include "nextPermutation.cpp"

int main() {
    Solution mySol;
    std::vector<int> nums = {1,3,2};
    mySol.nextPermutation(nums);
    for(int i : nums) {
        std::cout << i << " ";
    }
    std::cout << std::endl;
    return 0;
}