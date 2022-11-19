#include <iostream>

#include "threeSum.cpp"

int main() {
    Solution mySol;
    std::vector<int> nums = {-1,0,1,2,-1,-4};
    std::vector<std::vector<int>> res = mySol.threeSum(nums);
    for(std::vector<int> item : res) {
        for(int num : item) {
            std::cout << num << " ";
        }
        std::cout << std::endl;
    }
    return 0;
}