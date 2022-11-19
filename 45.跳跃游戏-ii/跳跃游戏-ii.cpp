/*
 * @lc app=leetcode.cn id=45 lang=cpp
 *
 * [45] 跳跃游戏 II
 *
 * https://leetcode-cn.com/problems/jump-game-ii/description/
 *
 * algorithms
 * Medium (44.44%)
 * Likes:    1857
 * Dislikes: 0
 * Total Accepted:    418.7K
 * Total Submissions: 926.9K
 * Testcase Example:  '[2,3,1,1,4]'
 *
 * 给你一个非负整数数组 nums ，你最初位于数组的第一个位置。
 * 
 * 数组中的每个元素代表你在该位置可以跳跃的最大长度。
 * 
 * 你的目标是使用最少的跳跃次数到达数组的最后一个位置。
 * 
 * 假设你总是可以到达数组的最后一个位置。
 * 
 * 
 * 
 * 示例 1:
 * 
 * 
 * 输入: nums = [2,3,1,1,4]
 * 输出: 2
 * 解释: 跳到最后一个位置的最小跳跃数是 2。
 * 从下标为 0 跳到下标为 1 的位置，跳 1 步，然后跳 3 步到达数组的最后一个位置。
 * 
 * 
 * 示例 2:
 * 
 * 
 * 输入: nums = [2,3,0,1,4]
 * 输出: 2
 * 
 * 
 * 
 * 
 * 提示:
 * 
 * 
 * 1 
 * 0 
 * 
 * 
 */
#include <vector>
#include <iostream>

// @lc code=start
class Solution {
public:
    int jump(std::vector<int>& nums) {
        int step = 0, currPos = 0, remain = nums.size() - 1;
        while(remain > 0) {
            int nextMax = nums[currPos];
            if(nextMax < remain) {
                for(int i = nums[currPos]; i > 0; --i) {
                    if(i + nums[currPos + i] > nextMax + nums[currPos + nextMax]) {
                        nextMax = i;
                    }
                }
            }
            currPos += nextMax;
            remain -= nextMax;
            ++step;
        }
        return step;
    }
};
// @lc code=end

int main() {
    Solution solution;
    std::vector<int> nums = {5,6,4,4,6,9,4,4,7,4,4,8,2,6,8,1,5,9,6,5,2,7,9,7,9,6,9,4,1,6,8,8,4,4,2,0,3,8,5};
    // std::vector<int> nums = {2, 3, 1, 1, 4};
    int res = solution.jump(nums);
    std::cout << res << std::endl;
    return 0;
}