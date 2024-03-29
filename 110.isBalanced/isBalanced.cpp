/*
 * @lc app=leetcode.cn id=110 lang=cpp
 *
 * [110] 平衡二叉树
 *
 * https://leetcode-cn.com/problems/balanced-binary-tree/description/
 *
 * algorithms
 * Easy (56.90%)
 * Likes:    1015
 * Dislikes: 0
 * Total Accepted:    360.1K
 * Total Submissions: 631.6K
 * Testcase Example:  '[3,9,20,null,null,15,7]'
 *
 * 给定一个二叉树，判断它是否是高度平衡的二叉树。
 * 
 * 本题中，一棵高度平衡二叉树定义为：
 * 
 * 
 * 一个二叉树每个节点 的左右两个子树的高度差的绝对值不超过 1 。
 * 
 * 
 * 
 * 
 * 示例 1：
 * 
 * 
 * 输入：root = [3,9,20,null,null,15,7]
 * 输出：true
 * 
 * 
 * 示例 2：
 * 
 * 
 * 输入：root = [1,2,2,3,3,null,null,4,4]
 * 输出：false
 * 
 * 
 * 示例 3：
 * 
 * 
 * 输入：root = []
 * 输出：true
 * 
 * 
 * 
 * 
 * 提示：
 * 
 * 
 * 树中的节点数在范围 [0, 5000] 内
 * -10^4 
 * 
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

// @lc code=start
class Solution {
public:
    bool isBalanced(TreeNode* root) {
        bool isBalance = true;
        subTreeDepth(root, isBalance);
        return isBalance;
    }

    int subTreeDepth(TreeNode *root, bool &isBalance) {
        if(root ==nullptr || !isBalance) {
            return 0;
        }
        int ld = subTreeDepth(root->left, isBalance);
        if(!isBalance) {
            return 0;
        }
        int rd = subTreeDepth(root->right, isBalance);
        if(!isBalance) {
            return 0;
        }
        if(ld - rd < -1 || ld - rd > 1) {
            isBalance = false;
        }
        return ld > rd ? ld + 1 : rd + 1;
    }
};
// @lc code=end

