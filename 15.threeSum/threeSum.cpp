/*
 * @lc app=leetcode.cn id=15 lang=cpp
 *
 * [15] 三数之和
 *
 * https://leetcode-cn.com/problems/3sum/description/
 *
 * algorithms
 * Medium (35.25%)
 * Likes:    4723
 * Dislikes: 0
 * Total Accepted:    946.4K
 * Total Submissions: 2.7M
 * Testcase Example:  '[-1,0,1,2,-1,-4]'
 *
 * 给你一个包含 n 个整数的数组 nums，判断 nums 中是否存在三个元素 a，b，c ，使得 a + b + c = 0 ？请你找出所有和为 0
 * 且不重复的三元组。
 * 
 * 注意：答案中不可以包含重复的三元组。
 * 
 * 
 * 
 * 示例 1：
 * 
 * 
 * 输入：nums = [-1,0,1,2,-1,-4]
 * 输出：[[-1,-1,2],[-1,0,1]]
 * 
 * 
 * 示例 2：
 * 
 * 
 * 输入：nums = []
 * 输出：[]
 * 
 * 
 * 示例 3：
 * 
 * 
 * 输入：nums = [0]
 * 输出：[]
 * 
 * 
 * 
 * 
 * 提示：
 * 
 * 
 * 0 
 * -10^5 
 * 
 * 
 */
#include <vector>
#include <algorithm>
// @lc code=start
class Solution {
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
        while(low < length - n + 1) {
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
// @lc code=end

