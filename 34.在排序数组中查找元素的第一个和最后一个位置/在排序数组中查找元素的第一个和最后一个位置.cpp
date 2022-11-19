/*
 * @lc app=leetcode.cn id=34 lang=cpp
 *
 * [34] 在排序数组中查找元素的第一个和最后一个位置
 *
 * https://leetcode-cn.com/problems/find-first-and-last-position-of-element-in-sorted-array/description/
 *
 * algorithms
 * Medium (42.21%)
 * Likes:    1959
 * Dislikes: 0
 * Total Accepted:    665.2K
 * Total Submissions: 1.6M
 * Testcase Example:  '[5,7,7,8,8,10]\n8'
 *
 * 给你一个按照非递减顺序排列的整数数组 nums，和一个目标值 target。请你找出给定目标值在数组中的开始位置和结束位置。
 * 
 * 如果数组中不存在目标值 target，返回 [-1, -1]。
 * 
 * 你必须设计并实现时间复杂度为 O(log n) 的算法解决此问题。
 * 
 * 
 * 
 * 示例 1：
 * 
 * 
 * 输入：nums = [5,7,7,8,8,10], target = 8
 * 输出：[3,4]
 * 
 * 示例 2：
 * 
 * 
 * 输入：nums = [5,7,7,8,8,10], target = 6
 * 输出：[-1,-1]
 * 
 * 示例 3：
 * 
 * 
 * 输入：nums = [], target = 0
 * 输出：[-1,-1]
 * 
 * 
 * 
 * 提示：
 * 
 * 
 * 0 <= nums.length <= 10^5
 * -10^9 <= nums[i] <= 10^9
 * nums 是一个非递减数组
 * -10^9 <= target <= 10^9
 * 
 * 
 */
#include <iostream>
#include <vector>
// @lc code=start
class Solution {
public:
    std::vector<int> searchRange(std::vector<int>& nums, int target) {
        std::vector<int> res = {-1, -1};
        int left = 0, right = nums.size() - 1, middle;
        if(nums.size() < 1 || target < nums[0] || target > nums[right]) {
            return res;
        }
        while(left <= right) {
            middle = (left + right) / 2;
            if(target == nums[middle]) {
                res = {middle, middle};
                while(left <= res[0]  - 1) {
                    middle = (left + res[0] - 1) / 2;
                    if(nums[middle] < target) {
                        left = middle + 1;
                    } else {
                        res[0] = middle;
                    }
                }
                while(right >= res[1] + 1) {
                    middle = (res[1] + 1 + right) / 2;
                    if(nums[middle] > target) {
                        right = middle - 1;
                    } else {
                        res[1] = middle;
                    }
                }
                break;
            }
            if(target < nums[middle]) {
                right = middle - 1;
            } else {
                left = middle + 1;
            }
        }
        return res;
    }
};
// @lc code=end

void main() {
    Solution s;
    std::vector<int> nums = {5, 7, 7, 8, 8, 10};
    int target = 8;
    std::vector<int> res = s.searchRange(nums, target);
    std::cout << res[0] << " " << res[1] << std::endl;
    return;
}