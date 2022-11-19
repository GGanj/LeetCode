#include <iostream>

#include "maxProfit.cpp"

int main() {
    Solution mySol;
    std::vector<int> prices = {1, 2, 1, 2, 1, 2};
    int res = mySol.maxProfit(prices);
    std::cout << res << std::endl;
    return 0;
}