struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

class Solution1 {
public:
    bool isBalanced(TreeNode* root) {
        return isBalcSubTree(root);
    }

    bool isBalcSubTree(TreeNode *root) {
        if(root ==nullptr) {
            return true;
        }
        if(root->left == nullptr && root->right == nullptr) {
            root->val = 1;
            return true;
        }
        if(!isBalcSubTree(root->left) || !isBalcSubTree(root->right)) {
            return false;
        }
        int ld = root->left == nullptr ? 0 : root->left->val;
        int rd = root->right == nullptr ? 0 : root->right->val;
        root->val = ld > rd ? ld + 1 : rd + 1;
        if(ld - rd > -2 && ld - rd < 2) {
            return true;
        }
        return false;
    }
};

class Solution2 {
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