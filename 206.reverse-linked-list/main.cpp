#include <iostream>

#include "reverse-linked-list.cpp"

int main() {
    Solution mySol;
    ListNode l1(1);
    ListNode l2(2);
    ListNode l3(3);
    ListNode l4(4);
    ListNode l5(5);
    l1.next = &l2;
    l2.next = &l3;
    l3.next = &l4;
    l4.next = &l5;
    ListNode *res = mySol.reverseList(&l1);
    std::cout << res << std::endl;
    return 0;
}