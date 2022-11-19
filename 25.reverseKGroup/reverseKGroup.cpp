/*
 * @lc app=leetcode.cn id=25 lang=cpp
 *
 * [25] K 个一组翻转链表
 *
 * https://leetcode-cn.com/problems/reverse-nodes-in-k-group/description/
 *
 * algorithms
 * Hard (67.06%)
 * Likes:    1617
 * Dislikes: 0
 * Total Accepted:    333.9K
 * Total Submissions: 496.5K
 * Testcase Example:  '[1,2,3,4,5]\n2'
 *
 * 给你链表的头节点 head ，每 k 个节点一组进行翻转，请你返回修改后的链表。
 * 
 * k 是一个正整数，它的值小于或等于链表的长度。如果节点总数不是 k 的整数倍，那么请将最后剩余的节点保持原有顺序。
 * 
 * 你不能只是单纯的改变节点内部的值，而是需要实际进行节点交换。
 * 
 * 
 * 
 * 示例 1：
 * 
 * 
 * 输入：head = [1,2,3,4,5], k = 2
 * 输出：[2,1,4,3,5]
 * 
 * 
 * 示例 2：
 * 
 * 
 * 
 * 
 * 输入：head = [1,2,3,4,5], k = 3
 * 输出：[3,2,1,4,5]
 * 
 * 
 * 
 * 提示：
 * 
 * 
 * 链表中的节点数目为 n
 * 1 <= k <= n <= 5000
 * 0 <= Node.val <= 1000
 * 
 * 
 * 
 * 
 * 进阶：你可以设计一个只用 O(1) 额外内存空间的算法解决此问题吗？
 * 
 * 
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
    ListNode* reverseKGroup(ListNode* head, int k) {
        ListNode *pResHead = new ListNode(-1, head), *pTail = pResHead,*pLeft= nullptr, *pRight = nullptr;
        
        while(pTail->next != nullptr) {
            pRight = pTail;
            for(int i = 0; i < k; ++i) {
                pRight = pRight->next;
                if(pRight == nullptr) {
                    return pResHead->next;
                }
            }
            pLeft = pTail->next;
            kReverse(pTail, pRight);
            pTail = pLeft;
        }
        return pResHead->next;
    }

    void kReverse(ListNode *pTail, ListNode *pRight) {
        ListNode *pL1 = pTail->next, *pL2 = pL1->next;
        while(pL1 != pRight) {
            pL1->next = pRight->next;
            pRight->next = pL1;
            if(pL2 == pRight) {
                break;
            }
            pL1 = pL2;
            pL2 = pL2->next;
        }
        pTail->next = pRight;
    }
};
// @lc code=end

