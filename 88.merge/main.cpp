#include <iostream>

#include "merge.cpp"

int main() {
    Solution mySol;
    std::vector<int> nums1 = {3, 0, 0};
    int m = 1;
    std::vector<int> nums2 = {1, 2};
    int n = 2;
    mySol.merge(nums1, m, nums2, n);
    for(int i : nums1) {
        std::cout << i << " ";
    }
    std::cout << std::endl;
    return 0;
}