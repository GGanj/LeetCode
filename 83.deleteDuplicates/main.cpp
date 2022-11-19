#include <iostream>
#include <vector>

#include "deleteDuplicates.cpp"

int main() {
    Solution mySol;
    std::vector<int> n = {1, 1, 2};
    ListNode *head = new ListNode();
    ListNode *p1 = head;
    for(int item : n) {
        ListNode *tmp = new ListNode(item);
        p1->next = tmp;
        p1 = p1->next;
    }
    ListNode * res = mySol.deleteDuplicates(head->next);
    while(res != nullptr) {
        std::cout << res->val << " ";
    }
    std::cout << std::endl;
    return 0;
}