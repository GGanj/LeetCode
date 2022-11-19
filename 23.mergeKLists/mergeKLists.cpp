/*
 * @lc app=leetcode.cn id=23 lang=cpp
 *
 * [23] 合并K个升序链表
 *
 * https://leetcode-cn.com/problems/merge-k-sorted-lists/description/
 *
 * algorithms
 * Hard (56.84%)
 * Likes:    1925
 * Dislikes: 0
 * Total Accepted:    457.8K
 * Total Submissions: 805K
 * Testcase Example:  '[[1,4,5],[1,3,4],[2,6]]'
 *
 * 给你一个链表数组，每个链表都已经按升序排列。
 * 
 * 请你将所有链表合并到一个升序链表中，返回合并后的链表。
 * 
 * 
 * 
 * 示例 1：
 * 
 * 输入：lists = [[1,4,5],[1,3,4],[2,6]]
 * 输出：[1,1,2,3,4,4,5,6]
 * 解释：链表数组如下：
 * [
 * ⁠ 1->4->5,
 * ⁠ 1->3->4,
 * ⁠ 2->6
 * ]
 * 将它们合并到一个有序链表中得到。
 * 1->1->2->3->4->4->5->6
 * 
 * 
 * 示例 2：
 * 
 * 输入：lists = []
 * 输出：[]
 * 
 * 
 * 示例 3：
 * 
 * 输入：lists = [[]]
 * 输出：[]
 * 
 * 
 * 
 * 
 * 提示：
 * 
 * 
 * k == lists.length
 * 0 <= k <= 10^4
 * 0 <= lists[i].length <= 500
 * -10^4 <= lists[i][j] <= 10^4
 * lists[i] 按 升序 排列
 * lists[i].length 的总和不超过 10^4
 * 
 * 
 */

#include <vector>
#include <unordered_map>
#include <queue>
#include <functional>
/**
 * Definition for singly-linked list.
 * */
 struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};


// @lc code=start
class Solution {
struct Status {
    int val;
    ListNode *ptr;
    bool operator < (const Status &rhs) const {
        return val > rhs.val;
    }
};
public:
    ListNode* mergeKLists(std::vector<ListNode*>& lists) {
        ListNode *head = new ListNode(-1), *p0 = head;
        std::priority_queue<Status> smallHeap;
        for(ListNode *pList : lists) {
            if(pList != nullptr) {
                smallHeap.push({pList->val, pList});
            }
        }
        while(smallHeap.size() > 0) {
            ListNode *smallNode = smallHeap.top().ptr;
            p0->next = smallNode;
            p0 = p0->next;
            smallHeap.pop();
            if(smallNode->next != nullptr) {
                smallHeap.push({smallNode->next->val, smallNode->next});
            }
        }

        return head->next;
    }
};
// @lc code=end

