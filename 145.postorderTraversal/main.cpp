#include <iostream>

#include "postorderTraversal.cpp"

int main() {
    Solution mySol;
    TreeNode *l1 = new TreeNode(1);
    TreeNode *l2 = new TreeNode(2);
    TreeNode *l3 = new TreeNode(3);
    l1->right = l2;
    l2->left = l3;
    std::vector<int> res = mySol.postorderTraversal(l1);
    for(int i : res) {
        std::cout << i << " ";
    }
    std::cout << std::endl;
    return 0;
}