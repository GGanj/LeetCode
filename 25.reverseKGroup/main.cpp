#include <iostream>
#include <vector>

#include "reverseKGroup.cpp"

int main() {
    Solution mySol;
    std::vector<int> numArr = {1,2,3,4,5};
    int k = 1;
    ListNode *head = new ListNode(), *tail = head;
    for(int i : numArr) {
        ListNode *tmpNode = new ListNode(i);
        tail->next = tmpNode;
        tail = tail->next;
    }
    ListNode *res = mySol.reverseKGroup(head->next, k);
    while(res != nullptr) {
        std::cout << res->val << std::endl;
        res = res->next;
    }
    return 0;
}