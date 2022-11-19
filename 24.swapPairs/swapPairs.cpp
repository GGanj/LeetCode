/*
 * @lc app=leetcode.cn id=24 lang=cpp
 *
 * [24] 两两交换链表中的节点
 *
 * https://leetcode-cn.com/problems/swap-nodes-in-pairs/description/
 *
 * algorithms
 * Medium (70.77%)
 * Likes:    1372
 * Dislikes: 0
 * Total Accepted:    434.8K
 * Total Submissions: 614.1K
 * Testcase Example:  '[1,2,3,4]'
 *
 * 给你一个链表，两两交换其中相邻的节点，并返回交换后链表的头节点。你必须在不修改节点内部的值的情况下完成本题（即，只能进行节点交换）。
 * 
 * 
 * 
 * 示例 1：
 * 
 * 
 * 输入：head = [1,2,3,4]
 * 输出：[2,1,4,3]
 * 
 * 
 * 示例 2：
 * 
 * 
 * 输入：head = []
 * 输出：[]
 * 
 * 
 * 示例 3：
 * 
 * 
 * 输入：head = [1]
 * 输出：[1]
 * 
 * 
 * 
 * 
 * 提示：
 * 
 * 
 * 链表中节点的数目在范围 [0, 100] 内
 * 0 <= Node.val <= 100
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
    ListNode* swapPairs(ListNode* head) {
        if(head == nullptr) {
            return head;
        }
        ListNode *p = new ListNode(-1, head), *p0 = p, *p1 = nullptr, *p2 = nullptr;
        while(p0 != nullptr && p0->next != nullptr) {
            p1 = p0->next;
            if(p1->next != nullptr) {
                p2 = p1->next;
            } else {
                break;
            }
            p0->next = p2;
            p1->next = p2->next;
            p2->next = p1;
            p0 = p1;
        }

        return p->next;
    }
};
// @lc code=end

