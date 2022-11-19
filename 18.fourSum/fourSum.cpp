/*
 * @lc app=leetcode.cn id=18 lang=cpp
 *
 * [18] 四数之和
 *
 * https://leetcode-cn.com/problems/4sum/description/
 *
 * algorithms
 * Medium (39.31%)
 * Likes:    1225
 * Dislikes: 0
 * Total Accepted:    310.4K
 * Total Submissions: 789.6K
 * Testcase Example:  '[1,0,-1,0,-2,2]\n0'
 *
 * 给你一个由 n 个整数组成的数组 nums ，和一个目标值 target 。请你找出并返回满足下述全部条件且不重复的四元组 [nums[a],
 * nums[b], nums[c], nums[d]] （若两个四元组元素一一对应，则认为两个四元组重复）：
 * 
 * 
 * 0 <= a, b, c, d < n
 * a、b、c 和 d 互不相同
 * nums[a] + nums[b] + nums[c] + nums[d] == target
 * 
 * 
 * 你可以按 任意顺序 返回答案 。
 * 
 * 
 * 
 * 示例 1：
 * 
 * 
 * 输入：nums = [1,0,-1,0,-2,2], target = 0
 * 输出：[[-2,-1,1,2],[-2,0,0,2],[-1,0,0,1]]
 * 
 * 
 * 示例 2：
 * 
 * 
 * 输入：nums = [2,2,2,2,2], target = 8
 * 输出：[[2,2,2,2]]
 * 
 * 
 * 
 * 
 * 提示：
 * 
 * 
 * 1 <= nums.length <= 200
 * -10^9 <= nums[i] <= 10^9
 * -10^9 <= target <= 10^9
 * 
 * 
 */
#include <vector>
#include <algorithm>
// @lc code=start
class Solution {
public:
    std::vector<std::vector<int>> fourSum(std::vector<int>& nums, int target) {
        sort(nums.begin(), nums.end());
        return nSumTarget(nums, 4, 0, target);
    }

    std::vector<std::vector<int>> nSumTarget(std::vector<int>& nums, int n, int start, int target) {
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
            for(std::vector<int> item : subRes) {
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

