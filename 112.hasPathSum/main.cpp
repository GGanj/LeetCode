#include <iostream>

#include "hasPathSum.cpp"

int main() {
    Solution mySol;
    TreeNode *t1 = new TreeNode(5);
    TreeNode *t2 = new TreeNode(4);
    TreeNode *t3 = new TreeNode(8);
    TreeNode *t4 = new TreeNode(11);
    TreeNode *t5 = new TreeNode(13);
    TreeNode *t6 = new TreeNode(4);
    TreeNode *t7 = new TreeNode(7);
    TreeNode *t8 = new TreeNode(2);
    TreeNode *t9 = new TreeNode(1);
    t1->left = t2;
    t1->right = t3;
    t2->left = t4;
    t3->left = t5;
    t3->right = t6;
    t4->left = t7;
    t4->right = t8;
    t6->right = t9;
    int target = 22;
    bool res = mySol.hasPathSum(t1, target);
    std::cout << res << std::endl;
    return 0;
}