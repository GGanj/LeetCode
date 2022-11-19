#include <climits>
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

// backtracking
class Solution1 {
public:
    int dept = 1, res = INT_MAX;
    int minDepth(TreeNode* root) {
        if(root == nullptr || dept >= res) {
            return 0;
        }
        if(root->left == nullptr && root->right == nullptr) {
            res = res < dept ? res : dept;
            return res;
        }
        ++dept;
        minDepth(root->left);
        minDepth(root->right);
        --dept;
        return res;
    }
};