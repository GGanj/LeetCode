/*
 * @lc app=leetcode.cn id=83 lang=cpp
 *
 * [83] 删除排序链表中的重复元素
 *
 * https://leetcode-cn.com/problems/remove-duplicates-from-sorted-list/description/
 *
 * algorithms
 * Easy (53.57%)
 * Likes:    790
 * Dislikes: 0
 * Total Accepted:    429K
 * Total Submissions: 801.2K
 * Testcase Example:  '[1,1,2]'
 *
 * 给定一个已排序的链表的头 head ， 删除所有重复的元素，使每个元素只出现一次 。返回 已排序的链表 。
 * 
 * 
 * 
 * 示例 1：
 * 
 * 
 * 输入：head = [1,1,2]
 * 输出：[1,2]
 * 
 * 
 * 示例 2：
 * 
 * 
 * 输入：head = [1,1,2,3,3]
 * 输出：[1,2,3]
 * 
 * 
 * 
 * 
 * 提示：
 * 
 * 
 * 链表中节点数目在范围 [0, 300] 内
 * -100 <= Node.val <= 100
 * 题目数据保证链表已经按升序 排列
 * 
 * 
 */


/**
 * Definition for singly-linked list.
 *   */
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
    ListNode* deleteDuplicates(ListNode* head) {
        if(head == nullptr) {
            return head;
        }
        ListNode *dumyHead = new ListNode();
        dumyHead->next = head;
        ListNode *p1 = dumyHead->next, *p2 = p1->next;
        while(p1 != nullptr && p2 != nullptr) {
            if(p1->val != p2->val) {
                p1 = p2;
                p2 = p2->next;
            } else {
                p1->next = p2->next;
                p2 = p2->next;
            }
        }
        return dumyHead->next;
    }
};
// @lc code=end

