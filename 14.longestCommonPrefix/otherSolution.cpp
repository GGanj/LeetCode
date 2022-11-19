#include <vector>
#include <algorithm>

// recursion from n = 1, **timeout**
class Solution1 {
public:
    std::vector<std::vector<int>> threeSum(std::vector<int>& nums) {
        sort(nums.begin(), nums.end());
        return nSumTarget(nums, 3, 0, 0);
    }

    std::vector<std::vector<int>> nSumTarget(std::vector<int> & nums, int n, int start, int target) {
        int length = nums.size();
        std::vector<std::vector<int>> res;
        if(n == 1) {
            while(start < length) {
                if(nums[start] == target) {
                    res.push_back({nums[start]});
                    return res;
                } else if(nums[start] > target) {
                    return res;
                }
                ++start;
            }
            return res;
        }
        while(start < length) {
            std::vector<std::vector<int>> subRes = nSumTarget(nums, n - 1, start + 1, target - nums[start]);
            for(auto item : subRes) {
                item.insert(item.begin(), nums[start]);
                res.push_back(item);
            }
            while(start < length - 1 && nums[start] == nums[start + 1]) {
                ++start;
            }
            ++start;
        }
        return res;
    }
};

// recursion from n = 2, **done**
class Solution2 {
public:
    std::vector<std::vector<int>> threeSum(std::vector<int>& nums) {
        sort(nums.begin(), nums.end());
        return nSumTarget(nums, 3, 0, 0);
    }

    std::vector<std::vector<int>> nSumTarget(std::vector<int> & nums, int n, int start, int target) {
        int length = nums.size(), low = start, height = length - 1;
        std::vector<std::vector<int>> res;
        if(n == 2) {
            int tmpSum = 0;
            while(low < height) {
                tmpSum = nums[low] + nums[height];
                if(tmpSum > target) {
                    while(low < height && nums[height] == nums[height - 1]) {
                        --height;
                    }
                    --height;
                } else if(tmpSum < target) {
                    while(low < height && nums[low] == nums[low + 1]) {
                        ++low;
                    }
                    ++low;
                } else {
                    res.push_back({nums[low], nums[height]});
                    while(low < height && nums[height] == nums[height - 1]) {
                        --height;
                    }
                    --height;
                    while(low < height && nums[low] == nums[low + 1]) {
                        ++low;
                    }
                    ++low;
                }
            }
            return res;
        }
        while(low < length) {
            std::vector<std::vector<int>> subRes = nSumTarget(nums, n - 1, low + 1, target - nums[low]);
            for(auto item : subRes) {
                item.insert(item.begin(), nums[low]);
                res.push_back(item);
            }
            while(low < length - 1 && nums[low] == nums[low + 1]) {
                ++low;
            }
            ++low;
        }
        return res;
    }
};