#include <iostream>
#include "binaryWatch.cpp"
int main() {
    Solution mySol;
    std::vector<std::string> res = mySol.readBinaryWatch(1);
    for(std::string item : res) {
        std::cout << item << std::endl;
    }
    return 0;
}