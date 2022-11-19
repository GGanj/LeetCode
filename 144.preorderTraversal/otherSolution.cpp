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
    std::vector<int> preorderTraversal(TreeNode* root) {
        if(root == nullptr) {
            return {};
        }
        res.push_back(root->val);
        preorderTraversal(root->left);
        preorderTraversal(root->right);
        return res;
    }
};

class Solution2 {
public:
    
    std::vector<int> preorderTraversal(TreeNode* root) {
        if(root == nullptr) {
            return {};
        }
        std::vector<int> res;
        res.push_back(root->val);
        std::vector<int> lr = preorderTraversal(root->left);
        res.insert(res.end(), lr.begin(), lr.end());
        std::vector<int> rr = preorderTraversal(root->right);
        res.insert(res.end(), rr.begin(), rr.end());
        return res;
    }
};

class Solution3 {
public:
    
    std::vector<int> preorderTraversal(TreeNode* root) {
        std::vector<TreeNode*> stack;
        std::vector<int> res;
        while(root != nullptr || !stack.empty()) {
            if(root == nullptr) {
              root = stack.back();
              stack.pop_back();
              continue;  
            }
            res.push_back(root->val);
            stack.push_back(root->right);
            root = root->left;
        }
        return res;
    }
};