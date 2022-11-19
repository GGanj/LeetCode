/*
 * @lc app=leetcode.cn id=101 lang=cpp
 *
 * [101] 对称二叉树
 *
 * https://leetcode-cn.com/problems/symmetric-tree/description/
 *
 * algorithms
 * Easy (57.53%)
 * Likes:    1920
 * Dislikes: 0
 * Total Accepted:    594.2K
 * Total Submissions: 1M
 * Testcase Example:  '[1,2,2,3,4,4,3]'
 *
 * 给你一个二叉树的根节点 root ， 检查它是否轴对称。
 * 
 * 
 * 
 * 示例 1：
 * 
 * 
 * 输入：root = [1,2,2,3,4,4,3]
 * 输出：true
 * 
 * 
 * 示例 2：
 * 
 * 
 * 输入：root = [1,2,2,null,3,null,3]
 * 输出：false
 * 
 * 
 * 
 * 
 * 提示：
 * 
 * 
 * 树中节点数目在范围 [1, 1000] 内
 * -100 <= Node.val <= 100
 * 
 * 
 * 
 * 
 * 进阶：你可以运用递归和迭代两种方法解决这个问题吗？
 * 
 */


/**
 * Definition for a binary tree node.
 *  */
 struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};
#include <vector>
// @lc code=start
class Solution {
public:
    bool isSymmetric(TreeNode* root) {
        if(root == nullptr) {
            return true;
        }
        std::vector<TreeNode *> ls, rs;
        TreeNode *lt = root->left;
        TreeNode *rt = root->right;
        bool res = false;
        while((lt != nullptr || !ls.empty()) && (rt != nullptr  || !rs.empty())) {
            if(lt == nullptr && rt == nullptr) {
                res = true;
            } else if(lt == nullptr || rt == nullptr) {
                return false;
            } else if(lt->val != rt->val) {
                return false;
            } else {
                res = true;
                ls.push_back(lt->right);
                lt = lt->left;
                rs.push_back(rt->left);
                rt = rt->right;
            }
        }
        return res;
    }
};
// @lc code=end

