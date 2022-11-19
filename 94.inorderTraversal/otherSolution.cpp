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
    std::vector<int> res;
    std::vector<int> inorderTraversal(TreeNode* root) {
        if(root == nullptr) {
            return {};
        }
        if(root->left != nullptr) {
            inorderTraversal(root->left);
        }
        res.push_back(root->val);
        if(root->right != nullptr) {
            inorderTraversal(root->right);
        }
        return res;
    }
};

class Solution2 {
public:
    
    std::vector<int> inorderTraversal(TreeNode* root) {
        std::vector<int> res;
        std::vector<TreeNode*> trace;
        while(root != nullptr) {
            while(root->left !=nullptr) {
                trace.push_back(root);
                root = root->left;
            }
            // root = trace.back();
            // trace.pop_back();
            res.push_back(root->val);
            if(root->right !=nullptr) {
                root = root->right;
            } else if(!trace.empty()) {
                root = trace.back();
                root->left = nullptr;
                trace.pop_back();
            } else {
                root = nullptr;
            }
        }
        return res;
    }
};

class Solution3 {
public:
    
    std::vector<int> inorderTraversal(TreeNode* root) {
        std::vector<int> res;
        std::vector<TreeNode*> trace;
        while(root != nullptr || !trace.empty()) {
            while(root != nullptr) {
                trace.push_back(root);
                root = root->left;
            }
            root = trace.back();
            trace.pop_back();
            res.push_back(root->val);
            root = root->right;
        }
        return res;
    }
};