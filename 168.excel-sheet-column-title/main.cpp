#include <iostream>

#include "excel-sheet-column-title.cpp"

int main() {
    Solution mySol;
    int i = 676;
    std::string res = mySol.convertToTitle(i);
    std::cout << res << std::endl;
    return 0;
}