#include <iostream>

#include "threeSumClosest.cpp"

int main() {
    Solution mySol;
    std::vector<int> nums = {4,-1,-4,4};
    int target = -1;
    int res = mySol.threeSumClosest(nums, target);
    std::cout << res << std::endl;
    return 0;
}