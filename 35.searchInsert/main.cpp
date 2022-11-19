#include <iostream>

#include "searchInsert.cpp"

int main() {
    Solution mySol;
    std::vector<int> nums = {1, 3, 5, 6};
    int target = 7;
    int res = mySol.searchInsert(nums, target);
    std::cout << res << std::endl;
    return 0;
}