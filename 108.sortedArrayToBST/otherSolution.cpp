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
    TreeNode* sortedArrayToBST(std::vector<int>& nums) {
        if(nums.size() == 0) {
            return nullptr;
        }
        int left = 0, right = nums.size() - 1, mid = left + (right - left) / 2;
        TreeNode *root = new TreeNode(nums[mid]);
        root->left = subTreeRoot(nums, left, mid - 1);
        root->right = subTreeRoot(nums, mid + 1, right);
        return root;
    }

    TreeNode* subTreeRoot(std::vector<int>& nums, int left, int right) {
        if(left == right) {
            TreeNode *root = new TreeNode(nums[left]);
            return root;
        } else if (left < right) {
            int mid = left + (right - left) / 2;
            TreeNode *root = new TreeNode(nums[mid]);
            root->left = subTreeRoot(nums, left, mid - 1);
            root->right = subTreeRoot(nums, mid + 1, right);
            return root;
        }
        return nullptr;
    }
};

class Solution2 {
public:
    TreeNode* sortedArrayToBST(std::vector<int>& nums) {
        return subTreeRoot(nums, 0, nums.size() - 1);
    }

    TreeNode* subTreeRoot(std::vector<int>& nums, int left, int right) {
        if(left == right) {
            TreeNode *root = new TreeNode(nums[left]);
            return root;
        } else if (left < right) {
            int mid = left + (right - left) / 2;
            TreeNode *root = new TreeNode(nums[mid]);
            root->left = subTreeRoot(nums, left, mid - 1);
            root->right = subTreeRoot(nums, mid + 1, right);
            return root;
        }
        return nullptr;
    }
};