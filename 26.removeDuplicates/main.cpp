#include <iostream>

#include "removeDuplicates.cpp"

int main() {
    Solution mySol;
    std::vector<int> nums = {0,0,1,1,1,2,2,3,3,4};
    int res = mySol.removeDuplicates(nums);
    for(int i = 0; i < res; ++i) {
        std::cout << nums[i] << " ";
    }
    std::cout << std::endl;
    return 0;
}