#include <iostream>

#include "implement-stack-using-queues.cpp"

int main() {
    MyStack myStack;
    myStack.push(1);
    myStack.push(2);
    std::cout << myStack.top() << std::endl;
    std::cout << myStack.pop() << std::endl;
    std::cout << myStack.pop() << std::endl;
    std::cout << myStack.empty() << std::endl;
    return 0;
}