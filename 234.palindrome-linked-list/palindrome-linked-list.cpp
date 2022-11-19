/*
 * @lc app=leetcode.cn id=234 lang=cpp
 *
 * [234] 回文链表
 *
 * https://leetcode-cn.com/problems/palindrome-linked-list/description/
 *
 * algorithms
 * Easy (51.35%)
 * Likes:    1425
 * Dislikes: 0
 * Total Accepted:    455.9K
 * Total Submissions: 878.6K
 * Testcase Example:  '[1,2,2,1]'
 *
 * 给你一个单链表的头节点 head ，请你判断该链表是否为回文链表。如果是，返回 true ；否则，返回 false 。
 * 
 * 
 * 
 * 示例 1：
 * 
 * 
 * 输入：head = [1,2,2,1]
 * 输出：true
 * 
 * 
 * 示例 2：
 * 
 * 
 * 输入：head = [1,2]
 * 输出：false
 * 
 * 
 * 
 * 
 * 提示：
 * 
 * 
 * 链表中节点数目在范围[1, 10^5] 内
 * 0 <= Node.val <= 9
 * 
 * 
 * 
 * 
 * 进阶：你能否用 O(n) 时间复杂度和 O(1) 空间复杂度解决此题？
 * 
 */


struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};
 // @lc code=start
/**
 * Definition for singly-linked list.
 * */
class Solution {
public:
    bool isPalindrome(ListNode* head) {
        ListNode *slow = head, *fast = head;
        while(fast != nullptr && fast->next != nullptr) {
            slow = slow->next;
            fast = fast->next->next;
        }
        if(fast != nullptr) {
            slow = slow->next;
        }
        ListNode *pPre = nullptr, *pCurr = slow, *pNext = slow;
        while(pCurr != nullptr) {
            pNext = pCurr->next;
            pCurr->next = pPre;
            pPre = pCurr;
            pCurr = pNext;
        }
        while(head != nullptr && pPre != nullptr) {
            if(head->val != pPre->val) {
                return false;
            }
            head = head->next;
            pPre = pPre->next;
        }
        return true;
    }
};
// @lc code=end

