#include <iostream>

void swap(int& a, int& b) {
    int tmp = a + b;
    a = tmp - a;
    b = tmp - b;
}

void createBigTopHead(int nums[], int parentNode, int n) {
    while(n != 0 && parentNode <= (n - 1) / 2) {
        int childNode = 2 * parentNode + 1;
        if(childNode < n) {
            if(nums[childNode] < nums[childNode + 1]) {
                ++childNode;
            }
        }

        if(nums[parentNode] > nums[childNode]) {
            break;
        }
        else {
            swap(nums[parentNode], nums[childNode]);
            parentNode = childNode;
        }
    }
}

void createSmallTopHead(int nums[], int rootNode, int n) {
    while(n != 0 && rootNode <= (n - 1) / 2) {
        int minChildNode = 2 * rootNode + 1;
        if(minChildNode < n && nums[minChildNode] > nums[minChildNode + 1]) {
            ++minChildNode;
        }

        if(nums[rootNode] < nums[minChildNode]) {
            break;
        } else {
            swap(nums[rootNode], nums[minChildNode]);
            rootNode = minChildNode;
        }
    }
}

void bHeadSort(int nums[], int n) {
    int parentNode = (n - 1) / 2;
    while(parentNode >= 0) {
        createBigTopHead(nums, parentNode, n);
        --parentNode;
    }
    while(n > 0) {
        swap(nums[0], nums[n]);
        --n;
        createBigTopHead(nums, 0, n);
    }
}



void sHeadSort(int nums[], int n) {
    int parentNode = (n - 1) / 2;
    while(parentNode >= 0) {
        createSmallTopHead(nums, parentNode, n);
        --parentNode;
    }
    while(n > 0) {
        swap(nums[0], nums[n]);
        --n;
        createSmallTopHead(nums, 0, n);
    }
}


int main() {
    int nums[10] = {5, 8, 69 , 7, 96, 45, 86, 13, 56, 3};
    bHeadSort(nums, 9);
    for(int i = 0; i < 10; ++i) {
        std::cout << nums[i] << " ";
    }
    std::cout << std::endl;

    sHeadSort(nums, 9);
    for(int i = 0; i < 10; ++i) {
        std::cout << nums[i] << " ";
    }
    std::cout << std::endl;
    return 0;
}