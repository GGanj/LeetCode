#include <vector>
#include <algorithm>
// run time error
class Solution1 {
public:
    void nextPermutation(std::vector<int>& nums) {
        sortSubArr(nums, findMin(nums));
    }

    std::vector<int>::iterator findMin(std::vector<int> &nums) {
        std::vector<int>::iterator iter1 = nums.end() - 1, iter2 = iter1 - 1;
        while(iter1 > nums.begin()) {
            for(iter2 = iter1 - 1; iter2 >= nums.begin(); --iter2) {
                if(*iter1 > *iter2) {
                    int tmp = *iter1;
                    nums.erase(iter1);
                    nums.insert(iter2, tmp);
                    return iter2 + 1;
                }
            }
            --iter1;
        }
        return nums.end();
    }

    void sortSubArr(std::vector<int> &nums, std::vector<int>::iterator iter) {
        if(iter == nums.end()) {
            return;
        }
        sort(iter, nums.end() - 1);
    }
};

class Solution2 {
public:
    void nextPermutation(std::vector<int>& nums) {
        std::vector<int>::iterator iter1 = nums.end() - 1, iter2 = iter1 - 1;
        while(iter1 > nums.begin()) {
            iter2 = iter1 - 1;
            if(*iter1 > *iter2) {
                break;
            }
            --iter1;
        }
        if(iter1 != nums.begin()) {
            std::vector<int>::iterator largeIter = nums.end() - 1;
            while(largeIter > iter2) {
                if(*largeIter > *iter2) {
                    *iter2 = *largeIter + *iter2;
                    *largeIter = *iter2 - *largeIter;
                    *iter2 = *iter2 - *largeIter;
                    break;
                }
                --largeIter;
            }
        }
        iter2 = iter1;
        iter1 = nums.end() - 1;
        while(iter2 < iter1) {
            *iter1 = *iter1 + *iter2;
            *iter2 = *iter1 - *iter2;
            *iter1 = *iter1 - *iter2;
            --iter1;
            ++iter2;
        }
    }
};

class Solution3 {
public:
    void nextPermutation(std::vector<int>& nums) {
        int i = nums.size() - 1, j = i - 1;
        while(i > 0) {
            j = i - 1;
            if(nums[i] > nums[j]) {
                break;
            }
            --i;
        }
        if(i != 0) {
            int k = nums.size() - 1;
            while(k > j) {
                if(nums[k] > nums[j]) {
                    nums[j] = nums[j] + nums[k];
                    nums[k] = nums[j] - nums[k];
                    nums[j] = nums[j] - nums[k];
                    break;
                }
                --k;
            }
        }
        j = i;
        i = nums.size() - 1;
        while(j < i) {
            nums[j] = nums[j] + nums[i];
            nums[i] = nums[j] - nums[i];
            nums[j] = nums[j] - nums[i];
            --i;
            ++j;
        }
    }
};