#include <iostream>

#include "fourSum.cpp"

int main() {
    Solution mySol;
    std::vector<int> nums = {1,0,-1,0,-2,2};
    int target = 0;
    std::vector<std::vector<int>> res = mySol.fourSum(nums, target);
    for(auto item : res) {
        for(auto digit : item) {
            std::cout << digit << " ";
        }
        std::cout << std::endl;
    }
    return 0;
}