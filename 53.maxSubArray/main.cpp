#include <iostream>

#include "maxSubArray.cpp"

int main() {
    Solution mySol;
    std::vector<int> nums = {-2,1,-3,4,-1,2,1,-5,4};
    int res = mySol.maxSubArray(nums);
    std::cout << res << std::endl;
    return 0;
}