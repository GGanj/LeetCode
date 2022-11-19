#include <iostream>

#include "majority-element.cpp"

int main() {
    Solution mySol;
    std::vector<int> nums = {3, 3, 4};
    int res = mySol.majorityElement(nums);
    std::cout << res << std::endl;
    return 0;
}