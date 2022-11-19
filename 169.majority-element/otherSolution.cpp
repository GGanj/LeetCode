#include <vector>
#include <algorithm>
#include <unordered_map>

class Solution1 {
public:
    int majorityElement(std::vector<int>& nums) {
        sort(nums.begin(), nums.end());
        return nums[nums.size() / 2];
    }
};

class Solution2 {
public:
    int majorityElement(std::vector<int>& nums) {
        std::unordered_map<int, int> counts;
        int res = nums[0];
        for(int i : nums) {
            ++counts[i];
            if(counts[i] > counts[res]) {
                res = i;
            }
        }
        return res;
    }
};

class Solution3 {
public:
    int currCounts(std::vector<int> nums, int target, int low, int high) {
        int counts = 0;
        for(int i = low; i <= high; ++i) {
            if(nums[i] == target) {
                ++counts;
            }
        }
        return counts;
    }

    int subMajorityElem(std::vector<int> nums, int low, int high) {
        if(low == high) {
            return nums[low];
        }
        int mid = (low + high) / 2;
        int left = subMajorityElem(nums, low, mid);
        int right = subMajorityElem(nums, mid + 1, high);
        if(currCounts(nums, left, low, high) > (high - low + 1) / 2) {
            return left;
        }
        return right;
    }
    int majorityElement(std::vector<int>& nums) {
        return subMajorityElem(nums, 0, nums.size() - 1);
    }
};

class Solution4 {
public:
    int majorityElement(std::vector<int>& nums) {
        int currentNum = nums[0], vote = 0;
        for( int i : nums) {
            if(vote == 0) {
                currentNum = i;
            }
            if(currentNum == i) {
                ++vote;
            } else {
                --vote;
            }
        }
        return currentNum;
    }
};