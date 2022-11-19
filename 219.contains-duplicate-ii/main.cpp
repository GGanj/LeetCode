#include <iostream>

#include "contains-duplicate-ii.cpp"

int main() {
    Solution mySol;
    std::vector<int> nums = {1, 2, 3, 1, 2, 3};
    int k = 2;
    bool res = mySol.containsNearbyDuplicate(nums, k);
    std::cout << res << std::endl;
    return 0;
}