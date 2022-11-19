/*
 * @lc app=leetcode.cn id=257 lang=cpp
 *
 * [257] 二叉树的所有路径
 *
 * https://leetcode-cn.com/problems/binary-tree-paths/description/
 *
 * algorithms
 * Easy (69.50%)
 * Likes:    770
 * Dislikes: 0
 * Total Accepted:    222.7K
 * Total Submissions: 318.7K
 * Testcase Example:  '[1,2,3,null,5]'
 *
 * 给你一个二叉树的根节点 root ，按 任意顺序 ，返回所有从根节点到叶子节点的路径。
 * 
 * 叶子节点 是指没有子节点的节点。
 * 
 * 
 * 示例 1：
 * 
 * 
 * 输入：root = [1,2,3,null,5]
 * 输出：["1->2->5","1->3"]
 * 
 * 
 * 示例 2：
 * 
 * 
 * 输入：root = [1]
 * 输出：["1"]
 * 
 * 
 * 
 * 
 * 提示：
 * 
 * 
 * 树中节点的数目在范围 [1, 100] 内
 * -100 <= Node.val <= 100
 * 
 * 
 */


struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};
#include <vector>
#include <string>
// @lc code=start
/**
 * Definition for a binary tree node.
 */
class Solution {
public:
    std::vector<std::string> res;
    std::vector<int> trace;
    std::vector<std::string> binaryTreePaths(TreeNode* root) {
        trace.push_back(root->val);
        if(root->left == nullptr && root->right == nullptr) {
            std::string s;
            s += std::to_string(trace[0]);
            for(int i = 1; i < trace.size(); ++i) {
                s +=  ("->" + std::to_string(trace[i]));
            }
            res.push_back(s);
            trace.pop_back();
            return res;
        }
        if(root->left != nullptr) {
            binaryTreePaths(root->left);
        }
        if(root->right != nullptr) {
            binaryTreePaths(root->right);
        }
        trace.pop_back();
        return res;
    }
};
// @lc code=end

