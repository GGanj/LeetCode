struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(nullptr) {}
};

class Solution1 {
public:
    bool hasCycle(ListNode *head) {
        if(head == nullptr) {
            return false;
        }
        while(head->next != nullptr) {
            if(head->next == head) {
                return true;
            }
            ListNode *tmp = head;
            head = head->next;
            tmp->next = tmp;
        }
        return false;
    }
};

class Solution2 {
public:
    bool hasCycle(ListNode *head) {
        ListNode *pSlow = head, *pFast = head;
        while(pFast != nullptr && pFast->next != nullptr) {
            pSlow = pSlow->next;
            pFast = pFast->next->next;
            if(pSlow == pFast) {
                return true;
            }
        }
        return false;
    }
};