/*
 * @lc app=leetcode.cn id=16 lang=cpp
 *
 * [16] 最接近的三数之和
 *
 * https://leetcode-cn.com/problems/3sum-closest/description/
 *
 * algorithms
 * Medium (45.69%)
 * Likes:    1132
 * Dislikes: 0
 * Total Accepted:    345.5K
 * Total Submissions: 756.6K
 * Testcase Example:  '[-1,2,1,-4]\n1'
 *
 * 给你一个长度为 n 的整数数组 nums 和 一个目标值 target。请你从 nums 中选出三个整数，使它们的和与 target 最接近。
 * 
 * 返回这三个数的和。
 * 
 * 假定每组输入只存在恰好一个解。
 * 
 * 
 * 
 * 示例 1：
 * 
 * 
 * 输入：nums = [-1,2,1,-4], target = 1
 * 输出：2
 * 解释：与 target 最接近的和是 2 (-1 + 2 + 1 = 2) 。
 * 
 * 
 * 示例 2：
 * 
 * 
 * 输入：nums = [0,0,0], target = 1
 * 输出：0
 * 
 * 
 * 
 * 
 * 提示：
 * 
 * 
 * 3 <= nums.length <= 1000
 * -1000 <= nums[i] <= 1000
 * -10^4 <= target <= 10^4
 * 
 * 
 */
#include <vector>
#include <algorithm>
#include <climits>
// @lc code=start
class Solution {
public:
    int threeSumClosest(std::vector<int>& nums, int target) {
        sort(nums.begin(), nums.end());
        return nSumCloset(nums, 3, 0, target);
    }

    int nSumCloset(std::vector<int>& nums, int n, int start, int target) {
        int length = nums.size(), low = start;
        int gap = INT_MAX, res = 0, tmpSum = 0;
        if(n == 2) {
            int height = length - 1;
            while(low < height) {
                tmpSum = nums[low] + nums[height];
                if(abs(gap) > abs(target - tmpSum)) {
                    gap = target - tmpSum;
                }
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
                    return target;
                }
            }
            return target - gap;
        }
        while(low < length - n + 1) {
            tmpSum = nums[low] + nSumCloset(nums, n - 1, low + 1, target - nums[low]);
            if(abs(gap) > abs(target - tmpSum)) {
                gap = target - tmpSum;
            }
            while(low < length - 1 && nums[low] == nums[low + 1]) {
                ++low;
            }
            ++low;
        }
        return target - gap;
    }
};
// @lc code=end

