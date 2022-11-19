/*
 * @lc app=leetcode.cn id=21 lang=cpp
 *
 * [21] 合并两个有序链表
 *
 * https://leetcode-cn.com/problems/merge-two-sorted-lists/description/
 *
 * algorithms
 * Easy (66.66%)
 * Likes:    2406
 * Dislikes: 0
 * Total Accepted:    993K
 * Total Submissions: 1.5M
 * Testcase Example:  '[1,2,4]\n[1,3,4]'
 *
 * 将两个升序链表合并为一个新的 升序 链表并返回。新链表是通过拼接给定的两个链表的所有节点组成的。 
 * 
 * 
 * 
 * 示例 1：
 * 
 * 
 * 输入：l1 = [1,2,4], l2 = [1,3,4]
 * 输出：[1,1,2,3,4,4]
 * 
 * 
 * 示例 2：
 * 
 * 
 * 输入：l1 = [], l2 = []
 * 输出：[]
 * 
 * 
 * 示例 3：
 * 
 * 
 * 输入：l1 = [], l2 = [0]
 * 输出：[0]
 * 
 * 
 * 
 * 
 * 提示：
 * 
 * 
 * 两个链表的节点数目范围是 [0, 50]
 * -100 
 * l1 和 l2 均按 非递减顺序 排列
 * 
 * 
 */


/**
 * Definition for singly-linked list.
 *  */
 struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};


// @lc code=start
class Solution {
public:
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        if(list1 == nullptr) {
            return list2;
        }
        if(list2 == nullptr) {
            return list1;
        }
        ListNode *head = new ListNode(-1);
        ListNode *p0 = head, *p1 = list1, *p2 = list2;
        while(p1 != nullptr && p2 != nullptr) {
            if(p1->val < p2->val) {
                p0->next = p1;
                p0 = p0->next;
                p1 = p1->next;

            } else if(p1->val > p2->val) {
                p0->next = p2;
                p0 = p0->next;
                p2 = p2->next;
            } else {
                p0->next = p1;
                p0 = p0->next;
                p1 = p1->next;
                p0->next = p2;
                p0 = p0->next;
                p2 = p2->next;

            }
        }
        p0->next = p1 != nullptr ? p1 : p2;
        return head->next;
    }
};
// @lc code=end

