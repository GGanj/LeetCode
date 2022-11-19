#include <queue>
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

// dynamic program
class Solution1 {
public:
    bool hasPathSum(TreeNode* root, int targetSum) {
        if(root == nullptr) {
            return false;
        }
        std::queue<TreeNode*> queue;
        queue.push(root);
        while(!queue.empty()) {
            for(int l = queue.size(); l > 0; --l) {
                TreeNode *currNode = queue.front();
                queue.pop();
                if(currNode->left == nullptr && currNode->right == nullptr) {
                    if(currNode->val == targetSum) {
                        return true;
                    }
                }
                if(currNode->left != nullptr) {
                    currNode->left->val = currNode->val + currNode->left->val;
                    queue.push(currNode->left);
                }
                if(currNode->right != nullptr) {
                    currNode->right->val = currNode->val + currNode->right->val;
                    queue.push(currNode->right);
                }
            }
        }
        return false;
    }
};

// backtracking

class Solution2 {
public:
    bool hasPathSum(TreeNode* root, int targetSum) {
        if(root == nullptr) {
            return false;
        }
        if(root->left == nullptr && root->right == nullptr && root->val == targetSum) {
            return true;
        }
        return hasPathSum(root->left, targetSum - root->val) || hasPathSum(root->right, targetSum -root->val);
    }
};
