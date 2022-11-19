/*
 * @lc app=leetcode.cn id=111 lang=cpp
 *
 * [111] 二叉树的最小深度
 *
 * https://leetcode-cn.com/problems/minimum-depth-of-binary-tree/description/
 *
 * algorithms
 * Easy (50.15%)
 * Likes:    760
 * Dislikes: 0
 * Total Accepted:    392.7K
 * Total Submissions: 779.8K
 * Testcase Example:  '[3,9,20,null,null,15,7]'
 *
 * 给定一个二叉树，找出其最小深度。
 * 
 * 最小深度是从根节点到最近叶子节点的最短路径上的节点数量。
 * 
 * 说明：叶子节点是指没有子节点的节点。
 * 
 * 
 * 
 * 示例 1：
 * 
 * 
 * 输入：root = [3,9,20,null,null,15,7]
 * 输出：2
 * 
 * 
 * 示例 2：
 * 
 * 
 * 输入：root = [2,null,3,null,4,null,5,null,6]
 * 输出：5
 * 
 * 
 * 
 * 
 * 提示：
 * 
 * 
 * 树中节点数的范围在 [0, 10^5] 内
 * -1000 
 * 
 * 
 */


/**
 * Definition for a binary tree node.
 *  */
#include <climits>
#include <queue>
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
    int minDepth(TreeNode* root) {
        if(root == nullptr) {
            return 0;
        }
        int dept = 1;
        std::queue<TreeNode*> layer;
        layer.push(root);
        while(!layer.empty()) {
            for(int i = layer.size(); i > 0; --i) {
                TreeNode * currNode = layer.front();
                layer.pop();
                if(currNode->left == nullptr && currNode->right == nullptr) {
                    return dept;
                }
                if(currNode->left != nullptr) {
                    layer.push(currNode->left);
                }
                if(currNode->right != nullptr) {
                    layer.push(currNode->right);
                }
            }
            ++dept;
        }
        return dept;
    }
};
// @lc code=end

