#include <iostream>

#include "mergeKLists.cpp"


// struct ListNode {
//     int val;
//     ListNode *next;
//     ListNode() : val(0), next(nullptr) {}
//     ListNode(int x) : val(x), next(nullptr) {}
//     ListNode(int x, ListNode *next) : val(x), next(next) {}
// };

int main() {
    Solution mySol;
    std::vector<std::vector<int>> listArr = {{}};
    std::vector<ListNode*> lists;
    for(std::vector<std::vector<int>>::iterator vecIter = listArr.begin(); vecIter < listArr.end(); ++vecIter) {
        ListNode *tmpHead = new ListNode(-1), *p0 = tmpHead;
        for(std::vector<int>::iterator intIter = (*vecIter).begin(); intIter < (*vecIter).end(); ++intIter) {
            ListNode *tmpNode = new ListNode(*intIter);
            p0->next = tmpNode;
            p0 = p0->next;
        }
        lists.push_back(tmpHead->next);
    }
    ListNode * res = mySol.mergeKLists(lists);
    while(res != nullptr) {
        std::cout << res->val << " ";
        res = res->next;
    }
    std::cout << std::endl;
    return 0;
}