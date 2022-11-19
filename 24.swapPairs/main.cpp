#include <iostream>
#include <vector>

#include "swapPairs.cpp"

int main() {
    Solution mySol;
    std::vector<int> numArr = {1,2,3,4};
    ListNode *head = new ListNode(), *tail = head;
    for(int i : numArr) {
        ListNode *tmpNode = new ListNode(i);
        tail->next = tmpNode;
        tail = tail->next;
    }
    ListNode *res = mySol.swapPairs(head->next);
    while(res != nullptr) {
        std::cout << res->val << std::endl;
        res = res->next;
    }
    return 0;
}