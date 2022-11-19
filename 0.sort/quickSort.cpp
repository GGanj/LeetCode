#include <iostream>

void swap(int& a, int& b) {
    int tmp = a + b;
    a = tmp - a;
    b = tmp - b;
}

void quickSort1(int nums[], int begin, int end) {
    if(end <= begin) {
        return;
    }
    int left = begin, right = end;
    while(left < right) {
        while(left < right && nums[left] <= nums[end]) {
            ++left;
        }
        while(left < right && nums[right] >= nums[end]) {
            --right;
        }
        swap(nums[left], nums[right]);
    }
    swap(nums[left], nums[end]);
    quickSort1(nums, begin, left - 1);
    quickSort1(nums, left + 1, end);
}

int partition(int nums[], int left, int right) {
    int pivotKey = nums[left];
    while(left < right) {
        while(left < right && nums[right] >= pivotKey) {
            --right;
        }
        swap(nums[left], nums[right]);

        while(left < right && nums[left] <= pivotKey) {
            ++left;
        }
        swap(nums[left], nums[right]);
    }
    return left;
}

void quickSort2(int nums[], int left, int right) {
    int pivot;
    if(left < right) {
        pivot = partition(nums, left, right);
        quickSort2(nums, left, pivot - 1);
        quickSort2(nums, pivot + 1, right);
    }
}

int main() {
    int nums[10] = {5, 8, 69 , 7, 96, 45, 86, 13, 56, 3};
    // int nums[5] = {5, 8, 69 , 7, 96};
    int left = 0, right = 9;
    quickSort1(nums, left, right);
    for(int i = 0; i < 10; ++i) {
        std::cout << nums[i] << " ";
    }
    std::cout << std::endl;

    quickSort2(nums, left, right);
    for(int i = 0; i < 10; ++i) {
        std::cout << nums[i] << " ";
    }
    std::cout << std::endl;
    
    return 0;
}