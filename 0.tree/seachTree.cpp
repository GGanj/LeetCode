#include <iostream>

#include "list.h"


void createSearchTree(Node** root, int n) {
    if(*root == nullptr) {
        *root = new Node();
        (*root)->pLeft = nullptr;
        (*root)->pRight = nullptr;
        (*root)->val = n;
        return;
    }
    Node* tmp1 = *root;
    Node* tmp2 = new Node();
    tmp2->pLeft = nullptr;
    tmp2->pRight = nullptr;
    tmp2->val = n;

    while(tmp1 != nullptr) {
        if(n < tmp1->val) {
            if(tmp1->pLeft == nullptr) {
                tmp1->pLeft = tmp2;
                return;
            }
            tmp1 = tmp1->pLeft;
        } else {
            if(tmp1->pRight == nullptr) {
                tmp1->pRight = tmp2;
                return;
            }
            tmp1 = tmp1->pRight;
        }
    }
    return ;
}

void traverse(Node* root) {
    if(root == nullptr) {
        return;
    }
    traverse(root->pLeft);
    std::cout << root->val << std::endl;
    traverse(root->pRight);
}

int main() {
    int nums[10] = {5, 8, 69 , 7, 96, 45, 86, 13, 56, 3};
    Node* pTree = nullptr;
    for(int i = 0; i < 10; ++i) {
        createSearchTree(&pTree, nums[i]);
    }

    traverse(pTree);
    std::cout << std::endl;
    return 0;
}