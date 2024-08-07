/*
 * @lc app=leetcode.cn id=55 lang=cpp
 *
 * [55] 跳跃游戏
 *
 * https://leetcode.cn/problems/jump-game/description/
 *
 * algorithms
 * Medium (43.69%)
 * Likes:    2239
 * Dislikes: 0
 * Total Accepted:    670.4K
 * Total Submissions: 1.5M
 * Testcase Example:  '[2,3,1,1,4]'
 *
 * 给定一个非负整数数组 nums ，你最初位于数组的 第一个下标 。
 * 
 * 数组中的每个元素代表你在该位置可以跳跃的最大长度。
 * 
 * 判断你是否能够到达最后一个下标。
 * 
 * 
 * 
 * 示例 1：
 * 
 * 
 * 输入：nums = [2,3,1,1,4]
 * 输出：true
 * 解释：可以先跳 1 步，从下标 0 到达下标 1, 然后再从下标 1 跳 3 步到达最后一个下标。
 * 
 * 
 * 示例 2：
 * 
 * 
 * 输入：nums = [3,2,1,0,4]
 * 输出：false
 * 解释：无论怎样，总会到达下标为 3 的位置。但该下标的最大跳跃长度是 0 ， 所以永远不可能到达最后一个下标。
 * 
 * 
 * 
 * 
 * 提示：
 * 
 * 
 * 1 
 * 0 
 * 
 * 
 */
#include <vector>
#include <iostream>

using namespace std;

// @lc code=start
class Solution {
public:

    bool canJump(vector<int>& nums) {
        int len = nums.size(), max = 0;
        for(int i = 0; i < len; ++i) {
            if(i <= max) {
                max = max > i + nums[i] ? max : i + nums[i];
                if(max + 1 >= len) {
                    return true;
                }
            }
        }
        return false;
    }
};
// @lc code=end
int main() {
    vector<int> nums = {5,9,3,2,1,0,2,3,3,1,0,0};
    Solution s;
    bool res = s.canJump(nums);
    std::cout << res << std::endl;
    return 0;
}
