 #include <vector>
 #include <unordered_map>
 
 struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution1 {
public:
    ListNode* mergeKLists(std::vector<ListNode*>& lists) {
        ListNode *head = new ListNode(-1), *p0 = head, *minNode = nullptr;
        std::unordered_map<int, ListNode*> pList;
        int min = INT_MAX, minIndex = 0;
        int k = lists.size();
        for(int i = 0; i < k; ++i) {
            if(lists[i] != nullptr) {
                pList[i] = lists[i];
            }
        }
        while(pList.size() > 0) {
            min = INT_MAX;
            for(int i = 0; i < k; ++i) {
                if(pList.find(i) != pList.end() && pList[i]->val < min) {
                    min = pList[i]->val;
                    minIndex = i;
                }
            }
            p0->next = pList[minIndex];
            p0 = p0->next;
            pList[minIndex] = pList[minIndex]->next;
            if(pList[minIndex] == nullptr) {
                pList.erase(minIndex);
            }
        }

        return head->next;
    }
};