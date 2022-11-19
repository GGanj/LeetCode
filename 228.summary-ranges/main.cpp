#include <iostream>

#include "summary-ranges.cpp"

int main() {
    Solution mySol;
    std::vector<int> nums = {0,2,3,4,6,8,9};
    std::vector<std::string> res = mySol.summaryRanges(nums);
    for(std::string i : res) {
        std::cout << i << std::endl;
    }
    std::cout << std::endl;
    return 0;
}