 struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution1 {
public:
    ListNode* reverseList(ListNode* head) {
        if(head == nullptr) {
            return head;
        }
        ListNode *pPre = nullptr, *pCurr = head, *pNext = nullptr;
        while(pCurr!= nullptr) {
            pNext = pCurr->next;
            pCurr->next = pPre;
            pPre = pCurr;
            pCurr = pNext;
        }
        return pPre;
    }
};

class Solution2 {
public:
    ListNode* reverseList(ListNode* head) {
        if(head == nullptr) {
            return head;
        }
        ListNode *p1 = head, *p2 = head->next, *pTail = p1;
        while(pTail->next != nullptr) {
            pTail = pTail->next;
        }
        while(p1 != pTail) {
            p1->next = pTail->next;
            pTail->next = p1;
            p1 = p2;
            p2 = p2->next;   
        }
        return pTail;
    }
};

class Solution2 {
public:
    ListNode* reverseList(ListNode* head) {
        if(head == nullptr || head->next == nullptr) {
            return head;
        }
        ListNode *pNext = head->next;
        ListNode *newHead = reverseList(head->next);
        pNext->next = head;
        head->next = nullptr;
        return newHead; 
    }
};