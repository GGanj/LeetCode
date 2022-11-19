#include <iostream>

#include "implement-queue-using-stacks.cpp"

int main() {
    MyQueue myQ;
    myQ.push(1);
    myQ.push(2);
    std::cout << myQ.peek() << std::endl;
    std::cout << myQ.pop() << std::endl;
    std::cout << myQ.empty() << std::endl;
    return 0;
}