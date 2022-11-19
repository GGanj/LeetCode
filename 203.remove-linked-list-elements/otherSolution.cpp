 struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution1 {
public:
    ListNode* removeElements(ListNode* head, int val) {
        ListNode *mockHead = new ListNode();
        mockHead->next = head;
        ListNode *p1 = mockHead, *p2 = head;
        while(p2 != nullptr) {
            if(p2->val != val) {
                p1 = p2;
            } else {
                p1->next = p2->next;
            }
            p2 = p2->next;
        }
        return mockHead->next;
    }
};

class Solution2 {
public:
    ListNode* removeElements(ListNode* head, int val) {
        if(head == nullptr) {
            return head;
        }
        head->next = removeElements(head->next, val);
        return head->val == val ? head->next : head;
    }
};