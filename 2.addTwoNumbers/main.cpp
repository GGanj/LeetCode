#include <iostream>
#include <vector>

#include "otherSolution.cpp"

int main() {
    std::vector<int> num1 = {2,4,9};
    std::vector<int> num2 = {5,6,4,9};
    ListNode* l1, *l2;
    std::vector<int>::iterator tmpIte = num1.end()-1;
    l1 = new ListNode(*tmpIte);
    for(--tmpIte; tmpIte >= num1.begin(); --tmpIte) {
        ListNode * tmpNode = new ListNode(*tmpIte, l1);
        tmpNode->next = l1;
        l1 = tmpNode;
    }
    tmpIte = num2.end()-1;
    l2 = new ListNode(*tmpIte);
    for(--tmpIte; tmpIte >= num2.begin(); --tmpIte) {
        ListNode * tmpNode = new ListNode(*tmpIte, l2);
        tmpNode->next = l2;
        l2 = tmpNode;
    }

    Solution2 sol;
    l1 = sol.addTwoNumbers(l1, l2);

    ListNode* pTmp;
    while(l1 != nullptr) {
        pTmp = l1;
        l1 = l1->next;
        delete pTmp;
    }

    while(l2 != nullptr) {
        pTmp = l2;
        l2 = l2->next;
        delete pTmp;
    }

    return 0;
}