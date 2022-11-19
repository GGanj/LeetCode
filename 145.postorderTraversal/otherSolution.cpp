#include <vector>

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
    std::vector<int> postorderTraversal(TreeNode* root) {
        if(root == nullptr) {
            return {};
        }
        std::vector<int> res, lr, rr;
        lr = postorderTraversal(root->left);
        res.insert(res.end(), lr.begin(), lr.end());
        rr = postorderTraversal(root->right);
        res.insert(res.end(), rr.begin(), rr.end());
        res.push_back(root->val);
        return res;
    }
};

class Solution2 {
public:
    std::vector<int> res;
    std::vector<int> postorderTraversal(TreeNode* root) {
        if(root == nullptr) {
            return {};
        }
        postorderTraversal(root->left);
        postorderTraversal(root->right);
        res.push_back(root->val);
        return res;
    }
};

class Solution3 {
public:
    std::vector<int> postorderTraversal(TreeNode* root) {
        if(root == nullptr) {
            return {};
        }
        std::vector<int> res;
        std::vector<TreeNode*> stack;
        while(root != nullptr || !stack.empty()) {
            while(root != nullptr) {
                stack.push_back(root);
                root = root->left;
            }
            root = stack.back();
            if(root->right == nullptr) {
                res.push_back(root->val);
                stack.pop_back();
                if(stack.empty()) {
                    root = nullptr;
                    continue;
                }
                root = stack.back();
                stack.pop_back();
                root->left = nullptr;
            } else {
                stack.push_back(root->right);
                root->right = nullptr;
                root = stack.back();
                stack.pop_back();
            }
        }
        return res;
    }
};

class Solution4 {
public:
    std::vector<int> postorderTraversal(TreeNode* root) {
        if(root == nullptr) {
            return {};
        }
        std::vector<int> res;
        std::vector<TreeNode*> stack;
        while(root != nullptr || !stack.empty()) {
            while(root != nullptr) {
                stack.push_back(root);
                if(root->right != nullptr) {
                    stack.push_back(root->right);
                    root->right = nullptr;
                }
                // stack.push_back(root->left);
                // root->left = nullptr;
                // root = stack.back();
                // stack.pop_back();
                if(root->left != nullptr) {
                    stack.push_back(root->left);
                    root->left = nullptr;
                }
                root = root->left;
            }
            root = stack.back();
            stack.pop_back();
            if(root->left != nullptr || root->right != nullptr) {
                continue;
            }
            res.push_back(root->val);
            if(stack.empty()) {
                root = nullptr;
                continue;
            }
            root = stack.back();
            stack.pop_back();
        }
        return res;
    }
};

class Solution5 {
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