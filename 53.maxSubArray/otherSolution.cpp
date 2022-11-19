#include <vector>
// timeout
class Solution1 {
public:
    int maxSubArray(std::vector<int>& nums) {
        if(nums.size() == 0) {
            return 0;
        }
        int res = INT_MIN;
        int currentSum = 0;
        for(int i = 1; i <= nums.size(); ++i) {
            for(int j = 0; j + i <= nums.size(); ++j) {
                currentSum = 0;
                for(int k = 0; k < i; ++k) {
                    currentSum += nums[j + k];
                }
                res = res > currentSum ? res : currentSum;
            }
        }
        return res;
    }
};

// dynamic programing
// dp[i] = num[i] or num[i] + (num[i-1] ... num[0])
class Solution2 {
public:
    int maxSubArray(std::vector<int>& nums) {
        if(nums.size() == 0) {
            return 0;
        }
        std::vector<int>::iterator iter = nums.begin();
        int res = *iter;
        ++iter;
        while(iter != nums.end()) {
            int tmp = *iter + *(iter - 1);
            *iter = *iter > tmp ? *iter : tmp;
            res = res > *iter ? res : *iter;
            ++iter;
        }
        return res;
    }
};