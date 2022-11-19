#include <iostream>

#include ".\twoSum.cpp"
#include ".\otherSolution.cpp"

int main() {
    std::vector<int> input = {3, 2, 4}; 
    int target = 6;

    Solution bestSol;
    std::vector<int> result = bestSol.twoSum(input, target);
    for(int i = 0; i < result.size(); i++) {
        std::cout << result[i] << " ";
    }
    std::cout << std::endl;

    Solution2 otherSol2;
    otherSol2.twoSum(input, target);
    return 0;
}