#include <iostream>
// #include <vector>

#include "findMedianSortedArrays.cpp"
#include "otherSolution.cpp"

int main() {
    Solution2 mySol;
    std::vector<int> v1 = {1,1,1,1,1,1,1,1,1,1,4,4};
    std::vector<int> v2 = {1,3,4,4,4,4,4,4,4,4,4};
    double res = mySol.findMedianSortedArrays(v1, v2);
    std::cout << res << std::endl;
    return 0;
}