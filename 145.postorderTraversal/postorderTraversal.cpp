/*
 * @lc app=leetcode.cn id=145 lang=cpp
 *
 * [145] 二叉树的后序遍历
 *
 * https://leetcode-cn.com/problems/binary-tree-postorder-traversal/description/
 *
 * algorithms
 * Easy (75.69%)
 * Likes:    844
 * Dislikes: 0
 * Total Accepted:    440.8K
 * Total Submissions: 581.3K
 * Testcase Example:  '[1,null,2,3]'
 *
 * 给你一棵二叉树的根节点 root ，返回其节点值的 后序遍历 。
 * 
 * 
 * 
 * 示例 1：
 * 
 * 
 * 输入：root = [1,null,2,3]
 * 输出：[3,2,1]
 * 
 * 
 * 示例 2：
 * 
 * 
 * 输入：root = []
 * 输出：[]
 * 
 * 
 * 示例 3：
 * 
 * 
 * 输入：root = [1]
 * 输出：[1]
 * 
 * 
 * 
 * 
 * 提示：
 * 
 * 
 * 树中节点的数目在范围 [0, 100] 内
 * -100 <= Node.val <= 100
 * 
 * 
 * 
 * 
 * 进阶：递归算法很简单，你可以通过迭代算法完成吗？
 * 
 */
#include <vector>

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

// @lc code=start
class Solution {
public:
    std::vector<int> postorderTraversal(TreeNode* root) {
        if(root == nullptr) {
            return {};
        }
        std::vector<int> res;
        std::vector<TreeNode*> stack;
        while(root != nullptr || !stack.empty()) {
            if(root->left == nullptr && root->right == nullptr) {
                res.push_back(root->val);
                if(stack.empty()) {
                    return res;
                }
                root = stack.back();
                stack.pop_back();
            } else {
                stack.push_back(root);
                if(root->right != nullptr) {
                    stack.push_back(root->right);
                    root->right = nullptr;
                }
                if(root->left != nullptr) {
                    stack.push_back(root->left);
                    root->left = nullptr;
                }
                root = stack.back();
                stack.pop_back();
            }
        }
        return res;
    }
};
// @lc code=end

