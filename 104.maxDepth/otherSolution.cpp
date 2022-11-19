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
    int maxDepth(TreeNode* root) {
        if(root == nullptr) {
            return 0;
        }
        int ld = leefDepth(root->left, 1);
        int rd = leefDepth(root->right, 1);
        return ld > rd ? ld : rd;
    }

    int leefDepth(TreeNode* root, int depth) {
        if(root == nullptr) {
            return depth;
        }
        int ld = leefDepth(root->left, depth + 1);
        int rd = leefDepth(root->right, depth + 1);
        return ld > rd ? ld : rd;
    }
};

class Solution2 {
public:
    int maxDepth(TreeNode* root) {
        if(root == nullptr) {
            return 0;
        }
        int ld = maxDepth(root->left) + 1;
        int rd = maxDepth(root->right) + 1;
        return ld > rd ? ld : rd;
    }
};

// backtracking
class Solution3 {
public:
    int depth = 0;
    int res = 0;
    int maxDepth(TreeNode* root) {
        leefDepth(root);
        return res;
    }

    void leefDepth(TreeNode* root) {
        if(root == nullptr) {
            res = res > depth ? res : depth;
            return;
        }
        ++depth;
        leefDepth(root->left);
        leefDepth(root->right);
        --depth;
    }
};

class Solution4 {
public:
    int maxDepth(TreeNode* root) {
        if(root == nullptr) {
            return 0;
        }
        int res = 0;
        leefDepth(root->left, 1, res);
        leefDepth(root->right, 1, res);
        return res;
    }

    void leefDepth(TreeNode* root, int depth, int& res) {
        if(root == nullptr) {
            res = res > depth ? res : depth;
            return;
        }
        leefDepth(root->left, depth + 1, res);
        leefDepth(root->right, depth + 1, res);
    }
};

class Solution5 {
public:
    int maxDepth(TreeNode* root) {
        int res = 0;
        leefDepth(root, 0, res);
        return res;
    }

    void leefDepth(TreeNode* root, int depth, int& res) {
        if(root == nullptr) {
            res = res > depth ? res : depth;
            return;
        }
        leefDepth(root->left, depth + 1, res);
        leefDepth(root->right, depth + 1, res);
    }
};