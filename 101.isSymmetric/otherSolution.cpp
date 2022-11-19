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
    bool isSymmetric(TreeNode* root) {
        if(root == nullptr) {
            return true;
        }
        return isSameSubTree(root->left, root->right);
    }

    bool isSameSubTree(TreeNode *p, TreeNode *q) {
        if(p == nullptr && q == nullptr) {
            return true;
        }
        if(p == nullptr || q == nullptr) {
            return false;
        }
        if(p->val != q->val) {
            return false;
        }
        return isSameSubTree(p->left, q->right) && isSameSubTree(p->right, q->left);
    }
};