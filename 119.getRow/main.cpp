#include <iostream>

#include "getRow.cpp"

int main() {
    Solution mySol;
    std::vector<int> res = mySol.getRow(3);
    for(int i : res) {
        std::cout << i << " ";
    }
    std::cout << std::endl;
    return 0;
}