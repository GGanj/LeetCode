struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution1 {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode *p1 = l1, *p2 = l2;
        int tmp = 0;
        while(p1 != nullptr) {
            tmp += p1->val;
            if(p2 != nullptr) {
                tmp += p2->val;
            }
            p1->val = tmp % 10;
            tmp /= 10;

            if(p1->next == nullptr) {
                if(p2 != nullptr && p2->next != nullptr) {
                    p1->next = p2->next;
                    p2 = nullptr;
                } else {
                    if(tmp != 0) {
                        p1->next = new ListNode(tmp);
                        tmp = 0;
                    }
                }
            }

            p1 = p1->next;
            if(p2 != nullptr) {
                p2 = p2->next;
            }
        }
        return l1;
    }
};

class Solution2 {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode *p1 = nullptr, *p2 = nullptr;
        int tmp = 0;
        while(l1 != nullptr || l2 != nullptr || tmp != 0) {
            if(l1 != nullptr) {
                tmp += l1->val;
                l1 = l1->next;
            }
            if(l2 != nullptr) {
                tmp += l2->val;
                l2 = l2->next;
            }
            if(p1 == nullptr) {
                p1 = new ListNode(tmp%10);
                tmp /= 10;
                p2 = p1;
            } else {
                p2->next = new ListNode(tmp%10);
                tmp /= 10;
                p2 = p2->next;
            }
        }
        return p1;
    }
};