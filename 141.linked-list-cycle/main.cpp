#include <iostream>

#include "linked-list-cycle.cpp"

int main() {
    Solution mySol;
    ListNode l1(1);
    ListNode l2(2);
    ListNode l3(3);
    l1.next = &l2;
    l2.next = &l3;
    bool res = mySol.hasCycle(&l1);
    std::cout << res << std::endl;
    return 0;
}