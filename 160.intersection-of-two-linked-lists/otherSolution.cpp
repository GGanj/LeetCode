 struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(nullptr) {}
};

class Solution1 {
public:
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        ListNode *p1 = headA, *p2 = headB;
        bool flag1 = false, flag2 = false;
        while(p1 != p2) {
            if(p1->next != nullptr) {
                p1 = p1->next;
            } else {
                if(flag1) {
                    return nullptr;
                }
                p1 = headB;
                flag1 = true;
            }
            if(p2->next != nullptr) {
                p2 = p2->next;
            } else 
            {
                if(flag2) {
                    return nullptr;
                }
                p2 = headA;
                flag2 = true;
            }
        }
        return p1;
    }
};

class Solution2 {
public:
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        ListNode *p1 = headA, *p2 = headB;
        int l1 = 0, l2 = 0;
        while(p1 != nullptr) {
            ++l1;
            p1 = p1->next;
        }
        while(p2 != nullptr) {
            ++l2;
            p2 = p2->next;
        }
        p1 = headA, p2 = headB;
        if(l1 > l2) {
            for(int i = l1 - l2; i > 0; --i) {
                p1 = p1->next;
            }
        } else {
            for(int i = l2 - l1; i > 0; --i) {
                p2 = p2->next;
            }
        }
        while(p1 != p2) {
            p1 = p1->next;
            p2 = p2->next;
        }
        return p1;
    }
};