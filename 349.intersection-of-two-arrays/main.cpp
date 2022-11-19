#include <iostream>

#include "intersection-of-two-arrays.cpp"

int main() {
    Solution mySol;
    std::vector<int> n1 = {1, 2, 2, 1}, n2 = {2, 2};
    std::vector<int> res = mySol.intersection(n1, n2);
    for(int i : res) {
        std::cout << i << " ";
    }
    std::cout << std::endl;
    return 0;
}